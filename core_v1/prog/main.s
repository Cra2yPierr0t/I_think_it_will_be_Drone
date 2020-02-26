.file "main.s"
.global main
main:
    addi a0, zero, 'D'
    call putc
    addi a0, zero, 'e'
    call putc
    addi a0, zero, 't'
    call putc
    addi a0, zero, 'a'
    call putc
    addi a0, zero, 'r'
    call putc
    addi a0, zero, 'a'
    call putc
    addi a0, zero, 'm'
    call putc
    addi a0, zero, 'e'
    call putc
    addi a0, zero, ' '
    call putc
    addi a0, zero, 'O'
    call putc
    addi a0, zero, 'S'
    call putc
    addi a0, zero, 0x0D
    call putc
    addi a0, zero, 0x0A
    call putc
Term:
    addi a0, zero, 'p'
    call putc
    addi a0, zero, 'i'
    call putc
    addi a0, zero, 'e'
    call putc
    addi a0, zero, 'r'
    call putc
    addi a0, zero, 'r'
    call putc
    addi a0, zero, '0'
    call putc
    addi a0, zero, 't'
    call putc
    addi a0, zero, '@'
    call putc
    addi a0, zero, 'M'
    call putc
    addi a0, zero, 'a'
    call putc
    addi a0, zero, 'g'
    call putc
    addi a0, zero, 'i'
    call putc
    addi a0, zero, 'c'
    call putc
    addi a0, zero, 'a'
    call putc
    addi a0, zero, 'l'
    call putc
    addi a0, zero, '-'
    call putc
    addi a0, zero, 'F'
    call putc
    addi a0, zero, 'P'
    call putc
    addi a0, zero, 'G'
    call putc
    addi a0, zero, 'A'
    call putc
    addi a0, zero, ' '
    call putc
    addi a0, zero, '$'
    call putc
    addi a0, zero, ' '
    call putc
    call getc
    addi s1, zero, 'A'
    addi s2, zero, 'Z'
    beq a0, s1, AIEEEE
    beq a0, s1, ZAPZAP
    jal zero, OTHER
AIEEEE:
    addi a0, zero, 0x0D
    call putc
    addi a0, zero, 0x0A
    call putc
    addi a0, zero, 'A'
    call putc
    addi a0, zero, 'I'
    call putc
    addi a0, zero, 'E'
    call putc
    addi a0, zero, 'E'
    call putc
    addi a0, zero, 'E'
    call putc
    addi a0, zero, 'E'
    call putc
    addi a0, zero, 0x0D
    call putc
    addi a0, zero, 0x0A
    call putc
    jal zero, Term
ZAPZAP:
    addi a0, zero, 0x0D
    call putc
    addi a0, zero, 0x0A
    call putc
    addi a0, zero, 'Z'
    call putc
    addi a0, zero, 'A' 
    call putc
    addi a0, zero, 'P'
    call putc
    addi a0, zero, 'Z'
    call putc
    addi a0, zero, 'A'
    call putc
    addi a0, zero, 'P'
    call putc
    addi a0, zero, 0x0D
    call putc
    addi a0, zero, 0x0A
    call putc
    jal zero, Term
OTHER:
    addi a0, zero, 0x0D
    call putc
    addi a0, zero, 0x0A
    call putc
    addi a0, zero, 'n'
    call putc
    addi a0, zero, 'o'
    call putc
    addi a0, zero, 't'
    call putc
    addi a0, zero, ' '
    call putc
    addi a0, zero, 'f'
    call putc
    addi a0, zero, 'o'
    call putc
    addi a0, zero, 'u'
    call putc
    addi a0, zero, 'n'
    call putc
    addi a0, zero, 'd'
    call putc
    addi a0, zero, 0x0A
    call putc
    addi a0, zero, 0x0D
    call putc
    jal zero, Term
