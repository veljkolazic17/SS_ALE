.global labela3
.extern labela2
.section .text
jmp %labela5
ldr r0, %labela1
ldr r0,labela1
ldr r0, [r0 + 0x13]
jmp *[r1 + labela1]
labela3:
.section .data
jmp labela1
add r1,r1
labela1:
labela5:
xor r1, r1
.end
