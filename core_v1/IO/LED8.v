module LED8(input [31:0] in_data,
            input begin_flag,
            output [31:0] state_reg,
            output reg [7:0] out_data,
            input clock);
    
    reg [23:0] delay_cnt = 8'h00;
    reg [31:0] buffer = 32'h00000000;
	 reg [2:0] state = 3'b000;

    assign state_reg = {28'h0000_000, 3'b000, ~((delay_cnt == 8'h00) && (begin_flag == 1'b0))};

    always @(posedge clock) begin
        case(state)
            3'b000: begin   //wait
                delay_cnt <= 8'h00;
                buffer <= in_data;
                if(begin_flag == 1'b1) begin
                    state <= 3'b001;
                end
            end
            3'b001: begin   //delay
                delay_cnt <= delay_cnt + 8'h01;
                buffer <= buffer;
                if(delay_cnt == 8'hff) begin
                    state <= 3'b010;
                end
            end
            3'b010: begin   //output
                out_data <= buffer[7:0];
                delay_cnt <= 8'h00;
                state <= 3'b000;
            end
        endcase
    end

/*
    always @(posedge clock) begin
        if(delay_cnt == 8'h00 && begin_flag == 1'b0) begin
            delay_cnt <= 8'h00;
            buffer <= in_data;
        end else if(delay_cnt == 8'h00 && begin_flag == 1'b1) begin
            delay_cnt <= delay_cnt + 8'h01;
            buffer <= in_data;
        end else if(delay_cnt != 8'hff) begin
            delay_cnt <= delay_cnt + 8'h01;
            buffer <= buffer;
        end else if(delay_cnt == 8'hff) begin
            delay_cnt <= 8'h00;
            out_data <= buffer[7:0];
        end else begin
            delay_cnt <= 8'h00;
            buffer <= buffer;
        end
    end
*/
endmodule
