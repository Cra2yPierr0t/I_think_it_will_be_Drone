module pwm(clk_in, clk_out);
    input clk_in;
    output clk_out;

    reg clk_out;
    reg [2:0] state = 3'b000;
    reg [7:0] DIV = 0;
    reg [7:0] cnt = 8'b0;

    always @(negedge clk_in) begin
        if(cnt < 100 - DIV) begin
            clk_out <= 1'b0;
            cnt = cnt + 1;
        end else begin
            clk_out <= 1'b1;
            cnt = cnt + 1;
        end

        if(cnt == 99) begin
            cnt <= 0;
            case(state)
                3'b000: begin
                DIV <= 0;
                state <= state + 1;
                end
                3'b001: begin
                DIV <= 100;
                state <= state + 1;
                end
                3'b010: begin
                DIV <= 40;
                state <= state + 1;
                end
                3'b011: begin
                DIV <= 80;
                state <= state + 1;
                end
                3'b100: begin
                DIV <= 40;
                state <= state + 1;
                end
                3'b101: begin
                DIV <= 20;
                state <= state + 1;
                end
                3'b110: begin
                DIV <= 10;
                state <= state + 1;
                end
                3'b111: begin
                DIV <= 0;
                state <= state + 1;
                end
            endcase
        end
    end
endmodule
