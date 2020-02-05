module data_mem(
    input [31:0] rw_addr,
    input [31:0] w_data,
    input w_en,
    input [2:0] funct3,
    output [31:0] r_data,
    input clock);

//funct3
//lb  -> 000
//lbu -> 100
//lh  -> 001
//lhu -> 101
//lw  -> 010
//sb  -> 000
//sh  -> 001
//sw  -> 010
    wire [1:0] size_sel;    //データサイズ選択 00:byte 01:half 10:word
    wire sign_sel;          //符号選択 0:singed 1:unsigned
    assign size_sel = funct3[1:0];  //funct3を分割
    assign sign_sel = funct3[2];
    
    wire [31:0] q;

    assign r_data = (size_sel == 2'b00) ? sign_sel ? {24'h000000, q[31:24]}
                                                   : q[31] ? {24'hffffff, q[31:24]}
                                                           : {24'h000000, q[31:24]}
                  : (size_sel == 2'b01) ? sign_sel ? {16'h000000, q[23:16], q[31:24]}
                                                   : q[23] ? {16'hffff, q[23:16], q[15:0]}
                                                           : {16'h0000, q[23:16], q[15:0]}
                  : (size_sel == 2'b10) ? {q[7:0], q[15:8], q[23:16], q[31:24]}
                                        : {q[7:0], q[15:8], q[23:16], q[31:24]};

    wire [31:0] data;
    assign data = (size_sel == 2'b00) ? {w_data[7:0], q[23:0]}
                : (size_sel == 2'b01) ? {w_data[7:0], w_data[15:8], q[15:0]}
                : (size_sel == 2'b10) ? {w_data[7:0], w_data[15:8], w_data[23:16], w_data[31:24]}
                : {w_data[7:0], w_data[15:8], w_data[23:16], w_data[31:24]};

    data_memory ram(.address(rw_addr >> 2),
                    .clock(clock),
                    .data(data),
                    .wren(w_en),
                    .q(q));

endmodule
