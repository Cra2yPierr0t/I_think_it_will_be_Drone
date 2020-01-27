module alu_decoder(
    input [6:0] opcode,
    input [2:0] funct3,
    input [6:0] funct7,
    output [3:0] alu_ctrl);

parameter I_INSTR = 7'b0010011;
parameter R_INSTR = 7'b0110011;
parameter B_INSTR = 7'b1100011;

//format
parameter ADD_SUB = 3'b000;
parameter SLL     = 3'b001;
parameter SLT     = 3'b010;
parameter SLTU    = 3'b011;
parameter XOR     = 3'b100;
parameter SRL_SRA = 3'b101;
parameter OR      = 3'b110;
parameter AND     = 3'b111;
//          |
//          v
//alu_ctrl table
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

parameter BEQ = 3'b000;
parameter BNE = 3'b001;
parameter BLT = 3'b100;
parameter BGE = 3'b101;
parameter BLTU = 3'b110;
parameter BGEU = 3'b111;
//brach format
//          |
//          v
//alu_ctrl table
parameter ALU_BEQ = 4'b0000;
parameter ALU_BNE = 4'b0000;
parameter ALU_BLT = 4'b0011;
parameter ALU_BGE = 4'b0011;
parameter ALU_BLTU = 4'b0100;
parameter ALU_BGEU = 4'b0100;


    assign alu_ctrl = alu_decode(opcode, funct3, funct7);

    function [3:0] alu_decode(input [6:0] opcode,
                                  input [2:0] funct3,
                                  input [6:0] funct7);
        begin
            case(opcode)
                I_INSTR: begin
                    case(funct3)
                        ADD_SUB: alu_decode = ALU_ADD;
                        SLT : alu_decode = ALU_SLT;
                        SLTU: alu_decode = ALU_SLTU;
                        XOR : alu_decode = ALU_XOR;
                        OR  : alu_decode = ALU_OR;
                        AND : alu_decode = ALU_AND;
                        SLL : alu_decode = ALU_SLL;
                        SRL_SRA : begin
                            case(funct7)
                                7'b0000000: alu_decode = ALU_SRL;
                                7'b0100000: alu_deocde = ALU_SRA;
                            endcase
                        end
                    endcase
                end
                R_INSTR: begin
                    case(funct3)
                        ADD_SUB: begin
                            case(funct7)
                                7'b0000000: alu_decode = ALU_ADD;
                                7'b0100000: alu_decode = ALU_SUB;
                            endcase
                        end
                        SLL: alu_decode = ALU_SLL;
                        SLT: alu_decode = ALU_SLT;
                        SLTU: alu_decode = ALU_SLTU;
                        XOR: alu_decode = ALU_XOR;
                        SRL_SRA: begin
                            case(funct7)
                                7'b0000000: alu_decode = ALU_SRL;
                                7'b0100000: alu_deocde = ALU_SRA;
                            endcase
                        end
                        OR: alu_decode = ALU_OR;
                        AND: alu_decode = ALU_AND;
                        end
                    endcase
                end
                B_INSTR: begin
                    case(funct3)
                        BEQ: alu_decode = ALU_BEQ;
                        BNE: alu_decode = ALU_BNE;
                        BLT: alu_decode = ALU_BLT;
                        BGE: alu_decode = ALU_BGE;
                        BLTU: alu_deocde = ALU_BLTU;
                        BGEU: alu_deocde = ALU_BGEU;
                    endcase
                end
            endcase
        end
    endfunction
endmodule
