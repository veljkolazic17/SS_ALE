.section .text
.word 8,6,KEYBOARD,TIMER
ldr r6, $0xFEFE
ldr r1,$3
str r1, 0xFF10
BEGIN:
jmp BEGIN
END:
halt

.section .keyboard
KEYBOARD:
ldr r2, 0xFF02
ldr r1, $10
cmp r1,r2
jeq END
str r2,0xFF00
iret



TIMER:
ldr r1, $65
str r1, 0xFF00
iret

.end
