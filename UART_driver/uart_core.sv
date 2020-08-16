module uart_core(
        input   logic clk,
        input   logic RX,
        output  logic TX,
        input   logic   [7:0] wdata,
        input   logic run_req,
        output  logic end_flag = 1'b0
    );
    
parameter BUSY  = 4'h0;
parameter START = 4'h1;
parameter WRITE_DATA    = 4'h2;
parameter READ_DATA     = 4'h3;
parameter STOP  = 4'h4;

    logic   run_flag = 0;

    logic   [3:0] state = BUSY;
    logic   [2:0] wdata_index = 3'b000;
    logic   [7:0] wdata_buf;

    always_ff @(posedge run_req or posedge end_flag) begin
        if(run_req) begin
            run_flag <= 1'b1;
        end else if(end_flag) begin
            run_flag <= 1'b0;
        end
    end

    always_ff @(posedge clk) begin
        case(state)
            BUSY: begin
                TX <= 1'b1;
                if(run_flag) begin
                    state <= START;
                    wdata_buf <= wdata;
                end else begin
                    state <= state;
                end
            end
            START: begin
                TX <= 1'b0;
                state <= WRITE_DATA;
            end
            WRITE_DATA: begin
                TX <= wdata_buf[wdata_index];
                if(wdata_index == 8'hff) begin
                    wdata_index <= 8'h00;
                    state <= STOP;
                    end_flag <= 1'b1;
                end else begin
                    wdata_index <= wdata_index + 8'h01;
                    state <= state;
                end
            end
            STOP: begin
                TX <= 1'b1;
                state <= BUSY;
                end_flag <= 1'b0;
            end
        endcase
    end
endmodule
