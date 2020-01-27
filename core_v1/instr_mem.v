module instr_mem(
    input [31:0] addr,
    output [31:0] instr);

    reg [7:0] mem[0:255];

    assign instr = {mem[addr + 3], mem[addr + 2], mem[addr + 1], mem[addr]};

    initial begin
        {mem[3], mem[2], mem[1], mem[0]} = 31'h00000000;
    end
endmodule
