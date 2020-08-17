module uart_convert(
        input   logic uart_end_flag,
        output  logic [7:0] uart_wdata,
        output  logic uart_run_req = 1'b0,
        input   logic [63:0] posi_out
    );

    logic   [63:0] posi_buf;
    logic   [7:0] uart_cnt = 8'h00;

    always_ff @(posedge uart_end_flag) begin
        if(uart_cnt == 8'h00) begin
            posi_buf <= posi_out[63:0];
            if(8'h00 <= posi_out[63:60] && posi_buf[63:60] <= 8'h09) begin
                uart_wdata <= posi_out[63:60] + 8'h30;
            end else begin
                uart_wdata <= posi_out[63:60] + 8'h57;
            end
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h01) begin
            if(8'h00 <= posi_buf[59:56] && posi_buf[59:56] <= 8'h09) begin
                uart_wdata <= posi_buf[59:56] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[59:56] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h02) begin
            if(8'h00 <= posi_buf[55:52] && posi_buf[55:52] <= 8'h09) begin
                uart_wdata <= posi_buf[55:52] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[55:52] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h03) begin
            if(8'h00 <= posi_buf[51:48] && posi_buf[51:48] <= 8'h09) begin
                uart_wdata <= posi_buf[51:48] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[51:48] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h04) begin
            if(8'h00 <= posi_buf[47:44] && posi_buf[47:44] <= 8'h09) begin
                uart_wdata <= posi_buf[47:44] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[47:44] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h05) begin
            if(8'h00 <= posi_buf[43:40] && posi_buf[40:40] <= 8'h09) begin
                uart_wdata <= posi_buf[43:40] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[43:40] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h06) begin
            if(8'h00 <= posi_buf[39:36] && posi_buf[39:36] <= 8'h09) begin
                uart_wdata <= posi_buf[39:36] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[39:36] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h07) begin
            if(8'h00 <= posi_buf[35:32] && posi_buf[35:32] <= 8'h09) begin
                uart_wdata <= posi_buf[35:32] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[35:32] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end if(uart_cnt == 8'h08) begin
            posi_buf <= posi_out[31:0];
            if(8'h00 <= posi_out[31:28] && posi_buf[31:28] <= 8'h09) begin
                uart_wdata <= posi_out[31:28] + 8'h30;
            end else begin
                uart_wdata <= posi_out[31:28] + 8'h57;
            end
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h09) begin
            if(8'h00 <= posi_buf[27:24] && posi_buf[27:24] <= 8'h09) begin
                uart_wdata <= posi_buf[27:24] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[27:24] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h0a) begin
            if(8'h00 <= posi_buf[23:20] && posi_buf[23:20] <= 8'h09) begin
                uart_wdata <= posi_buf[23:20] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[23:20] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h0b) begin
            if(8'h00 <= posi_buf[19:16] && posi_buf[19:16] <= 8'h09) begin
                uart_wdata <= posi_buf[19:16] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[19:16] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h0c) begin
            if(8'h00 <= posi_buf[15:12] && posi_buf[15:12] <= 8'h09) begin
                uart_wdata <= posi_buf[15:12] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[15:12] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h0d) begin
            if(8'h00 <= posi_buf[11:8] && posi_buf[11:8] <= 8'h09) begin
                uart_wdata <= posi_buf[11:8] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[11:8] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h0e) begin
            if(8'h00 <= posi_buf[7:4] && posi_buf[7:4] <= 8'h09) begin
                uart_wdata <= posi_buf[7:4] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[7:4] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h0f) begin
            if(8'h00 <= posi_buf[3:0] && posi_buf[3:0] <= 8'h09) begin
                uart_wdata <= posi_buf[3:0] + 8'h30;
            end else begin
                uart_wdata <= posi_buf[3:0] + 8'h57;
            end
            posi_buf <= posi_buf;
            uart_cnt <= uart_cnt + 8'h01;
            uart_run_req <= 1'b1;
        end else if(uart_cnt == 8'h10) begin
            uart_wdata <= 8'h0D;
            uart_run_req <= 1'b1;
            uart_cnt <= uart_cnt + 8'h01;
        end else if(uart_cnt == 8'h11) begin
            uart_wdata <= 8'h0A;
            uart_run_req <= 1'b1;
            uart_cnt <= 8'h00;
        end
    end

endmodule
