module main_controller(
    input [6:0] opcode,
    output reg_w_en,        //0:disable 1:enable
    output dmem_w_en,       //0:disable 1:enable
    output store_load_sel,  //0:store   1:load
    output [1:0] reg_w_sel, //00:dmem  01:alu   10:pc + 4
    output reg_imm_sel,     //0:reg     1:imm
    output [1:0] imm_sel,   //00:U     01:I     10:J
    output rs1_pc_sel,      //0:rs1     1:pc
    output jump_en);        //0:nojump  1:jump enable
    
    assign {reg_w_en, dmem_w_en, store_load_sel, reg_w_sel, reg_imm_sel, imm_sel, rs1_pc_sel, jump_en} = control(opcode);

    function [9:0] control(input [6:0] opcode);
        begin
            case(opcode)
                7'b0000011: control = 10'b101_00_0_01_00;  //store
                7'b0100011: control = 10'b010_00_0_01_00;  //load
                7'b0110011: control = 10'b100_01_0_01_00;  //reg-reg cal
                7'b0010011: control = 10'b100_01_1_01_00;  //imm-reg cal
                7'b1100011: control = 10'b000_00_0_01_00;  //branch
                7'b0110111: control = 10'b100_01_1_00_00;  //lui
                7'b0010111: control = 10'b100_01_1_00_10;  //auipc
                7'b1101111: control = 10'b100_10_1_10_11;  //jal
                7'b1100111: control = 10'b100_10_1_01_11;  //jalr
            endcase
        end
    endfunction
endmodule
