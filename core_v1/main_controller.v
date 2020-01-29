module main_controller(
    input [6:0] opcode,
    input [4:0] funct3,
    output reg_w_en,        //0:disable 1:enable
    output dmem_w_en,       //0:disable 1:enable
    output store_load_sel,  //0:store   1:load
    output dmem_alu_sel,    //0:dmem    1:alu
    output reg_imm_sel,     //0:reg     1:imm
    output imm_U_I_sel      //0:U       1:I
    output rs1_pc_sel);     //0:rs1     1:pc
    
    assign {reg_w_en, dmem_w_en, store_load_sel, dmem_alu_sel, reg_imm_sel, imm_U_I_sel, rs1_pc_sel} = control(opcode);

    function [6:0] control(input [6:0] opcode);
        begin
            case(opcode)
                7'b0000011: control = 7'b1010010;  //store
                7'b0100011: control = 7'b0100010;  //load
                7'b0110011: control = 7'b1001010;  //reg-reg cal
                7'b0010011: control = 7'b1001110;  //imm-reg cal
                7'b1100011: control = 7'b0000010:  //branch
                7'b0110111: control = 7'b1001100:  //lui
                7'b0010111: control = 7'b1001101;  //auipc
            endcase
        end
    endfunction
endmodule
