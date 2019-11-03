module accelerometer_test(CLK12M, SDO, SDI, SPC, CS, LED);
    input CLK12M, SDO;
    output SDI, SPC, CS;
    output [7:0] LED;

    wire [7:0] G_DATA;
    wire [7:0] out;

    assign G_DATA = out;

    accelerometer_driver accelerometer_driver(CLK12M, SDO, SDI, SPC, CS, out);
    led_controller led_controller(G_DATA, LED);
endmodule
