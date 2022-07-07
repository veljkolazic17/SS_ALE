.section .text
.word START,ERROR
.skip 4
START:
    ldr r1, $66 # should load 66 if opcode is good
    halt
ERROR:
    ldr r4,$66 # should load 66 if opcode is bad
    halt
.end
