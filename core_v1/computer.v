module computer(input clock);
    wire [31:0] pc;
    wire [31:0] instr;
    
    wire [31:0] dmem_rw_addr;
    wire [31:0] dmem_w_data;
    wire dmem_w_en;
    wire [2:0] funct3;
    wire [31:0] dmem_r_data;
    wire [31:0] rs2_data;

    instr_mem instr_mem(.addr(pc),
                        .instr(instr));

    cpu cpu(.pc(pc),
            .instr(instr),
            .dmem_rw_addr(dmem_rw_addr),
            .rs2_data(rs2_data),
            .dmem_w_en(dmem_w_en),
            .funct3(funct3),
            .dmem_r_data(dmem_r_data),
            .clock(clock));

    data_mem data_mem(.rw_addr(dmem_rw_addr),
                      .w_data(rs2_data),
                      .w_en(dmem_w_en),
                      .funct3(funct3),
                      .r_data(dmem_r_data),
                      .clock(clock));
endmodule
