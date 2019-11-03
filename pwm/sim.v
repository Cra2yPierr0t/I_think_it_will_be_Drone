module sim();
    reg clk_in = 0;
    wire clk_out;

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, pwm);
    end

    pwm pwm(clk_in, clk_out);

    always #1 begin
        clk_in = ~clk_in;
    end

    initial begin
        #7000
        $finish;
    end
endmodule
