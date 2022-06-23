.section .text
jmp %labela1
ldr r0, %labela1
ldr r0,labela1
ldr r0, [r0 + 0x13]
jmp *[r1 + labela1]
.section .data
labela1:
xor r1, r1
.end
