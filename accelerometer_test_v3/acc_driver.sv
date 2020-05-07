module acc_driver(
    input   logic   clk12M,
    inout   wire   SDA,
    output  logic   SCL
);  

    reg clk400K = 0;
    reg clk800K = 0;
    reg [5:0] clk400K_cnt = 6'b000000;

    reg [3:0] state = 0;
    
    parameter BUSY = 4'd0;
    parameter START = 4'd1;
    parameter SLAVE_ADDR_W = 4'd2;
    parameter WAIT_ACK_1  = 4'd3;
    parameter START_R = 4'd4;
    parameter SLAVE_ADDR_R = 4'd5;
    parameter WAIT_ACK_2  = 4'd6;
    parameter GET_DATA = 4'd7;
    parameter STOP = 4'd8;

    reg SCL_buf = 1;
    reg SDA_buf = 1;

    reg [5:0] data_index = 0;

    always_ff @(posedge clk12M) begin
        if(clk400K_cnt == 6'd14) begin
            clk400K = ~clk400K;
            clk400K_cnt = 6'd0;
        end else begin
            clk400K_cnt = clk400K_cnt + 1;
        end
    end

    reg [31:0] general_cnt = 32'h0000_0000;

    always_ff @(posedge clk12M) begin
        if(state == BUSY) begin
            SDA_buf = 1;
            SCL_buf = 1;
            if(general_cnt == 300 - 1) begin
                state = START
                general_cnt = 0;
            end else begin
                genenral_cnt = general_cnt + 1;
            end
        end else if(state == START) begin
            SDA_buf = 0;    //START送信 SCLがHighでSDAをlowに
            if(cnt < 12) begin  //1.0μs待機
                general_cnt = general_cnt + 1;
                SCL_buf = 1;
            if(cnt == 100) begin
                general_cnt = 0;
                state = SLAVE_ADDR_W;
                SCL_buf = 0;
            end else begin
                general_cnt = general_cnt + 1;
                SCL_buf = 0;
            end
        end else if(state == SLAVE_ADDR_W) begin
            //データを送信する為の、非常に陳腐で冗長で複雑なロジック↓
            if((clk400K_cnt == 0) && (clk400K == 0) && (data_index != 8)) begin
                SDA_buf = 0;
                general_cnt = general_cnt + 1;
            end else if((general_cnt == 7) && (data_index != 8)) begin
                SDA_buf = data[data_index];   //MBS先頭にデータ送信 W
                data_intdex = data_index + 1;
                general_cnt = 0;
            end else if((general_cnt == 7) && (data_index == 8)) begin
                data_index = 0;
                general_cnt = 0;
                state = WAIT_ACK_1;
            end
            SCL_buf = clk400K;
        end else if(state == WAIT_ACK) begin
            if(SDA == 0) begin
                general_cnt = general_cnt + 1;
            end else if(general_cnt != 0) begin
                general_cnt = general_cnt + 1;
            end else if(general_cnt == 28) begin
                general_cnt = 0;
                state = START_R;
            end
            SCL_buf = clk400K;
        end else if(state == START_R) begin
            //Sr: SLCがHighの時にSDAを下げる
            if(general_cnt < 12) begin
                SCL_buf = 0;
                SDA_buf = 1;
                general_cnt = general_cnt + 1;
            end else if((12 <= general_cnt) && (general_cnt < 24)) begin
                SCL_buf = 1;
                SDA_buf = 1;
                general_cnt = general_cnt + 1;
            end else if((24 <= general_cnt) && (genenral_cnt < 35)) begin
                SCL_buf = 1;
                SDA_buf = 0;
                general_cnt = general_cnt + 1;
            end else begin  //general_cnt == 35
                SCL_buf = 1;
                SDA_buf = 0;
                general_cnt = 0;
                state = SLAVE_ADDR_R;
            end
        end else if(state == SLAVE_ADDR_R) begin
            //データを送信する為の、非常に陳腐で冗長で複雑なロジック↓
            if((clk400K_cnt == 0) && (clk400K == 0) && (data_index != 8)) begin
                SDA_buf = 0;
                general_cnt = general_cnt + 1;
            end else if((general_cnt == 7) && (data_index != 8)) begin
                SDA_buf = data[data_index];   //MBS先頭にデータ送信 R
                data_intdex = data_index + 1;
                general_cnt = 0;
            end else if((general_cnt == 7) && (data_index == 8)) begin
                data_index = 0;
                general_cnt = 0;
                state = WAIT_ACK_2;
            end
            SCL_buf = clk400K;
        end else if(state == WAIT_ACK_2) begin
            if(SDA == 0) begin
                general_cnt = general_cnt + 1;
            end else if(general_cnt != 0) begin
                general_cnt = general_cnt + 1;
            end else if(general_cnt == 28) begin
                general_cnt = 0;
                state = GET_DATA;
            end
            SCL_buf = clk400K;
        end else if(state == GET_DATA) begin
            receved_data[] = SDA; //データ取得
            SCL_buf = clk400K;
        end else if(state == SEND_NACK) begin
            SDA_buf = 1;    //NACK送信 SCLがHighかつSDAが1
            SCL_buf = clk400K;
        end else if(state == STOP) begin
            SDA_buf = 1;    //STOP送信 SCLでHighの状態でSDAをHighに
            SCL_buf = 1;
            //BUSYに遷移
        end else begin
            SCL_buf = 1;
        end
    end
    
    assign SCL = SCL_buf;
    assign SDA = SDA_buf;
endmodule
