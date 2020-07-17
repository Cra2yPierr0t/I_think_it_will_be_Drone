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
        inout   logic   SDA
    );

parameter BUSY = 4'b0000;
parameter START = 4'b0001;
parameter RSTART = 4'b0010;
parameter STOP = 4'b0011;
parameter S_ADDR_W = 4'b0100;
parameter S_ADDR_R = 4'b0101;
parameter REG_ADDR = 4'b0110;
parameter DATA = 4'b0111;
parameter ACK = 4'b1000;
parameter NACK = 4'b1001;
parameter ERR = 4'b1010;

parameter W =   1'b0;
parameter R =   1'b1;

parameter A =   3'b000;
parameter B =   3'b001;
parameter C =   3'b010;
parameter D =   3'b011;

    logic   [2:0]   ABCD_cnt    = A;
    logic   [3:0]   state       = BUSY;
    logic   [3:0]   pstate      = 4'b000;

    logic   [3:0]   data_index  = 4'b0000;
    logic   [7:0]   slave_addr  = 8'h55;
    logic   [7:0]   received_data;
    
    logic   [7:0]   i_reg_addr  = 8'h22; 

    logic   [8:0]   slave_addr_w;
    logic   [8:0]   slave_addr_r;

    logic           ack_flag;

    assign slave_addr_w  = {W, slave_addr};
    assign slave_addr_r  = {R, slave_addr};
    
// 幸せのステートマシン

    always_ff @(posedge clk) begin
        case(state)
            BUSY    : begin
                SCL <= 1'b1;
                SDA = 1'b1;
                pstate <= state;
                state <= START;
            end
            START   : begin
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b1;
                        SDA = 1'b1;
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = 1'b1;
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = 1'b0;
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = 1'b0;
                        ABCD_cnt    <= A;
                        pstate <= state;
                        state <= S_ADDR_W;
                    end
                endcase
            end
            RSTART  : begin
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = 1'b1;
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = 1'b1;
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = 1'b0;
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = 1'b0;
                        ABCD_cnt    <= A;
                        pstate <= state;
                        state   <= S_ADDR_R;
                    end
                endcase
            end
            STOP    : begin
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = 1'b0;
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = 1'b0;
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = 1'b1;
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b1;
                        SDA = 1'b1;
                        ABCD_cnt    <= A;
                        pstate <= state;
                        state  <= BUSY;
                    end
                endcase
            end
            S_ADDR_W    : begin 
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = slave_addr_w[data_index]; //valid data
                        ABCD_cnt    <= A;
                        if(data_index == 4'b1000)begin
                            pstate      <= state;
                            state       <= ACK;
                            data_index  <= 4'b0000;
                        end else begin
                            state       <= state;
                            data_index  <= data_index + 1;
                        end
                    end
                endcase
            end
            S_ADDR_R    : begin 
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = slave_addr_r[data_index]; //valid data
                        ABCD_cnt    <= A;
                        if(data_index == 4'b1000)begin
                            pstate      <= state;
                            state       <= ACK;
                            data_index  <= 4'b0000;
                        end else begin
                            state       <= state;
                            data_index  <= data_index + 1;
                        end
                    end
                endcase
            end
            REG_ADDR    : begin 
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = i_reg_addr[data_index[2:0]]; //valid data
                        ABCD_cnt    <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = i_reg_addr[data_index[2:0]]; //valid data
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = i_reg_addr[data_index[2:0]]; //valid data
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = i_reg_addr[data_index[2:0]]; //valid data
                        ABCD_cnt    <= A;
                        if(data_index == 4'b0111)begin
                            pstate      <= state;
                            state       <= ACK;
                            data_index  <= 4'b0000;
                        end else begin
                            state       <= state;
                            data_index  <= data_index + 1;
                        end
                    end
                endcase
            end
            DATA    : begin
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = 1'bz;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = 1'bz; //valid data
                        received_data[data_index[2:0]] = SDA;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = 1'bz; //valid data
                        received_data[data_index[2:0]] = SDA;
                        ABCD_cnt <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = 1'bz;
                        ABCD_cnt <= A;
                        if(data_index == 4'b0111)begin
                            pstate      <= state;
                            state       <= NACK;
                            data_index  <= 4'b0000;
                        end else begin
                            state       <= state;
                            data_index  <= data_index + 1;
                        end
                    end
                endcase
            end
            ACK     : begin
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = 1'bz;
                        ack_flag <= 1'b1;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = 1'bz;
                        ack_flag <= !SDA;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = 1'bz;
                        ack_flag <= !SDA;
                        ABCD_cnt <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = 1'bz;
                        ABCD_cnt <= A;
                        pstate <= state;
                        if(ack_flag) begin
                            if(pstate == S_ADDR_W) begin
                                state <= REG_ADDR;
                            end else if(pstate == REG_ADDR) begin
                                state <= RSTART;
                            end else if(pstate == S_ADDR_R) begin
                                state <= DATA;
                            end else begin
                                state <= ERR;
                            end
                        end else begin
                            state <= ERR;
                        end
                    end
                endcase
            end
            NACK    : begin
                case(ABCD_cnt)
                    A: begin
                        SCL <= 1'b0;
                        SDA = 1'b1;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCL <= 1'b1;
                        SDA = 1'b1;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SCL <= 1'b1;
                        SDA = 1'b1;
                        ABCD_cnt <= D;
                    end
                    D: begin
                        SCL <= 1'b0;
                        SDA = 1'b1;
                        ABCD_cnt <= A;
                        pstate  <= state;
                        state   <= STOP;
                    end
                endcase
            end
        endcase
    end
endmodule
