module esti_top(
        input   logic        clk,
        output  logic       SCL = 1,
        inout   SDA,
        input   logic        reset,
        output  logic [7:0]  led_out
    );

    logic   [63:0]  posi_out;
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
        led_out = posi_out[47:40];
    end
endmodule
