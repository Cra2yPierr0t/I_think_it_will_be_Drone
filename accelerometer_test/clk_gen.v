module clk_gen(in, out);
    input in;
    output out;

    reg out = 1'b0;

    always @(posedge in) begin
        out <= ~out;
    end
endmodule
