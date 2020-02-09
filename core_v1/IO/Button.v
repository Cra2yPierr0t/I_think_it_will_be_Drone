module BUTTON(input button,
              input clock,
              input [31:0] access_addr,
              output reg [31:0] out_data = 32'h00000000,
              output reg int_req = 1'b0);

    reg state = 0;
    always @(posedge button) begin
        out_data <= out_data + 32'h00000001;
    end

    always @(posedge clock) begin
        if(state == 0) begin
            int_req <= 1'b0;
            if(~button == 1'b1) begin
                state <= 1'b1;
            end else begin
                state <= state;
            end
        end else if(state == 1) begin
            int_req <= 1'b1;
            if(access_addr == 32'h00000400) begin
                state <= 1'b0;
            end else begin
                state <= state;
            end
        end
    end
endmodule
