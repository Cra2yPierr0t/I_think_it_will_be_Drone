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

    computer computer(.clock(clock));

    initial begin
        #1000
        $finish;
    end
endmodule
