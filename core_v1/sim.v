module sim();
    reg clock;

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, computer);
    end

    initial begin
        clock = 0;
    end

    always #1 begin
        clock = ~clock;
    end

    computer computer(.clock50M(clock));

    initial begin
        #10000
        $finish;
    end
endmodule
