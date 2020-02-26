module main_controller(
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0] funct7,
    output reg_w_en,        //0:disable 1:enable
    output dmem_w_en,       //0:disable 1:enable
    output store_load_sel,  //0:store   1:load  (dmem_rw_addr)
    output [1:0] reg_w_sel, //00:dmem  01:alu   10:pc + 4   11:csr_reg
    output rs2_imm_sel,     //0:rs2     1:imm   (alu_data_y)
    output [1:0] imm_sel,   //00:U     01:I     10:J        11:zimm
    output rs1_pc_sel,      //0:rs1     1:pc    (alu_data_x)
    output jump_en,         //0:nojump  1:jump enable
    output csr_w_en,        //0:disable 1:enable
    output ret,             //0:stay    1:return
    output wfi);            //0:though  1:wait
    
    assign {reg_w_en, dmem_w_en, store_load_sel, reg_w_sel, rs2_imm_sel, imm_sel, rs1_pc_sel, jump_en, csr_w_en, ret, wfi} = control(opcode, funct3, funct7);

    function [12:0] control(input [6:0] opcode, input [2:0] funct3, input [6:0] funct7);
        begin
            case(opcode)
                7'b0000011: control = 13'b101_00_0_01_00000;  //store
                7'b0100011: control = 13'b010_00_0_01_00000;  //load
                7'b0110011: control = 13'b100_01_0_01_00000;  //reg-reg cal
                7'b0010011: control = 13'b100_01_1_01_00000;  //imm-reg cal
                7'b1100011: control = 13'b000_00_0_01_00000;  //branch
                7'b0110111: control = 13'b100_01_1_00_00000;  //lui
                7'b0010111: control = 13'b100_01_1_00_10000;  //auipc
                7'b1101111: control = 13'b100_10_1_10_11000;  //jal
                7'b1100111: control = 13'b100_10_1_01_01000;  //jalr
                7'b1110011: begin
                    case(funct3)
                        3'b000:  begin
                            case(funct7)
                            7'b0011000: control = 13'b000_00_0_00_00010; //mret
                            7'b0001000: control = 13'b000_00_0_00_00001;
                            endcase
                        end
                        default: control = 13'b100_11_0_11_00100;  //csr
                    endcase
                end  //csr
            endcase
        end
    endfunction
endmodule
