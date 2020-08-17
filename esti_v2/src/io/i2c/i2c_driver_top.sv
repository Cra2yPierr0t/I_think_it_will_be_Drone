//MPU-6050  400kHz
//MAX1000   12MHz

module i2c_driver_top(
        input   logic   clk,
        output  logic   SCL,
        inout      SDA,
        output  logic           end_flag,
        output  logic   [7:0] received_data[7:0]
    );

    logic           master_clk = 0;
    logic   [7:0]   clk_cnt = 8'h0;

    always @(posedge clk) begin
        if(clk_cnt == 8'h5) begin
            master_clk <= !master_clk;
            clk_cnt = 8'h00;
        end else begin
		      master_clk <= master_clk;
		  end
        clk_cnt = clk_cnt + 1;
    end

    logic           run_req = 0;
    logic           r_en = 1'b0;
    logic   [7:0]   i_reg_addr = 8'h6b;
    logic   [7:0]   send_data;
    logic   [2:0]   num_data;
	 
	 logic [1:0] cnt = 2'b00;

    logic   [7:0]   addrs[2:0];
    logic   [7:0]   send_datas[2:0];
    logic   [2:0]   num_datas[2:0];

    always @(posedge master_clk) begin  //初期化とデータ読み出し
        run_req <= 1'b1;
        i_reg_addr <= addrs[cnt];
        send_data <= send_datas[cnt];
        num_data    <= num_datas[cnt];
        if(end_flag == 1'b1) begin
            if(cnt != 2'b10) begin
                cnt <= cnt + 2'b01;
            end else begin
                cnt <= cnt;
                r_en <= 1'b1;
            end
        end
    end

    assign addrs[0] = 8'h6b;
    assign addrs[1] = 8'h1c;
    assign addrs[2] = 8'h3d;

    assign send_datas[0] = 8'h00;
    assign send_datas[1] = 8'b000_00_000;
    assign send_datas[2] = 8'h00;

    assign num_datas[0] = 3'b001;
    assign num_datas[1] = 3'b001;
    assign num_datas[2] = 3'b010;
        
    i2c_driver  i2c_driver(
            .clk            (master_clk),
            .SCL            (SCL    ),
            .SDA            (SDA    ),
            .run_req        (run_req),
            .slave_addr     (7'h68  ),
            .send_data      (send_data ),
            .r_en           (r_en   ),
            .i_reg_addr     (i_reg_addr),
            .num_data       (num_data),
            .received_data  (received_data  ),
            .end_flag       (end_flag)
        );
endmodule
