module instr_mem(
    input [31:0] addr,
	 input clock,
    output [31:0] instr);

	 wire [31:0] q;
	 
	 assign instr = q;
	 
    instruction_memory rom(.address(addr >> 2),
	                        .clock(clock),
									.q(q));
endmodule
