typedef struct {
    logic [31:0] pc;
    logic [31:0] rd_d;
    logic [31:0] memw_d;
} execute_elements;

typedef struct{
    logic [7:0] op;
    logic [4:0] rs1;
    logic [4:0] rs2;
    logic [4:0] rd;
    logic [2:0] funct3;
    logic [6:0] funct7;
    logic [31:0] imm;
} decode_elements;

typedef struct{
    logic [31:0] r1_d;
    logic [31:0] r2_d;
} regfile_r_elements;
