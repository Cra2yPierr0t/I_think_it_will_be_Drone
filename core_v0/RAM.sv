module RAM(
    input [31:0] instr_addr;
    output [31:0] instr_data;
    input [31:0] mem_r_addr;
    output [31:0] mem_r_out;
    input [31:0] mem_w_addr;
    input [31:0] mem_w_data;
    input mem_w_en;
    );

    reg [7:0] mem [16383:0];
    
endmodule
