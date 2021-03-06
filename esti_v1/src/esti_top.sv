module esti_top(
        input   logic        clk,
        output  logic       SCL = 1,
        inout   SDA,
        input   logic        reset,
        output  logic [7:0]  led_out = 8'h00
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

    always_ff @(posedge end_flag) begin
        acc <= {received_data[0], received_data[1]};
        //led_out <= posi_out[42:35];
    end

    always_comb begin
        if(64'h0000_0000_0000_0000 <= posi_out && posi_out < 64'h0000_0000_c26d_d3e6) begin
            led_out <= 8'h01;
        end else if(64'h0000_0000_c26d_d3e6 <= posi_out && posi_out < 64'h0000_0001_84db_a7cc) begin
            led_out <= 8'h02;
        end else if(64'h0000_0001_84db_a7cc <= posi_out && posi_out < 64'h0000_0002_4749_7bb2) begin
            led_out <= 8'h04;
        end else if(64'h0000_0002_4749_7bb2 <= posi_out && posi_out < 64'h0000_0003_09b7_4f98) begin
            led_out <= 8'h08;
        end else if(64'h0000_0003_09b7_4f98 <= posi_out && posi_out < 64'h0000_0003_cc25_237e) begin
            led_out <= 8'h10;
        end else if(64'h0000_0003_cc25_237e <= posi_out && posi_out < 64'h0000_0004_8e92_f764) begin
            led_out <= 8'h20;
        end else if(64'h0000_0004_8e92_f764 <= posi_out && posi_out < 64'h0000_0005_5100_cb4a) begin
            led_out <= 8'h40;
        end else if(64'h0000_0005_5100_cb4a <= posi_out && posi_out < 64'h0000_0006_136e_9f30) begin
            led_out <= 8'h80;
        end else begin
            led_out <= 8'h55;
        end
    end
endmodule
