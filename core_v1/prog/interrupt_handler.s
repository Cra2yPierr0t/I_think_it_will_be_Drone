.section vector
lw t3, 0x40c(zero)
lw t4, 0x0fc(zero)
sw t3, 0x100(t4)
addi t4, t4, 4
sw t4, 0x0fc(zero)
mret
