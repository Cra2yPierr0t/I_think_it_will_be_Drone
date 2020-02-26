.file "putc.s"
.option nopic
.text
.align 1
.global putc
.type putc, @function
putc:
    addi t1, zero, 1
.L7:
    lw t2, 0x408(zero)
    beq t1, t2, .L7
    sw a0, 0x404(zero)
    ret
