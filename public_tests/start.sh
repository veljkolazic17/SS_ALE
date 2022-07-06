../assembler -o interrupts.o interrupts.s
../assembler -o main.o main.s
../linker -hex -place=ivt@0x0000 -o program.hex interrupts.o main.o
../emulator program.hex