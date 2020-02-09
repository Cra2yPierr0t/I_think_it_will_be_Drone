module main_controller(
    input [6:0] opcode,
    input [2:0] funct3,
    output reg_w_en,        //0:disable 1:enable
    output dmem_w_en,       //0:disable 1:enable
    output store_load_sel,  //0:store   1:load  (dmem_rw_addr)
    output [1:0] reg_w_sel, //00:dmem  01:alu   10:pc + 4   11:csr_reg
    output rs2_imm_sel,     //0:rs2     1:imm   (alu_data_y)
    output [1:0] imm_sel,   //00:U     01:I     10:J        11:zimm
    output rs1_pc_sel,      //0:rs1     1:pc    (alu_data_x)
    output jump_en,         //0:nojump  1:jump enable
    output csr_w_en,        //0:disable 1:enable
    output ret);            //0:stay    1:return
    
    assign {reg_w_en, dmem_w_en, store_load_sel, reg_w_sel, rs2_imm_sel, imm_sel, rs1_pc_sel, jump_en, csr_w_en, ret} = control(opcode, funct3);

    function [11:0] control(input [6:0] opcode, input [2:0] funct3);
        begin
            case(opcode)
                7'b0000011: control = 12'b101_00_0_01_0000;  //store
                7'b0100011: control = 12'b010_00_0_01_0000;  //load
                7'b0110011: control = 12'b100_01_0_01_0000;  //reg-reg cal
                7'b0010011: control = 12'b100_01_1_01_0000;  //imm-reg cal
                7'b1100011: control = 12'b000_00_0_01_0000;  //branch
                7'b0110111: control = 12'b100_01_1_00_0000;  //lui
                7'b0010111: control = 12'b100_01_1_00_1000;  //auipc
                7'b1101111: control = 12'b100_10_1_10_1100;  //jal
                7'b1100111: control = 12'b100_10_1_01_1100;  //jalr
                7'b1110011: begin
                    case(funct3)
                        3'b000:  control = 12'b000_00_0_00_0001;
                        default: control = 12'b100_11_0_11_0010;  //csr
                    endcase
                end  //csr
            endcase
        end
    endfunction
endmodule
