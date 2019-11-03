module accelerometer_driver(CLK12M, SDO, SDI, SPC, CS, out);
    input CLK12M, SDO;
    output CS, SPC, SDI;
    output [7:0] out;

    reg RW = 1'b1;
    reg MS = 1'b0;
    reg [5:0] AD = 6'b100000;
    reg [7:0] DI = 8'b00100111;
    reg [7:0] DO = 8'b10101010;
    reg SPC = 1'b1;
    reg [15:0] SDI_DATA;
    reg CS = 1'b1;
    reg SDI = 1'b1;
    reg [7:0] out;
    reg [3:0] cnt = 4'd0;
    reg buff;

    reg init = 1'b0;

    always @(negedge CLK12M) begin
        if(CS == 1'b0) begin
            SDI_DATA <= init ? {RW, MS, AD, DI} : {1'b1, 1'b0, 6'b100000, 8'b00100111};
            SPC <= ~SPC;
            if(SPC == 1'b0) begin
                SDI <= SDI_DATA[15 - cnt];
                cnt <= cnt + 4'd1;
                if(cnt > 7) begin
                    DO[cnt - 8] <= SDO;
                end else begin
                    buff <= SDO;
                end
            end else begin
                SDI <= SDI;
                if(cnt == 4'd15) begin
                    cnt <= 4'd0;
                    init <= 1'b1;
                    CS <= 1'b1;
                end else begin
                    cnt <= cnt;
                end
            end
        end else begin
            CS <= 1'b0;
        end
        out <= DO;
    end
endmodule
