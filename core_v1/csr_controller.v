module csr_controller(input [2:0] funct3,
                      input [31:0] csr_r_data,
                      input [31:0] zimm,
                      input [31:0] rs1_data,
                      output [31:0] csr_w_data);
    
    assign csr_w_data = csr_wd_gen(funct3, csr_r_data, zimm, rs1_data);

    function [31:0] csr_wd_gen(input [2:0] funct3,
                               input [31:0] csr_r_data,
                               input [31:0] zimm,
                               input [31:0] rs1_data);
        begin
            case(funct3)
                001: csr_wd_gen = rs1_data;     //csrrw
                010: csr_wd_gen = csr_r_data | rs1_data; //csrrs
                011: csr_wd_gen = csr_r_data & (~rs1_data); //csrrc
                101: csr_wd_gen = zimm; //csrrwi
                110: csr_wd_gen = csr_r_data | zimm; //csrrsi
                111: csr_wd_gen = csr_r_data & (~zimm);  //csrrci
                default: csr_wd_gen = 32'h00000000;
            endcase
        end
    endfunction
    
endmodule
