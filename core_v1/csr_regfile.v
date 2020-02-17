module csr_regfile(
    input [11:0] csr_addr,
    input [31:0] csr_w_data,
    input [31:0] pc,
    input csr_w_en,
    output [31:0] csr_r_data,
    output reg [31:0] mtvec,
    output reg [31:0] mepc,
    output reg [31:0] mie,
    input int_req,
    input clock);

parameter MSTATUS   = 12'h300;
parameter MIE       = 12'h304;
parameter MTVEC     = 12'h305;
parameter MSCRATCH  = 12'h340;
parameter MEPC      = 12'h341;
parameter MCAUSE    = 12'h342;
parameter MTVAL     = 12'h343;
parameter MIP       = 12'h344;

    initial mie = 32'h00000800;
    reg [31:0] mstatus = 32'h00000008;
    reg [31:0] mcause, mtval, mip, mscratch;

    assign csr_r_data = (csr_addr == MSTATUS)   ? mstatus
                      : (csr_addr == MIE)       ? mie
                      : (csr_addr == MTVEC)     ? mtvec
                      : (csr_addr == MSCRATCH)  ? mscratch
                      : (csr_addr == MEPC)      ? mepc
                      : (csr_addr == MCAUSE)    ? mcause
                      : (csr_addr == MTVAL)     ? mtval
                      : 12'hxxx;

    always @(posedge clock) begin
        if(csr_w_en) begin
            case(csr_addr)
                MSCRATCH: mscratch = csr_w_data;
            endcase
        end

         if(mstatus[3] && mie[11] && int_req) begin
            mstatus <= 32'h00000000;
        end else begin
            mstatus <= mstatus;
        end
        
        if(csr_w_en == 1 && csr_addr == MIE) begin
            mie <= csr_w_data;
        end else if(mstatus[3] && mie[11] && int_req) begin   
            mie <= 32'h00000000;
        end else begin
            mie <= mie;
        end

        if(mstatus[3] && mie[11] && int_req) begin
            mcause <= 32'h8000000b;
        end

        if(mstatus[3] && mie[11] && int_req) begin
            mtvec <= 32'h000000f0;
        end else begin
            mtvec <= 32'h000000f0;
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

/*
    always @(posedge clock) begin
        if(csr_w_en) begin
            case(csr_addr)
                MSTATUS : csr_register[0] <= csr_w_data;
                MIE     : csr_register[1] <= csr_w_data;
                MTVEC   : csr_register[2] <= csr_register[2];   //同期例外
                MSCRATCH: csr_register[3] <= csr_w_data;
                MEPC    : csr_register[4] <= csr_w_data;
                MCAUSE  : csr_register[5] <= csr_register[5];   //同期例外
                MTVAL   : csr_register[6] <= csr_w_data;
                MIP     : csr_register[7] <= csr_w_data;
                default : csr_register[7] <= csr_w_data;    //後で同期例外割り込み線伸ばす
            endcase
        end else begin
            csr_register[0] <= csr_register[0];
        end
    end
*/
endmodule
