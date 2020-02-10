module computer(input clock50M,
                input button,
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

    wire [31:0] button_out_data;
	 
	 reg clock = 0;
	 reg clock_rom = 0;
	 reg [23:0] cnt = 24'h000000;
	 reg [23:0] cnt_rom = 24'h000000;
    always @(posedge clock50M) begin
        if(cnt == 24'h00001388) begin
            cnt <= 24'h000000;
            clock <= ~clock;
        end else begin
            cnt <= cnt + 1;
        end
    end
	 
	 always @(posedge clock50M) begin
	     if(cnt_rom == 24'h000009c4) begin
		      cnt_rom <= 24'h000000;
				clock_rom = ~clock_rom;
        end else begin
		      cnt_rom <= cnt_rom + 1;
		  end
	 end

    instr_mem instr_mem(.addr(pc),
	                     .clock(clock_rom),
                        .instr(instr));
								
    cpu cpu(.pc(pc),
            .instr(instr),
            .dmem_rw_addr(dmem_rw_addr),
            .rs2_data(rs2_data),
            .dmem_w_en(dmem_w_en),
            .funct3(funct3),
            .dmem_r_data(dmem_r_data),
            .int_req(int_req),
            .clock(clock));
				

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

    assign dmem_r_data = (dmem_rw_addr == 32'h0000_03f8) ? led_state_reg 
                       : (dmem_rw_addr == 32'h0000_0400) ? button_out_data
                       : _dmem_r_data;

    BUTTON BUTTON(.button(button),
                  .clock(clock),
                  .access_addr(dmem_rw_addr),
                  .out_data(button_out_data),
                  .int_req(int_req));

    LED8 LED8(.in_data(led_in_data),
              .begin_flag(led_begin_flag),
              .state_reg(led_state_reg),
              .out_data(led_out_data),
              .clock(clock));
endmodule
