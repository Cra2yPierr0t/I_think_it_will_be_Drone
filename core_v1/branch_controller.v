module branch_controller(
    input [2:0] funct3,
    input [31:0] alu_out,
    output branch_ctrl);

parameter BEQ = 3'b000;
parameter BNE = 3'b001;
parameter BLT = 3'b100;
parameter BGE = 3'b101;
parameter BLTU = 3'b110;
parameter BGEU = 3'b111;

    assign branch_ctrl = branch_control(funct3, alu_out);

    function branch_control(input [2:0] funct3, input [31:0] alu_out);
        begin
            case(funct3)
                BEQ: branch_control = ~|alu_out;
                BNE: branch_control = ~&alu_out;
                BLT: branch_control = alu_out[0];
                BGE: branch_control = ~alu_out[0];
                BLTU: branch_control = alu_out[0];
                BGEU: branch_control = ~alu_out[0];
            endcase
        end
    endfunction
endmodule
