module esti_top(
        input   logic        clk,
        output  logic       SCL = 1,
        inout   SDA,
        input   logic        reset,
        output  logic [7:0]  led_out = 8'h00;
    );

    logic   [63:0]  posi_out = 64'h0000000000000000;
    logic   [15:0]  acc;
    logic   [7:0]   received_data[7:0];
    logic           end_flag;

    esti_core esti_core(
            .posi_out   (posi_out   ),
            .acc_in     (acc        ),
            .clk        (clk        ),
            .reset      (reset      )
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
    end

    always_comb begin
        if(64'h0 <= posi_out && posi_out < 64'h0000_0000_c26d_d3e6) begin
            led_out <= 8'h1;
        end else if(64'h0000_0000_c26d_d3e6 <= posi_out && posi_out < 64'h0000_0001_84db_a7cc) begin
            led_out <= 8'h2;
        end else if(64'h0000_0001_84db_a7cc <= posi_out && posi_out < 64'h0000_0002_4749_7bb2) begin
            led_out <= 8'h3;
        end else if(64'h0000_0002_4749_7bb2 <= posi_out && posi_out < 64'h0000_0003_09b7_4f98) begin
            led_out <= 8'h4;
        end else if(64'h0000_0003_09b7_4f98 <= posi_out && posi_out < 64'h0000_0003_cc25_237e) begin
            led_out <= 8'h5;
        end else begin
            led_out <= 8'hff;
        end
    end
endmodule
