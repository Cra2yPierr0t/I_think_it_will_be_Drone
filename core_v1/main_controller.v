module main_controller(
    input [6:0] opcode,
    input [4:0] funct3,
    output reg_w_en,        //0:disable 1:enable
    output dmem_w_en,       //0:disable 1:enable
    output store_load_sel,  //0:store   1:load
    output dmem_alu_sel     //0:dmem    1:alu
    output reg_imm_sel);    //0:reg     1:imm
    
    assign {reg_w_en, dmem_w_en, store_load_sel, dmem_alu_sel, reg_imm_sel} = control(opcode);

    function [4:0] control(input [6:0] opcode);
        begin
            case(opcode)
                7'b0000011: control = 5'b10100;  //store
                7'b0100011: control = 5'b01000;  //load
                7'b0110011: control = 5'b10010;  //reg-reg cal
                7'b0010011: control = 5'b10011;  //imm-reg cal
            endcase
        end
    endfunction
endmodule
