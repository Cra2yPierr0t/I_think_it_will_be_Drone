module csr_regfile_rw(input [11:0] csr_addr,
                      input [31:0] csr_w_data,
                      input csr_w_en,
                      output [31:0] csr_r_data,
                      input clock,
                      input [31:0] csr_ro_data,
                      output [11:0] csr_ro_addr);

parameter MSTATUS   = 12'h300;
parameter MIE       = 12'h304;
parameter MTVEC     = 12'h305;
parameter MSCRATCH  = 12'h340;
parameter MEPC      = 12'h341;
parameter MCAUSE    = 12'h342;
parameter MTVAL     = 12'h343;
parameter MIP       = 12'h344;
    reg [31:0] mscratch;
    
    assign csr_ro_addr = csr_addr;
    assign csr_r_data = (csr_addr == MSCRATCH)  ? mscratch
                      : csr_ro_data;

    always @(clock) begin
        if(csr_w_en) begin
            case(csr_addr)
                MSCRATCH: mscratch = csr_w_data;
            endcase
        end
    end
endmodule
