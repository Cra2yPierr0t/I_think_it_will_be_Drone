module csr_regfile(
    input [11:0] csr_addr,
    input [31:0] csr_w_data,
    input csr_w_en,
    output [31:0] csr_r_data,
    input clock);

parameter MSTATUS   = 12'h300;
parameter MIE       = 12'h304;
parameter MTVEC     = 12'h305;
parameter MSCRATCH  = 12'h340;
parameter MEPC      = 12'h341;
parameter MCAUSE    = 12'h342;
parameter MTVAL     = 12'h343;
parameter MIP       = 12'h344;
    reg [31:0] csr_register[2:0];
    assign csr_r_data = (csr_addr == MSTATUS)   ? csr_register[0]
                      : (csr_addr == MIE)       ? csr_register[1]
                      : (csr_addr == MTVEC)     ? csr_register[2]
                      : (csr_addr == MSCRATCH)  ? csr_register[3]
                      : (csr_addr == MEPC)      ? csr_register[4]
                      : (csr_addr == MCAUSE)    ? csr_register[5]
                      : (csr_addr == MTVAL)     ? csr_register[6]
                      : (csr_addr == MIP)       ? csr_register[7]
                      : 12'hxxx;

    always @(posedge clock) begin
        if(csr_w_en) begin
            case(csr_addr)
                MSTATUS : csr_register[0] <= csr_w_data;
                MIE     : csr_register[1] <= csr_w_data;
                MTVEC   : csr_register[2] <= csr_w_data;
                MSCRATCH: csr_register[3] <= csr_w_data;
                MEPC    : csr_register[4] <= csr_w_data;
                MCAUSE  : csr_register[5] <= csr_w_data;
                MTVAL   : csr_register[6] <= csr_w_data;
                MIP     : csr_register[7] <= csr_w_data;
                default : csr_register[7] <= csr_w_data;    //後で同期例外割り込み線伸ばす
            endcase
        end else begin
            csr_register[0] <= csr_register[0];
        end
    end
endmodule
