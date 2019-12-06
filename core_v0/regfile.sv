module regfile(
    input decode_elements dec_elem,
    input [4:0] w_a,
    input [31:0] w_d,
    input w_en,
    input clock,
    output regfile_r_elements regfr_elem
    );

    reg [31:0] regs [31:0];

    always @(*) begin
        regfr_elem.r1_d = regs[dec_elem.rs1];
        regfr_elem.r2_d = regs[dec_elem.rs2];
    end

    always @(posedge clock) begin
        if(w_en && w_a != 5'h0) begin
            regs[w_a] = w_d;
        end
    end
endmodule
