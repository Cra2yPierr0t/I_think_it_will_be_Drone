module test_reg(input clock, 
                input [7:0] w_data, 
                input r_en);

    reg register[7:0];
    always @(posedge clock) begin
        if(r_en) begin
            register = w_data;
        end else begin
            register = register;
        end
    end
endmodule

module test_writer1(input clock,
                    input button,
                    output data,
                    output w_en);
    input [7:0] addr;
    reg flag;
    
    always @(posedge clock) begin
        if(addr == 255 && reg_w_en == 1) begin
            flag = 1
        end else begin
            flag = 0
        end
    end



endmodule
