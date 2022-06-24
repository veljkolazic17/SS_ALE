.section .text
.skip 9
e: .word 6,7
jmp %f
x: .word 1,x,8
.section .data
.skip 8
f:
jmp e


