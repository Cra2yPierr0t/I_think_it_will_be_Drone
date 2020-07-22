/*
            AABBCCDD
    Busy:

        SS  ________

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
                ____
        SS  ___/    

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
               __
      SCLK  __/  \__

      MOSI  XXXXXXXX
             ______
      MISO  X______X

    W_DATA:
        
        SS  ________
               __  
      SCLK  __/  \__
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
*/

module spi_driver(
        input   logic   clk,
        output  logic   SCLK,
        output  logic   MOSI,
        input   logic   MISO,
        output  logic   SS
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
parameter BUSY      = 5'b01111;

    logic   [4:0]   state    = BUSY;
    logic   [1:0]   ABCD_cnt = 2'b00;
    logic   [7:0]   read_data;
    logic   [7:0]   wirte_data;
    logic   [7:0]   wirte_data_buf;
    logic   [2:0]   data_index  = 3'b000;

    always_ff @(posedge clk) begin
        case(state)
            BUSY: begin
                case(ABCD_cnt) begin
                    A: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b0;
                    end
                    B: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b0;
                    end
                    C: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b0;
                    end
                    D: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b0;
                    end

                end
            end
            START: begin
                case(ABCD_cnt) begin
                    A: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b0;
                    end
                    B: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b0;
                    end
                    C: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b0;
                    end
                    D: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b0;
                    end
                end
            end
            STOP: begin
                case(ABCD_cnt) begin
                    A: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b0;
                    end
                    B: begin
                        SS      <= 1'b0;
                        SCLK    <= 1'b0;
                    end
                    C: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b0;
                    end
                    D: begin
                        SS      <= 1'b1;
                        SCLK    <= 1'b0;
                    end
                end
            end
            RW_DATA: begin
                case(ABCD_cnt) begin
                    SS <= 1'b0;
                    A: begin
                        SCLK    <= 1'b0;
                    end
                    B: begin
                        SCLK    <= 1'b1;
                        read_data[] <= MISO;
                        MOSI        <= write_data_buf[];
                    end
                    C: begin
                        SCLK    <= 1'b1;
                        read_data[] <= MISO;
                        MOSI        <= write_data_buf[];
                    end
                    D: begin
                        SCLK    <= 1'b0;
                    end
                end
            end
            R_DATA: begin
                case(ABCD_cnt) begin
                    A: begin
                    end
                    B: begin
                    end
                    C: begin
                    end
                    D: begin
                    end
                end
            end
            W_DATA: begin
                case(ABCD_cnt) begin
                    A: begin
                    end
                    B: begin
                    end
                    C: begin
                    end
                    D: begin
                    end
                end
            end
        endcase
    end

endmodule
