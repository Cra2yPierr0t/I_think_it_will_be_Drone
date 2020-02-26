`timescale 1ns/1ps
module test_bench();
parameter TIMESCALE_HZ = 1000_000_000;
parameter CLOCK_HZ = 50_000_000;
parameter BAUD_RATE = 115200;
parameter TIME_CLOCK = $floor(TIMESCALE_HZ / CLOCK_HZ);
parameter TIME_BIT = $floor(TIMESCALE_HZ / BAUD_RATE);
    reg clock = 0;
    reg button = 1;
    reg rx = 1;

    wire tx;
    wire [7:0] led_out_data;

    initial begin   
        $dumpfile("wave.vcd");
        $dumpvars(0, computer);
    end

    always #(TIME_CLOCK/2) begin
        clock = ~clock;
    end

    computer computer(.clock50M(clock),
                      .button(button),
                      .rx(rx),
                      .tx(tx),
                      .led_out_data(led_out_data));

    initial begin
        #10000
        #(40*TIME_BIT)
        rx = 1'b0;
        #(TIME_BIT);
        rx = 1'b0;
        #(TIME_BIT);
        rx = 1'b1;
        #(TIME_BIT);
        rx = 1'b0;
        #(TIME_BIT);
        rx = 1'b1;
        #(TIME_BIT);
        rx = 1'b0;
        #(TIME_BIT);
        rx = 1'b1;
        #(TIME_BIT);
        rx = 1'b0;
        #(TIME_BIT);
        rx = 1'b1;
        #(TIME_BIT);
        rx = 1'b1;
        #(TIME_BIT);
        #(40*TIME_BIT)
        $finish;
    end
endmodule
