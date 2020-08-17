module esti_top(
        input   logic        clk,
        output  logic       SCL = 1,
        inout   SDA,
        input   logic        reset,
        output  logic [7:0]  led_out = 8'h00,
        input   logic   RX,
        output  logic   TX
    );

    logic   [63:0]  posi_out = 64'h0000000000000000;
    logic   [15:0]  acc;
    logic   [7:0]   received_data[7:0];
    logic           end_flag;

    esti_core esti_core(
            .posi_out   (posi_out   ),
            .acc_in     (acc        ),
            .clk        (end_flag   ),
            .reset      (~reset     )
        );

    i2c_driver_top i2c_driver_top(
            .clk            (clk    ),
            .SCL            (SCL    ),
            .SDA            (SDA    ),
            .end_flag       (end_flag),
            .received_data  (received_data)
        );

    logic   uart_end_flag;
    logic   [7:0]   uart_wdata;
    logic           uart_run_req;
    
    uart_convert(
            .uart_end_flag  (uart_end_flag  ),
            .uart_wdata     (uart_wdata     ),
            .uart_run_req   (uart_run_req   ),
            .posi_out       (posi_out       )
        );

    uart_core(
            .clk    (clk    ),
            .RX     (RX     ),
            .TX     (TX     ),
            .wdata  (uart_wdata ),
            .run_req    (uart_run_req   ),
            .end_flag   (uart_end_flag  )
        );

    always_ff @(posedge end_flag) begin
        if(({received_data[0], received_data[1]} > 16'h0200) || (16'h0000 > {received_data[0], received_data[1]})) begin
            acc <= {received_data[0], received_data[1]};
        end else begin
            acc <= 16'h0000;
        end
        //led_out <= received_data[0];
    end

    always_comb begin
        if(64'h0000_0000_0000_0000 <= posi_out && posi_out < 64'h0000_0001_84db__a7cc) begin
            led_out <= 8'h01;
        end else if(64'h0000_0001_84db_a7cc <= posi_out && posi_out < 64'h0000_0003_09b7_4f98) begin
            led_out <= 8'h02;
        end else if(64'h0000_0003_09b7_4f98 <= posi_out && posi_out < 64'h0000_0004_8e92_f764) begin
            led_out <= 8'h04;
        end else if(64'h0000_0004_8e92_f764 <= posi_out && posi_out < 64'h0000_0006_136e_9f30) begin
            led_out <= 8'h08;
        end else if(64'h0000_0006_136e_9f30 <= posi_out && posi_out < 64'h0000_0007_984a_46fc) begin
            led_out <= 8'h10;
        end else if(64'h0000_0007_984a_46fc <= posi_out && posi_out < 64'h0000_0009_1d25_eec8) begin
            led_out <= 8'h20;
        end else if(64'h0000_0009_1d25_eec8 <= posi_out && posi_out < 64'h0000_000a_a201_9694) begin
            led_out <= 8'h40;
        end else if(64'h0000_000a_a201_9694 <= posi_out && posi_out < 64'h0000_000c_26dd_3e60) begin
            led_out <= 8'h80;
        end else begin
            led_out <= 8'h55;
        end
    end
endmodule
