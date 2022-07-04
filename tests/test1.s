.extern array
.extern array_size
.section .text

.word 2

ldr r2, $2
ldr r0, $0 # pomeraj

ldr r5, [r0 + array_size]

ldr r4, $0 # zbir

for:
    ldr r2, $2
    ldr r3, [r0 + array]
    add r4,r3
    add r0, r2

    ldr r2, $1
    sub r5, r2
    ldr r2, $0
    

    cmp r5, r2
    jne %for

    push r4
.end
