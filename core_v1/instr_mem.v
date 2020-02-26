module instr_mem(
    input [31:0] addr,
    input clock,
    output [31:0] instr);

    instruction_memory instruction_memory(.address(addr >> 2),
                                          .clock(clock),
                                          .q(instr));
/*
    initial begin
//main
     	mem[0] = 32'h04100513;    //  	li	a0,65
     	mem[1] = 32'h020000ef;    //  	jal	ra,24 <putc>
     	mem[2] = 32'h04200513;    //  	li	a0,66
     	mem[3] = 32'h018000ef;    //  	jal	ra,24 <putc>
     	mem[4] = 32'h04300513;    //  	li	a0,67
     	mem[5] = 32'h010000ef;    //  	jal	ra,24 <putc>
     	mem[6] = 32'h020000ef;    //  	jal	ra,38 <getc>
     	mem[7] = 32'h008000ef;    //  	jal	ra,24 <putc>
     	mem[8] = 32'h0000006f;    //  	j	20 <main+0x20>
//putc
     	mem[9] = 32'h00100e13;    //  	li	t3,1
     	mem[10] = 32'h40802383;   //  	lw	t2,1032(zero) # 408 <getc+0x3d0>
     	mem[11] = 32'hfe7e0ee3;   //  	beq	t3,t2,28 <loop>
     	mem[12] = 32'h40a02223;   //  	sw	a0,1028(zero) # 404 <getc+0x3cc>
     	mem[13] = 32'h00008067;   //  	ret
//getc
     	mem[14] = 32'h0fc02e83;   //  	lw	t4,252(zero) # fc <getc+0xc4>
     	mem[15] = 32'hfe0e8ee3;   //  	beqz	t4,38 <getc>
     	mem[16] = 32'hffce8e93;   //  	addi	t4,t4,-4
     	mem[17] = 32'h100ea503;   //  	lw	a0,256(t4)
     	mem[18] = 32'h0fd02e23;   //  	sw	t4,252(zero) # fc <getc+0xc4>
     	mem[19] = 32'h00008067;   //  	ret

//interrupt handler
        mem[320] = 32'h40c02283;  //    lw	t0,1036(zero) # 0x40c
        mem[321] = 32'h0fc02303;  //    lw	t1,252(zero) # 0xfc
        mem[322] = 32'h10532023;  //    sw	t0,256(t1)
        mem[323] = 32'h00430313;  //    addi	t1,t1,4
        mem[324] = 32'h0e602e23;  //    sw  t1,252(zero) # 0xfc
        mem[325] = 32'h30200073;  //    mret
    end
*/
endmodule
