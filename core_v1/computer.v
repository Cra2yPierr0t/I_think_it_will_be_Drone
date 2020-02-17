module computer(input clock50M,
                input button,
                input rx,
                output tx,
					 output [7:0] led_out_data);

    wire [31:0] pc;
    wire [31:0] instr;
    
    wire [31:0] dmem_rw_addr;
    wire [31:0] dmem_w_data;
    wire dmem_w_en;
    wire [2:0] funct3;
    wire [31:0] dmem_r_data;
    wire [31:0] _dmem_r_data;
    wire [31:0] rs2_data;

    reg led_begin_flag = 0;
    reg [31:0] led_in_data;
    wire [31:0] led_state_reg;
	 wire [7:0] _led_out_data;

    wire [31:0] button_out_data;
	 
    reg clock = 0;
    reg clock_rom = 0;
    reg [31:0] cnt = 32'h00000000;
    reg [31:0] cnt_rom = 32'h00000000;
    
    wire int_req[1:0];

    reg [7:0] tx_data;
    wire [7:0] rx_data;
    reg tx_begin_flag = 0;
    wire tx_busy_flag;
    wire [31:0] tx_state_data;
	 wire debug_line;

    always @(posedge clock50M) begin
	     //if(cnt == 32'h017d7840) begin   
	         clock = ~clock;
			//	cnt = 32'h00000000;
		   //end else begin
			  //  cnt = cnt + 1;
			//end
    end
	 
	 always @(posedge clock50M) begin
        if(cnt_rom == 32'h00bebc20) begin
            clock_rom = ~clock_rom;
            cnt_rom = 32'h00000000;
        end else begin
            cnt_rom = cnt_rom + 1;
        end
	 end

    instr_mem instr_mem(.addr(pc),
	                     .clock(clock50M),
                        .instr(instr));
								
    cpu cpu(.pc(pc),
            .instr(instr),
            .dmem_rw_addr(dmem_rw_addr),
            .rs2_data(rs2_data),
            .dmem_w_en(dmem_w_en),
            .funct3(funct3),
            .dmem_r_data(dmem_r_data),
            .int_req(int_req[0] || int_req[1]),
            .clock(clock),
				.debug_line(debug_line));
				

    data_mem data_mem(.rw_addr(dmem_rw_addr),
                      .w_data(rs2_data),
                      .w_en(dmem_w_en),
                      .funct3(funct3),
                      .r_data(_dmem_r_data),
                      .clock(clock));

    always @(posedge clock) begin
        if(dmem_rw_addr == 32'h0000_03fc && dmem_w_en == 1'b1) begin
            led_begin_flag <= 1;
            led_in_data <= rs2_data;
        end else begin
            led_begin_flag <= 0;
            led_in_data <= led_in_data;
        end
    end

    always @(posedge clock) begin
        if(dmem_rw_addr == 32'h0000_0404 && dmem_w_en == 1'b1) begin
            tx_begin_flag <= 1'b1;  //未対応
            tx_data <= rs2_data[7:0];    //未宣言
        end else begin
            tx_begin_flag <= 1'b0;
            tx_data <= tx_data;
        end
    end

    assign tx_state_data = {28'h0000000, 3'b000, tx_busy_flag};
	 
    assign dmem_r_data = (dmem_rw_addr == 32'h0000_0408) ? tx_state_data//未対応
                       : (dmem_rw_addr == 32'h0000_040c) ? rx_data//未対応
                       : (dmem_rw_addr == 32'h0000_0400) ? button_out_data
							  : (dmem_rw_addr == 32'h0000_03f8) ? led_state_reg 
                       : _dmem_r_data;

    UART UART(.clk(clock50M),
              .rx(rx),
              .rx_data(rx_data),
              .tx(tx),
              .tx_data(tx_data),
              .tx_begin_flag(tx_begin_flag),
              .tx_busy_flag(tx_busy_flag),
              .access_addr(dmem_rw_addr),
              .int_req(int_req[1]));

    BUTTON BUTTON(.button(button),
                  .clock(clock),
                  .access_addr(dmem_rw_addr),
                  .out_data(button_out_data),
                  .int_req(int_req[0]));
					
    LED8 LED8(.in_data(led_in_data),
              .begin_flag(led_begin_flag),
              .state_reg(led_state_reg),
              .out_data(led_out_data),
              .clock(clock));
endmodule
