ASSEMBLER=../assembler
LINKER=../linker
EMULATOR=../emulator

# ${ASSEMBLER} -o main.o main.s
# ${ASSEMBLER} -o ivt.o ivt.s
# ${ASSEMBLER} -o isr_reset.o isr_reset.s
# ${ASSEMBLER} -o isr_terminal.o isr_terminal.s
# ${ASSEMBLER} -o isr_timer.o isr_timer.s
# ${LINKER} -hex -place=ivt@0x0000 -o program.hex main.o isr_reset.o isr_terminal.o isr_timer.o ivt.o

# ${ASSEMBLER} -o test1.o test1.s
# ${ASSEMBLER} -o test2.o test2.s
# ${LINKER} -hex -place=data@0x400 -place=text@0x0 -o test_program.hex test1.o test2.o
# ${EMULATOR} test_program.hex



${ASSEMBLER} -o equ_test.o equ_test.s -objdump equ.dump
${LINKER} -hex -o equ_test.hex equ_test.o
ulimit -c unlimited
${EMULATOR} equ_test.hex