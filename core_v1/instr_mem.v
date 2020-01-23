module instr_mem(
    input [31:0] addr,
    output [31:0] instr);

    reg [31:0] mem[0:255];

    assign instr = mem[addr];

    initial begin
        mem[0] = 31'h00000000;
    end
endmodule
