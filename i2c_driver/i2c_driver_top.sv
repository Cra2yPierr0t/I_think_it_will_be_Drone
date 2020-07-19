//MPU-6050  400kHz
//MAX1000   12MHz

module i2c_driver_top(
        input   logic   clk,
        output  logic   SCL = 1,
        inout      SDA,
        output  logic   [7:0] received_data
    );

    logic           master_clk = 0;
    logic   [1:0]   clk_cnt = 2'b00;

    always @(posedge clk) begin
        if(clk_cnt == 2'b11) begin
            master_clk <= !master_clk;
        end else begin
		      master_clk <= master_clk;
		  end
        clk_cnt = clk_cnt + 1;
    end

    logic           run_req = 0;
    logic           r_en = 1'b0;
    logic   [7:0]   i_reg_addr = 8'h6b;
	 
	 logic [1:0] cnt = 2'b00;

    always @(posedge master_clk) begin
        run_req <= 1'b1;
        cnt <= cnt + 1;
		  if(cnt == 2'b11) begin
		      r_en <= 1'b1;
				i_reg_addr <= 8'h47;
		  end
    end

    i2c_driver  i2c_driver(
            .clk            (master_clk     ),
            .SCL            (SCL    ),
            .SDA            (SDA    ),
            .run_req        (run_req),
            .slave_addr     (7'h68  ),
            .send_data      (8'h00  ),
            .r_en           (r_en   ),
            .i_reg_addr     (i_reg_addr),
            .received_data  (received_data  )
        );
endmodule
