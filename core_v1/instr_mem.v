module instr_mem(
    input [31:0] addr,
    output [31:0] instr);

    reg [7:0] mem[0:255];

    assign instr = {mem[addr + 3], mem[addr + 2], mem[addr + 1], mem[addr]};

    initial begin
    /*
        {mem[3], mem[2], mem[1], mem[0]} = 32'h00000293;
        {mem[7], mem[6], mem[5], mem[4]} = 32'h00000313;
        {mem[11], mem[10], mem[9], mem[8]} = 32'h00a00393;
        {mem[15], mem[14], mem[13], mem[12]} = 32'h00128293;
        {mem[19], mem[18], mem[17], mem[16]} = 32'h00530333;
        {mem[23], mem[22], mem[21], mem[20]} = 32'h00728463;
        {mem[27], mem[26], mem[25], mem[24]} = 32'hff1ff06f;
        {mem[31], mem[30], mem[29], mem[28]} = 32'h00030533;
        {mem[35], mem[34], mem[33], mem[32]} = 32'h00008067;
    */
        {mem[3], mem[2], mem[1], mem[0]} = 32'b000000101010_00000_000_00001_0010011;
        {mem[7], mem[6], mem[5], mem[4]} = 32'b0000000_00001_00000_010_00001_0100011;
        {mem[11], mem[10], mem[9], mem[8]} = 32'b000000000001_00000_000_00010_0000011;
        {mem[15], mem[14], mem[13], mem[12]} = 32'h00030533;
        {mem[19], mem[18], mem[17], mem[16]} = 32'h00008067;
    end
endmodule
