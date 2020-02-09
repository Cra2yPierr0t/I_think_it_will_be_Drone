module csr_regfile_ro(input [11:0] csr_addr,
                      input [31:0] pc,
                      output [31:0] csr_r_data,
                      output reg [31:0] mtvec,
                      output reg [31:0] mepc,
                      output reg [31:0] mie,
                      input int_req,
                      input clock,
                      input ret);

parameter MSTATUS   = 12'h300;
parameter MIE       = 12'h304;
parameter MTVEC     = 12'h305;
parameter MEPC      = 12'h341;
parameter MCAUSE    = 12'h342;
parameter MTVAL     = 12'h343;
parameter MIP       = 12'h344;

    initial mie = 32'h00000800;

    reg [31:0] mstatus = 32'h00000008;
    reg [31:0] mcause, mtval, mip;

    assign csr_r_data = (csr_addr == MSTATUS)   ? mstatus
                      : (csr_addr == MIE)       ? mie
                      : (csr_addr == MTVEC)     ? mtvec
                      : (csr_addr == MEPC)      ? mepc
                      : (csr_addr == MCAUSE)    ? mcause
                      : (csr_addr == MTVAL)     ? mtval
                      : (csr_addr == MIP)       ? mip
                      : 32'hxxxxxxxx;

    always @(posedge clock) begin
        if(ret == 1'b1) begin
            mstatus <= 32'h00000008;
        end else if(mstatus[3] && mie[11] && int_req) begin
            mstatus <= 32'h00000000;
        end else begin
            mstatus <= mstatus;
        end

        if(ret == 1'b1) begin
            mie <= 32'h00000800;
        end else if(mstatus[3] && mie[11] && int_req) begin   
            mie <= 32'h00000000;
        end else begin
            mie <= mie;
        end

        if(mstatus[3] && mie[11] && int_req) begin
            mcause <= 32'h8000000b;
        end

        if(mstatus[3] && mie[11] && int_req) begin
            mtvec <= 32'h00000500;
        end else begin
            mtvec <= 32'h00000500;
        end

        if(mstatus[3] && mie[11] && int_req) begin
            mtval <= 32'h0000000f;
        end else begin
            mtval <= mtval;
        end

        if(mstatus[3] && mie[11] && int_req) begin
            mepc <= pc;
        end else begin
            mepc <= mepc;
        end

    end
endmodule
