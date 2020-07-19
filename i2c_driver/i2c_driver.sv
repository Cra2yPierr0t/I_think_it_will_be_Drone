/*
            AABBCCDD
    Start:
            ______
        SCL       \_
            ____
        SDA     \___
    
    Rep Start:
               ___
        SCL __/   \_
             ___
        SDA /   \___

    Stop:
               _____
        SCL __/
                 ___
        SDA X___/
              
    Write:
               ___
        SCL __/   \_
             _______
        SDA X_______

    Read:
               ___
        SCL __/   \_
               ___
  slave SDA XXX___XX

    ACK:
               ___   
        SCL __/   \_

  slave SDA \______/

    NACK:
               ___
        SCL __/   \_
            ________
 Master SDA

*/

/*
Read Sequence

Master |S|AD+W|   |RA|   |S|AD+R|   |    |NACK|P|
Slave  | |    |ACK|  |ACK| |    |ACK|DATA|    |P|

Write Sequence

Master |S|AD+W|   |RA|   |DATA|   |P|
Slave  | |    |ACK|  |ACK|    |ACK|P|

S   : Start
AD  : Slave addr
W   : Write bit (0)
R   : Read bit  (1)
ACK : Acknowledge
NACK: Not Acknowledge
RA  : internal register addr
DATA: Data
P   : Stop

*/


module i2c_driver(
        input   logic   clk,
        output  logic   SCL,
        inout   logic   SDA,
        input   logic   run_req,
        input   logic   [6:0]   slave_addr,     //slaveアドレス
        input   logic   r_en,                   //読み出し(R) : 1 , 書き込み(R) : 0
        input   logic   [7:0]   send_data,      //書き込み用データ
        input   logic   [7:0]   i_reg_addr,     //slave内部のレジスタアドレス
        output  logic   [7:0]   received_data   //読み出しデータ
    );

parameter BUSY = 4'b0000;
parameter START = 4'b0001;
parameter RSTART = 4'b0010;
parameter STOP = 4'b0011;
parameter S_ADDR_W = 4'b0100;
parameter S_ADDR_R = 4'b0101;
parameter REG_ADDR = 4'b0110;
parameter RDATA = 4'b0111;
parameter ACK = 4'b1000;
parameter NACK = 4'b1001;
parameter ERR = 4'b1010;
parameter WDATA = 4'b1011;

parameter W =   1'b0;
parameter R =   1'b1;

parameter A =   3'b000;
parameter B =   3'b001;
parameter C =   3'b010;
parameter D =   3'b011;

    logic   run_flag = 1'b0;
    logic   end_flag = 1'b0;

    logic   [2:0]   ABCD_cnt    = A;
    logic   [3:0]   state       = BUSY;
    logic   [3:0]   pstate      = 4'b000;

    logic   [2:0]   data_index  = 3'b111;
    
    //logic   [7:0]   i_reg_addr  = 8'h6B; 

    logic   [7:0]   slave_addr_w;
    logic   [7:0]   slave_addr_r;

    //logic   [6:0]   slave_addr  = 7'h68;    //slveアドレス
    //logic   [7:0]   send_data   = 8'h00;    //書き込み用データ

    //logic   r_en = 0;   //読み出し(R) : 1 , 書き込み(R) : 0

    interface input_buf;
        logic   [6:0]   slave_addr_buf;
        logic   r_en_buf;   //r_enが途中で変更されないようにするためのバッファ
        logic   [7:0]   send_data_buf;
        logic   [7:0]   i_reg_addr_buf;
    endinterface

    logic   ack_flag;

    logic   SDA_buf;

// verilator lint_off BLKANDNBLK
    logic   SDA_en = 0;
// verilator lint_on BLKANDNBLK

    assign slave_addr_w  = {slave_addr_buf, W};
    assign slave_addr_r  = {slave_addr_buf, R};

    
    always @(posedge run_req or posedge end_flag) begin
        if(run_req) begin           //run_reqが常にHighなら連続で動く
            run_flag <= 1'b1;
        end else if(end_flag) begin
            run_flag <= 1'b0;
        end
    end

    
// 幸せのステートマシン

    always_ff @(posedge clk) begin
        case(state)
            BUSY    : begin
                input_buf.slave_addr_buf    <= slave_addr;
                input_buf.r_en_buf          <= r_en;
                input_buf.send_data_buf     <= send_data;
                input_buf.i_reg_addr_buf    <= i_reg_addr;
                SDA_en <= 1'b1;
                SCL <= 1'b1;
                SDA_buf <= 1'b1;
                pstate <= state;
                if(run_flag) begin
                    state <= START;
                end else begin
                    stete <= state;
                end
            end
            START   : begin                 //スタートコンディションの送信
                SDA_en <= 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b1;
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b1;
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b0;
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA_buf <= 1'b0;
                        ABCD_cnt    <= A;
                        pstate <= state;
                        state <= S_ADDR_W;
                    end
                endcase
            end
            RSTART  : begin                 //Repスタートコンディションの送信
                SDA_en <= 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA_buf <= 1'b1;
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b1;
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b0;
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA_buf <= 1'b0;
                        ABCD_cnt    <= A;
                        pstate <= state;
                        state   <= S_ADDR_R;
                    end
                endcase
            end
            STOP    : begin             //ストップコンディションの送信
                SDA_en <= 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA_buf <= 1'b0;
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b0;
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b1;
                        ABCD_cnt    <= D;
                        end_flag <= 1'b1; //end_flagのパルスを作る
                    end
                    D: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b1;
                        ABCD_cnt    <= A;
                        pstate <= state;
                        state  <= BUSY;
                        end_flag <= 1'b0; //end_flagのパルスを作る
                    end
                endcase
            end
            S_ADDR_W    : begin     //slaveアドレスの送信(W)
                SDA_en <= 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA_buf <= slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA_buf <= slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= A;
                        if(data_index == 3'b000)begin
                            pstate      <= state;
                            state       <= ACK;
                            data_index  <= 3'b111;
                        end else begin
                            state       <= state;
                            data_index  <= data_index - 1;
                        end
                    end
                endcase
            end
            S_ADDR_R    : begin     //slaveアドレスの送信(R)
                SDA_en <= 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA_buf <= slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA_buf <= slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= A;
                        if(data_index == 3'b000)begin
                            pstate      <= state;
                            state       <= ACK;
                            data_index  <= 3'b111;
                        end else begin
                            state       <= state;
                            data_index  <= data_index - 1;
                        end
                    end
                endcase
            end
            REG_ADDR    : begin     //slave内部のレジスタアドレスの送信
                SDA_en <= 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA_buf <= input_buf.i_reg_addr_buf[data_index]; //valid data
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= input_buf.i_reg_addr_buf[data_index]; //valid data
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= input_buf.i_reg_addr_buf[data_index]; //valid data
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA_buf <= input_buf.i_reg_addr_buf[data_index]; //valid data
                        ABCD_cnt    <= A;
                        if(data_index == 3'b000)begin
                            pstate      <= state;
                            state       <= ACK;
                            data_index  <= 3'b111;
                        end else begin
                            state       <= state;
                            data_index  <= data_index - 1;
                        end
                    end
                endcase
            end
            WDATA   : begin         //Masterからslaveへの書き込み用データの送信
                SDA_en <= 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA_buf <= input_buf.send_data_buf[data_index]; //valid data
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= input_buf.send_data_buf[data_index]; //valid data
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= input_buf.send_data_buf[data_index]; //valid data
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA_buf <= input_buf.send_data_buf[data_index]; //valid data
                        ABCD_cnt    <= A;
                        if(data_index == 3'b000)begin
                            pstate      <= state;
                            state       <= ACK;
                            data_index  <= 3'b111;
                        end else begin
                            state       <= state;
                            data_index  <= data_index - 1;
                        end
                    end
                endcase
            end
            RDATA    : begin        //slaveからMasterへの読み出しデータ受信
                SDA_en <= 1'b0;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        received_data[data_index] <= SDA;   //valid data
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        received_data[data_index] <= SDA;   //valid data
                        ABCD_cnt <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        ABCD_cnt <= A;
                        if(data_index == 3'b000)begin
                            pstate      <= state;
                            state       <= NACK;
                            data_index  <= 3'b111;
                        end else begin
                            state       <= state;
                            data_index  <= data_index - 1;
                        end
                    end
                endcase
            end
            ACK     : begin         //ACK検知
                SDA_en = 1'b0;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        ack_flag <= 1'b1;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        ack_flag <= !SDA;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        ack_flag <= !SDA;
                        ABCD_cnt <= D;
                    end
                    D: begin
                        pstate <= state;
                        if(ack_flag) begin
                            SCL <= 1'b0;
                            ABCD_cnt <= A;
                            if(pstate == S_ADDR_W) begin
                                state <= REG_ADDR;
                            end else if(pstate == REG_ADDR) begin
                                state <= r_en ? RSTART : WDATA;
                            end else if(pstate == S_ADDR_R) begin
                                state <= RDATA;
                            end else if(pstate == WDATA) begin
                                state <= STOP;
                            end else begin
                                state <= ERR;
                            end
                        end else begin
                            SCL <= 1'b1;
                            ABCD_cnt <= B;
                            state <= state;
                        end
                    end
                endcase
            end
            NACK    : begin         //NACK送信
                SDA_en = 1'b1;
                input_buf <= input_buf;
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA_buf <= 1'b1;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b1;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA_buf <= 1'b1;
                        ABCD_cnt <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA_buf <= 1'b1;
                        ABCD_cnt <= A;
                        pstate  <= state;
                        state   <= STOP;
                    end
                endcase
            end
            ERR     : begin     //エラー
                input_buf <= input_buf;
                SCL <= 1'b1;
                SDA_buf <= 1'b1;
            end
        endcase
    end
    assign SDA = SDA_en ? SDA_buf : 1'bz;   //トライステート・バッファ
endmodule
