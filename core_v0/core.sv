module core();
    fetch();
 
    decode(instr, clock, dec_elem);
    regfile(dec_elem, , , , clock, regfr_elem)

    execute(dec_elem, regfr_elem, clock, exe_elem);
    
    writeback();
endmodule
