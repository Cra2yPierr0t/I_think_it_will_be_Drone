.section vector
lw t0, 0x40c(zero)
lw t1, 0x0fc(zero)
sw t0, 0x100(t1)
addi t1, t1, 4
sw t1, 0x0fc(zero)
mret
