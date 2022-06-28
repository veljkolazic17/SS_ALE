.section .text
.skip 9
e: .word 6,7
jmp %f
x: jmp f
.section .data
.skip 8
f:
jmp e


