module led_controller(G_DATA, LED);
    input [7:0] G_DATA;
    output [7:0] LED;

	 assign LED = G_DATA;
    //assign LED = controller(G_DATA);

    function [7:0] controller(input [7:0] G_DATA);
    begin
        if($signed(G_DATA) == 0) begin
            controller = 8'b00010000;
        end else if(0 < $signed(G_DATA) && $signed(G_DATA) < 31) begin
            controller = 8'b00001000;
        end else if(31 <= $signed(G_DATA) && $signed(G_DATA) < 62) begin
            controller = 8'b00000100;
        end else if(62 <= $signed(G_DATA) && $signed(G_DATA) < 93) begin
            controller = 8'b00000010;
        end else if(93 <= $signed(G_DATA) && $signed(G_DATA) <= 127) begin
            controller = 8'b00001000;
        end else if(-42 <= $signed(G_DATA) && $signed(G_DATA) < 0) begin
            controller = 8'b00100000;
        end else if(-84 <= $signed(G_DATA) && $signed(G_DATA) < -42) begin
            controller = 8'b01000000;
        end else if(-127 <= $signed(G_DATA) && $signed(G_DATA) < -84) begin
            controller = 8'b10000000;
        end
    end
    endfunction
endmodule