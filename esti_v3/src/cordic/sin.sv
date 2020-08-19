module sin(
        input clk
    );

    logic [63:0] x_in = 64'h780000000;          //sin, cosを求めたい角度は0x4000000倍する

    logic [63:0] theta[17:0];
    logic [17:0] sign_table;
    logic [63:0] buffer;
    logic sign_table_flag = 0;

    logic [15:0] index = 16'h0000;

    always_ff @(posedge clk) begin              //符号テーブルの作成
        if(index == 16'd18) begin
            index <= 16'h0;
            sign_table_flag <= 1;
        end else if(index == 16'd0) begin
            buffer <= theta[0] - x_in;
            sign_table[index] = 1;
            index <= index + 16'h1;
        end else begin
            if(buffer[63] == 1'b1) begin
                buffer <= buffer + theta[index];
                sign_table[index] = 1;
            end else begin
                buffer <= buffer - theta[index];
                sign_table[index] = 0;
            end
            index <= index + 16'h1;
        end
    end

    logic [31:0] px = 32'h4000;                 //以下 0x4000倍された値で計算
    logic [31:0] x;
    logic [31:0] py = 32'h4000;
    logic [31:0] y;

    logic [15:0] index2 = 16'h0001;
    logic end_flag = 0;

    always_ff @(posedge clk) begin              //sin, cosの計算 px, pyを0x6964で割ると出る
        if((sign_table_flag == 1'b1) && (index2 == 16'd18)) begin
            end_flag <= 1'b1;
            px <= px;
            py <= py;
            index2 <= 16'h0; 
        end else if(sign_table_flag == 1'b1) begin
            px <= x;
            py <= y;
            index2 <= index2 + 16'h1; 
        end else begin
            px <= px;
            py <= py;
        end
    end
    
    always_comb begin
        if(sign_table[index2]) begin
            x = px - (py >> index2);
            y = py + (px >> index2);
        end else begin
            x = px + (py >> index2);
            y = py - (px >> index2);
        end
    end


    initial begin
        theta[0]  = 36'hb40000000;
        theta[1]  = 36'h6a429cc6c;
        theta[2]  = 36'h38251d021;
        theta[3]  = 36'h1c8004492;
        theta[4]  = 36'he4e2a993;
        theta[5]  = 36'h728de539;
        theta[6]  = 36'h394a86ac;
        theta[7]  = 36'h1ca5b5e8;
        theta[8]  = 36'he52e946;
        theta[9]  = 36'h729766d;
        theta[10] = 36'h394bb70;
        theta[11] = 36'h1ca5dbf;
        theta[12] = 36'he52ee0;
        theta[13] = 36'h729770;
        theta[14] = 36'h394bb8;
        theta[15] = 36'h1ca5db;
        theta[16] = 36'he52ed;
        theta[17] = 36'h72976;
    end
endmodule
