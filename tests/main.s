.global myStart
.global myCounter
.section myCode
myStart:
    ldr r0, $0x1
    str r0, 0xFF10
wait:
    ldr r0, myCounter
    ldr r1, $17
    cmp r0, r1
    jne wait
    halt
.section myData
myCounter:
    .word 0
.end
