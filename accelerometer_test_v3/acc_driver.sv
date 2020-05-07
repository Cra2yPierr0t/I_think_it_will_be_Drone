module acc_driver(
    input   logic   clk12M,
    inout   logic   SDA,
    output  logic   SCL
);  

    reg clk400K = 0;
    reg [5:0] clk_cnt = 6'b000000;
    always_ff @(posedge clk12M) begin
        if(clk_cnt == 6'd14) begin
            clk400K = ~clk400K;
            clk_cnt = 6'd0;
        end else begin
            clk_cnt = clk_cnt + 1;
        end
    end

    always_comb begin
        SCL = clk400K;
    end
endmodule
