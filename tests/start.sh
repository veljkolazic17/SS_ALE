ASSEMBLER=../assembler
LINKER=../linker
# EMULATOR=./emulator

# ${ASSEMBLER} -o main.o main.s
# ${ASSEMBLER} -o ivt.o ivt.s
# ${ASSEMBLER} -o isr_reset.o isr_reset.s
# ${ASSEMBLER} -o isr_terminal.o isr_terminal.s
# ${ASSEMBLER} -o isr_timer.o isr_timer.s
# ${LINKER} -hex -place=ivt@0x0000 -o program.hex main.o isr_reset.o isr_terminal.o isr_timer.o ivt.o

${ASSEMBLER} -o test1.o test1.s -objdump test1dump
${ASSEMBLER} -o test2.o test2.s -objdump test2dump
${LINKER} -hex -o test_program.hex test1.o test2.o