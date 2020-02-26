//clock must be 50MHz
// baud rate 115200bps, stop bit 1bit, data 8bit, no parity, no flow control

module UART(
    input wire clk,
    input wire tx_begin_flag,
    input wire rx,
    input wire [7:0] tx_data,
    input wire [31:0] access_addr,
    input wire reg_w_en,
    output wire tx,
    output wire[7:0] rx_data,
    output wire tx_busy_flag,
    output reg int_req = 1'b0
);

    reg state = 1'b0;

    always @(negedge clk) begin
        if(state == 1'b0) begin //データ待機中
            int_req <= 1'b0;
            if(receive_flag == 1'b1) begin
                state <= 1'b1;
            end else begin
                state <= state;
            end
        end else if(state == 1'b1) begin //データが来たことをCPUに伝える
            int_req <= 1'b1;
            if(access_addr == 32'h0000_040c && reg_w_en == 1'b1) begin
                state <= 1'b0;
            end else begin
                state <= state;
            end
        end
    end

    tx tx1(clk, 1'b1, tx_begin_flag, tx_data, tx, tx_busy_flag);
    rx rx1(clk, 1'b1, rx, rx_data, receive_flag);
    
endmodule
