module esti_top(
        input   logic        clk,
        input   logic [15:0] acc,
        input   logic        reset,
        output  logic [7:0]  led_out
    );

    logic   [63:0]  posi_out;

    esti_core esti_core(
            .posi_out   (posi_out   ),
            .acc_in     (acc        ),
            .clk        (clk        ),
            .reset      (reset      )
        );

    always_comb begin
        // posi_out -> led_out の処理
    end
endmodule
