module alu(
    input [3:0] alu_ctrl,
    input [31:0] data_x,
    input [31:0] data_y,
    output [31:0] alu_out);

parameter ALU_ADD = 4'b0000;
parameter ALU_SUB = 4'b0001;
parameter ALU_SLL = 4'b0010;
parameter ALU_SLT = 4'b0011;
parameter ALU_SLTU = 4'b0100;
parameter ALU_XOR = 4'b0101;
parameter ALU_SRL = 4'b0110;
parameter ALU_SRA = 4'b0111;
parameter ALU_OR = 4'b1000;
parameter ALU_AND = 4'b1001;

    assign alu_out = alu_exec(data_x, data_y, alu_ctrl);

    function [31:0] alu_exec(input [31:0] data_x, 
                             input [31:0] data_y, 
                             input [3:0] alu_ctrl);
        begin
            case(alu_ctrl)
                ALU_ADD : alu_exec = data_x + data_y;
                ALU_SUB : alu_exec = data_x - data_y;
                ALU_SLL : alu_exec = data_x << data_y
                ALU_SLT : alu_exec = $signed(data_x) < $signed(data_y);
                ALU_SLTU: alu_exec = data_x < data_y;
                ALU_XOR : alu_exec = data_x ^ data_y;
                ALU_SRL : alu_exec = data_x >> data_y;
                ALU_SRA : alu_exec = $signed(data_x) >>> $signed(data_y);
                ALU_OR  : alu_exec = data_x | data_y;
                ALU_AND : alu_exec = data_x & data_y;
            endcase
        end
    endfunction
endmodule
