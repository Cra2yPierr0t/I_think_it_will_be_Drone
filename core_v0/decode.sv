module decode(
    input [31:0]instr,
    input clock,
    output decode_elements dec_elem
    );

    always @(posedge clock) begin
        case(instr[7:0])
            8'h33: begin
                dec_elem.op <= instr[7:0];
                dec_elem.rs1 <= instr[19:15];
                dec_elem.rs2 <= instr[24:20];
                dec_elem.rd <= instr[11:7];
                dec_elem.funct7 <= instr[31:25];
            end
            //8'h13:
            8'h03: begin
                dec_elem.op <= instr[7:0];
                dec_elem.rs1 <= instr[19:15];
                dec_elem.rd <= instr[11:7];
                dec_elem.funct3 <= instr[14:12];
                dec_elem.imm <= instr[31:20];
            end
            8'h23: begin
                dec_elem.op <= instr[7:0];
                dec_elem.rs1 <= instr[19:15];
                dec_elem.rs2 <= instr[24:20];
                dec_elem.funct3 <= instr[14:12];
                dec_elem.imm[4:0] <= instr[11:7];
                dec_elem.imm[11:5] <= instr[31:25];
            end
            8'h6f: begin
                dec_elem.op <= instr[7:0];
                dec_elem.rd <= instr[11:7];
                dec_elem.imm[0] <= 1'h0;
                dec_elem.imm[10:1] <= instr[29:20];
                dec_elem.imm[11] <= instr[19];
                dec_elem.imm[19:12] <= instr[19:12];
                dec_elem.imm[31:20] <= instr[31] ? 12'hfff : 12'h000;
            end
            8'h63: begin
                dec_elem.op <= instr[7:0];
                dec_elem.rs1 <= instr[19:15];
                dec_elem.rs2 <= instr[24:20];
                dec_elem.funct3 <= instr[14:12];
                dec_elem.imm[0] <= 1'h0;
                dec_elem.imm[4:1] <= instr[11:8];
                dec_elem.imm[10:5] <= instr[30:25];
                dec_elem.imm[12] <= instr[7];
                dec_elem.imm[31:12] <= instr[31] ? 20'hffff : 20'h0000;
            end
        endcase
    end
endmodule
