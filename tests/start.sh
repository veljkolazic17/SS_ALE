# testira tastaturu
../assembler -o main.o main.s
../assembler -o interrupts.o interrupts.s
../linker -hex -o program.hex interrupts.o main.o
../emulator program.hex