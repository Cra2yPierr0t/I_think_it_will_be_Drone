module data_mem(
    input [31:0] rw_addr,
    input [31:0] w_data,
    input w_en,
    input [2:0] funct3,
    output [31:0] r_data,
    input clock);

    reg [7:0] mem[0:16384];

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

    assign r_data = (size_sel == 2'b00) ? sign_sel ? {8'h00, 8'h00, 8'h00, mem[rw_addr]}
                                                   : mem[rw_addr][7] ? {8'hff, 8'hff, 8'hff, mem[rw_addr]}
                                                                     : {8'h00, 8'h00, 8'h00, mem[rw_addr]}
                  : (size_sel == 2'b01) ? sign_sel ? {8'h00, 8'h00, mem[rw_addr + 1], mem[rw_addr]}
                                                   : mem[rw_addr + 1][7] ? {8'hff, 8'hff, mem[rw_addr + 1], mem[rw_addr]}
                                                                         : {8'h00, 8'h00, mem[rw_addr + 1], mem[rw_addr]}
                  : (size_sel == 2'b10) ? {mem[rw_addr + 3], mem[rw_addr + 2], mem[rw_addr + 1], mem[rw_addr]}
                                        : {32'hxxxxxxxx};

    always @(posedge clock) begin
        if(w_en) begin
            if(size_sel == 2'b00) begin
                mem[rw_addr] <= w_data[7:0];
            end else if(size_sel == 2'b01) begin
                {mem[rw_addr + 1], mem[rw_addr]} <= w_data[15:0];
            end else if(size_sel == 2'b10) begin
                {mem[rw_addr + 3], mem[rw_addr + 2], mem[rw_addr + 1], mem[rw_addr]} <= w_data;
            end else begin
                {mem[rw_addr + 3], mem[rw_addr + 2], mem[rw_addr + 1], mem[rw_addr]} <= w_data; //後で同期例外線伸ばす
            end
        end else begin
            mem[rw_addr] <= mem[rw_addr];
        end
    end

    initial begin
        mem[32'h000000fc] = 8'h00;
        mem[32'h000000fc + 1] = 8'h00;
        mem[32'h000000fc + 2] = 8'h00;
        mem[32'h000000fc + 3] = 8'h00;
    end
endmodule
