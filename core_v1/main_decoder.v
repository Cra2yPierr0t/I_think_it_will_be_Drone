module main_decoder(
    input [31:0] instr,
    output [6:0] opcode,
    output [4:0] rd,
    output [4:0] rs1,
    output [4:0] rs2,
    output [2:0] funct3,
    output [6:0] funct7,
    output [11:0] imm_I,
    output [11:0] imm_S,
    output [11:0] imm_B,
    output [19:0] imm_U,
    output [19:0] imm_J);

    assign opcode = instr[6:0];
    assign rd = instr[11:7];
    assign rs1 = instr[19:15];
    assign rs2 = instr[24:20];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];
    assign imm_I = instr[31:20];
    assign imm_S = {instr[31:25], instr[11:7]};
    assign imm_B = {instr[31], instr[7], instr[30:25], instr[11:8]};
    assign imm_U = instr[31:12];
    assign imm_J = {instr[31], instr[19:12], instr[20], instr[30:21]};

endmodule
