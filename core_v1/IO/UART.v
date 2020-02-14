// clock must be 50MHz
// baud rate 115200bps, stop bit 1bit, data 8bit, no parity, no flow control

module UART(
    input wire clk,
    input wire rx,
    input wire tx_begin_flag,
    input [31:0] access_addr,
    output wire tx,
    output [7:0] tx_data,
    output [7:0] rx_data,
    output wire tx_busy_flag
    output int_req
);

    reg state = 0;
    wire end_flag;

    always @(posedge clk) begin
        if(state == 0) begin
            int_req <= 1'b0;
            if(end_flag == 1'b1) begin
                state <= 1'b1;
            end else begin
                state <= state;
            end
        end else if(state == 1'b1) begin
            int_req <= 1'b1;
            if(access_addr == 32'h0000_040c) begin
                state <= 1'b0;
            end else begin
                state <= state;
            end
        end
    end

    tx tx1(clk, tx_begin_flag, tx_data, tx, tx_busy_flag);
    rx rx1(clk, rx, rx_data, end_flag);
    
endmodule
