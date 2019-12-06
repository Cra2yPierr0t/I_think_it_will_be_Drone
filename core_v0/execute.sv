module execute(
    input dec_elements dec_elem,
    input regfile_r_elements regfr_elem,
    input clock,
    output execute_elements exe_elem
    );

    always @(posedge clock) begin
        case(dec_elem.op)
            8'h33: begin
                case(dec_elem.funct3)
                    3'h00: exe_elem.rd_d = regfr_elem.r1_d + regfr_elem.r2_d;   //ADD
                    3'h07: exe_elem.rd_d = regfr_elem.r1_d & regfr_elem.r2_d;   //AND
                    3'h06: exe_elem.rd_d = regfr_elem.r1_d | regfr_elem.r2_d;   //OR
                    3'h04: exe_elem.rd_d = regfr_elem.r1_d ^ regfr_elem.r2_d;   //XOR
                endcase
                exe_elem.pc = fetch_elem.pc;
            end
            8'h03: begin
                case(dec_elem.funct3)
                    3'h02: exe_elem.rd_d = memr_elem.memr_d //LW     レジスタに書き込み用線の名前募集
                endcase
                exe_elem.pc = fetch_elem.pc;
            end
            8'h13: begin
                case(dec_elem.funct3)
                    3'h0: exe_elem.rd_d = regfr_elem.r1_d + dec_elem.imm;   //ADDI
                    3'h7: exe_elem.rd_d = regfr_elem.r1_d & dec_elem.imm;   //ANDI
                    3'h6: exe_elem.rd_d = regfr_elem.rd_d | dec_elem.imm;   //ORI
                    3'h4: exe_elem.rd_d = regfr_elem.rd_d ^ dec_elem.imm;   //XORI
                endcase
                exe_elem.pc = fetch_elem.pc;
            end
            8'h23: begin
                case(dec_elem.funct3)
                    3'h2: exe_elem.memw_d = regfr_elem.r1_d //SW
                endcase
                exe_elem.pc = fetch_elem.pc;
            end
            8'h6f: begin
                exe_elem.pc = dec_elem.imm + fetch_elem.pc;  //JAL
                exe_elem.rd_d = fetch_elem.pc + 1;
            end
            8'h63: begin
                case(dec_elem.funct3)
                    3'h0: if(dec_elem.r1_d == dec_elem.r2.d) begin
                        exe_elem.pc = dec_elem.imm + fetch_elem.pc; //BEQ
                    end else begin
                        exe_elem.pc = fetch_elem.pc + 1;
                    end
                endcase
            end
        endcase
    end
endmodule
//fetch_elemまだ
//exe_elemまた
