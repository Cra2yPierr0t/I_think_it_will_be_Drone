module acc_driver(
    input   logic   clk12M,
    inout   wire   SDA,
    output  logic   SCL
);  

    reg clk400K = 0;
    reg clk800K = 0;
    reg [5:0] clk_cnt = 6'b000000;

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

    always_ff @(posedge clk12M) begin
        if(clk_cnt == 6'd14) begin
            clk400K = ~clk400K;
            clk_cnt = 6'd0;
        end else begin
            clk_cnt = clk_cnt + 1;
        end
    end

    always_ff @(posedge clk12M) begin
        if(state == BUSY) begin
            SDA_buf = 1;
            SCL_buf = 1;
        end else if(state == START) begin
            SDA_buf = 0;    //START送信 SCLがHighでSDAをlowに
            SCL_buf = 1;
            //数クロック後に遷移
        end else if(state == SLAVE_ADDR_W) begin
            SDA_buf = data[];   //MBS先頭にデータ送信 W
            SCL_buf = clk400K;
            //送信後、遷移
        end else if(state == WAIT_ACK) begin
            if(SDA == 0) begin
                //ACKを感知後、遷移 SCLがHighかつSDAが0
            end
            SCL_buf = clk400K;
        end else if(state == START_R) begin
            if(/*SLCがHighの時にSDAを下げる*/) begin
                SDA_buf = 0;
            end else begin
                SDA_buf = 1;
            end
            SCL_buf = 1;
        end else if(state == SLAVE_ADDR_R) begin
            SDA_buf = data[]    //MBS先頭にデータ送信 R
            SCL_buf = clk400K;
            //送信後、遷移
        end else if(state == WAIT_ACK_2) begin
            if() begin
                //ACKを感知後、遷移 SCLがHighかつSDAが0
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
