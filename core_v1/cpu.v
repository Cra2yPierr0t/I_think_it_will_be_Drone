//一旦cpu内にpcとdmem, instr_memを置いて, rv32i実装終わったら外に出す
module cpu(
    input clock
);

    reg [31:0] pc = 0;
    wire [31:0] instr;

    wire [31:0] dmem_rw_addr;
    wire [31:0] dmem_r_data;
    wire dmem_w_en;          //0:disable 1:enable
    wire [31:0] load_addr;
    wire [31:0] store_addr;

    wire store_load_sel;    //0:store 1:load
    
    wire [4:0] rd_addr;
    wire [4:0] rs1_addr;
    wire [4:0] rs2_addr;
    wire [31:0] rs1_data;
    wire [31:0] rs2_data;
    wire reg_w_en;          //0:disable 1:enable
    wire [31:0] reg_w_data;
    wire dmem_alu_sel;      //0:dmem 1:alu

    wire [11:0] imm_I;
    wire [5:0] offset_s;
    wire [2:0] funct3;
    wire [6:0] funct7;

    wire [3:0] alu_ctrl;
    wire [31:0] alu_out;
    wire [31:0] alu_data_y;
    wire [31:0] alu_data_x;
    wire reg_imm_sel;   //0:reg 1:imm
    wire [31:0] imm_I_data;

    wire [11:0] imm_B;
    wire branch_ctrl; //0:notbranch 1:branch

    wire [19:0] imm_U;
    wire [31:0] imm_U_data;
    wire imm_U_I_sel;   //0:U   1:I
    wire rs1_pc_sel;    //0:rs1 1:pc

    instr_mem instr_mem(.addr(pc), .instr(instr));
    main_decoder main_dec(.instr(instr), 
                          .rd(rd_addr), 
                          .rs1(rs1_addr),
                          .rs2(rs2_addr),
                          .funct3(funct3),
                          .funct7(funct7),
                          .imm_I(imm_I),
                          .imm_S(offset_s),
                          .imm_B(imm_B)
                          .imm_U(imm_U));
    
    alu_decoder alu_dec(.opcode(opcode),
                        .funct3(funct3),
                        .funct7(funct7),
                        .alu_ctrl(alu_ctrl));

    main_controller main_controller(.opcode(opcode),
                                    .funct3(funct3),
                                    .reg_w_en(reg_w_en),
                                    .dmem_w_en(d_mem_w_en),
                                    .store_load_sel(store_load_sel),
                                    .dmem_alu_sel(dmem_alu_sel),
                                    .reg_imm_sel(reg_imm_sel),
                                    .imm_U_I_sel(imm_U_I_sel),
                                    .rs1_pc_sel(rs1_pc_sel));

    assign imm_I_data = (func3 == 3'b001 || func3 == 3'b101) ? {27'h0, imm_I[4:0]}
                                                           : imm_I[11] ? {20'hfffff, imm_I} 
                                                                       : {20'h00000, imm_I};   //Immidiateの符号拡張
    assign imm_U_data = {imm_U, 12'h000};
    assign imm_data = imm_U_I_sel ? imm_I_data : imm_U_data;

    assign alu_data_x = rs1_pc_sel ? pc : rs1_data;
    assign alu_data_y = reg_imm_sel ? imm_data : rs2_data; 

    alu alu(.alu_ctrl(alu_ctrl),
            .data_x(alu_data_x),
            .data_y(alu_data_y),
            .alu_out(alu_out));
    
    assign reg_w_data = dmem_alu_sel ? alu_out : dmem_r_data;
    regfile regfile(.rd_addr(rd_addr),
                    .rs1_addr(rs1_addr),
                    .rs2_addr(rs2_addr),
                    .w_data(reg_w_data),
                    .w_en(reg_w_en),
                    .rs1_data(rs1_data),
                    .rs2_data(rs2_data),
                    .clock(clock));

    //オフセットの符号拡張とアドレス作成
    assign load_addr = rs1_data + {imm_I[11] ? 20'hfffff : 20'h00000, imm_I};
    assign store_addr = rs1_data + {offset_s[11] ? 20'hfffff : 20'h00000, offset_s};
    
    assign dmem_rw_addr = store_load_sel ? load_addr : store_addr;
    data_mem data_mem(.rw_addr(dmem_rw_addr),
                      .w_data(rs2_data),
                      .w_en(dmem_w_en),
                      .funct3(funct3),
                      .r_data(dmem_r_data),
                      .clock(clock));

    branch_controller branch_controller(.funct3(funct3),
                                        .alu_out(alu_out),
                                        .branch_ctrl(branch_ctrl));

    always @(posedge clock) begin
        if(branch_ctrl) begin
            pc = pc + {imm_B[11] ? 19'b11111_11111_11111_1111 : 19'b00000_00000_00000_0000, imm_B, 0};
        end else begin
            pc = pc + 4;
        end
    end
endmodule
