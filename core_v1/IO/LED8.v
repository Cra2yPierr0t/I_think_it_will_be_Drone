module LED8(input [31:0] in_data,
            input begin_flag,
            output reg [31:0] state_reg,
            output reg [7:0] out_data,
            input clock);
    
    reg [4:0] delay_cnt = 5'b00000;
    reg [31:0] buffer;

    always @(posedge clock) begin
        if(delay_cnt == 5'b00000 && begin_flag == 1'b0) begin
            delay_cnt <= 5'b00000;
            state_reg <= 32'h00000000;
            buffer <= in_data;
        end else if(delay_cnt == 5'b00000 && begin_flag == 1'b1) begin
            delay_cnt <= delay_cnt + 5'b00001;
            state_reg <= 32'h00000001;
            buffer <= in_data;
        end else if(delay_cnt != 5'b11111) begin
            delay_cnt <= delay_cnt + 5'b00001;
            state_reg <= 32'h00000001;
            buffer <= buffer;
        end else if(delay_cnt == 5'b11111) begin
            delay_cnt <= 5'b00000;
            state_reg <= 32'h00000001;
            out_data <= buffer[7:0];
        end
    end
endmodule
