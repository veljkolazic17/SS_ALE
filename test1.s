.extern f
.section .text
ldr r1,	 %b
.skip 3
b: .word 9
.skip 8
jmp c
jmp %f

.section .cica
.skip 1


.section .baba
.skip 8	
c:
