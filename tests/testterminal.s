.section .text
.word 6,6,KEYBOARD
ldr r6, $0xFEFE
ldr r1,$0
BEGIN:
ldr r2,$1
add r1,r2
jmp BEGIN
END:
halt

.section .keyboard
KEYBOARD:
ldr r2, 0xFF02
ldr r1, $11
cmp r1,r2
jeq END
str r2,0xFF00
iret