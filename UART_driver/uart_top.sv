module uart_top(
        input   logic clk,
        input   logic RX,
        output  logic TX,
        input   logic [7:0] wdata,
        input   logic run_req,
        output  logic end_flag = 1'b0
    );

    logic clk115200 = 1'b0;
    logic [15:0]    clk_cnt = 16'h0000;   

    always_ff @(posedge clk) begin
        if(clk_cnt == 16'd51) begin
            clk115200 <= ~clk115200;
            clk_cnt <= 16'h0000;
        end else begin
            clk_cnt <= clk_cnt + 16'h0001;
        end
    end
    
    uart_core uart_core(
            .clk        (clk115200  ),
            .RX         (RX         ),
            .TX         (TX         ),
            .wdata      (wdata      ),
            .run_req    (run_req    ),
            .end_flag   (end_flag   )
        );

endmodule
