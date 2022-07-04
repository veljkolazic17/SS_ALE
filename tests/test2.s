.global array
.global array_size

.section .text
    pop r4
    ldr r0 , $66
    add r4, r0
    xchg r4, r3
    halt

.section .data
array:
    .word 1,2,3,4,5,6,7,8,9,10

array_size:
    .word 10

.end
