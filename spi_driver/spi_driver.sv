/*
            AABBCCDD
    Busy:
            ________
        SS  

      SCLK  ________
        
      MOSI  XXXXXXXX

      MISO  ZZZZZZZZ

    Start:
            ____
        SS      \___

      SCLK  ________
        
      MOSI  XXXXXXXX

      MISO  ZZZZZZZZ

    Stop:
               _____
        SS  __/     

      SCLK  ________ 

      MOSI  XXXXXXXX

      MISO  ZZZZZZZZ

  RW_DATA:

        SS  ________
               ___
      SCLK  __/   \_
             ______ 
      MOSI  X______X
             ______ 
      MISO  X______X

    R_DATA:

        SS  ________
               ___
      SCLK  __/   \_

      MOSI  XXXXXXXX
             ______
      MISO  X______X

    W_DATA:
        
        SS  ________
               ___
      SCLK  __/   \_
             ______
      MOSI  X______X

      MISO  ZZZZZZZZ

SPI Mode
Mode | clk at idle | Data Sampling | Data shift
-----------------------------------------------
0    | Low         | posedge       | negedge
1    | Low         | negedge       | posedge
2    | High        | negedge       | posedge
3    | High        | posedge       | negedge

mode 0: ENC28J60
mode 2: LIS3DH      <- NOW!!!!

*/


module spi_driver(
        input   logic   clk,
        output  logic   SCLK,
        output  logic   MOSI,
        input   logic   MISO,
        output  logic   SS,
        output  logic   [7:0]   read_data 
    );

parameter A = 2'b00;
parameter B = 2'b01;
parameter C = 2'b10;
parameter D = 2'b11;

parameter START     = 5'b00000;
parameter STOP      = 5'b00001;
parameter RW_DATA   = 5'b00010;
parameter R_DATA    = 5'b00011;
parameter W_DATA    = 5'b00100;
parameter SEND_ADDR = 5'b00101;
parameter BUSY      = 5'b01111;

    logic   [4:0]   state    = BUSY;
    logic   [1:0]   ABCD_cnt = A;
    logic   [7:0]   write_data = 8'h77;
    logic   [5:0]   write_addr = 6'h20;
    logic   [2:0]   data_index  = 3'b111;
    logic           RW_sel = 1'b0;     //0: write, 1: read
    logic           auto_inc = 1'b0;   //0: remain, 1:increment

    typedef struct packed {
        logic   [7:0]   write_data_buf;
        logic   [7:0]   write_addr_ctrl_buf;
    } input_buf_;

    input_buf_ input_buf;

    always_ff @(posedge clk) begin
        case(state)
            BUSY: begin
                input_buf.write_data_buf <= write_data;
                input_buf.write_addr_ctrl_buf <= {RW_sel, auto_inc, write_addr};
                case(ABCD_cnt)
                    A: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= D;
                    end
                    D: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= A;
                        state   <= START;
                    end
                endcase
            end
            START: begin
                input_buf <= input_buf;
                case(ABCD_cnt) 
                    A: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= D;
                    end
                    D: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= A;
                        state   <= SEND_ADDR;
                    end
                endcase
            end
            STOP: begin
                input_buf <= input_buf;
                case(ABCD_cnt) 
                    A: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= D;
                        write_addr <= 6'h2a;
                        RW_sel <= 1'b1;
                    end
                    D: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b1;
                        ABCD_cnt <= A;
                        state   <= BUSY;
                    end
                endcase
            end
            RW_DATA: begin
                input_buf <= input_buf;
                SS <= 1'b0;
                case(ABCD_cnt) 
                    A: begin
                        SCLK    <= 1'b0;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCLK    <= 1'b1;
                        read_data[data_index] <= MISO;
                        MOSI    <= input_buf.write_data_buf[data_index];
                        ABCD_cnt <= C;
                    end
                    C: begin
                        SCLK    <= 1'b1;
                        read_data[data_index] <= MISO;
                        MOSI    <= input_buf.write_data_buf[data_index];
                        ABCD_cnt <= D;
                    end
                    D: begin
                        if(data_index == 3'b000) begin
                            data_index <= 3'b111;
                            state <= STOP;
                        end else begin
                            data_index  <= data_index - 3'b1;
                        end
                        ABCD_cnt <= A;
                        SCLK    <= 1'b0;
                    end
                endcase
            end
            SEND_ADDR: begin
                SS <= 1'b0;
                case(ABCD_cnt) 
                    A: begin
                        SCLK    <= 1'b0;
                        ABCD_cnt <= B;
                    end
                    B: begin
                        SCLK    <= 1'b1;
                        MOSI    <= input_buf.write_addr_ctrl_buf[data_index];
                        ABCD_cnt    <= C;
                    end
                    C: begin
                        SCLK    <= 1'b1;
                        MOSI    <= input_buf.write_addr_ctrl_buf[data_index];
                        ABCD_cnt    <= D;
                    end
                    D: begin
                        if(data_index == 3'b000) begin
                            data_index <= 3'b111;
                            state <= RW_DATA;
                        end else begin
                            data_index  <= data_index - 3'b1;
                        end
                        ABCD_cnt    <= A;
                        SCLK    <= 1'b0;
                    end
                endcase
            end
        endcase
    end
endmodule
