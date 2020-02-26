.global getc
getc:
lw t0, 0xfc(zero)
beq t0, zero, getc
addi t0, t0, -4
lw a0, 0x100(t0)
sw t0, 0xfc(zero)
ret
