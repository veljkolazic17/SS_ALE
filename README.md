# SS_ALE
Software includes:
  - Assembler 
  - Linker
  - Emulator

## Assembler
1. How to run assembler: `assembler [options] <input_asm_file>`  
2. Flags: 
  - `-o <output_asm_file>`  
4. Example: `./assembler -o input.o output.s`
## Linker
1. How to run linker: `linker [options] <input_file>...`
2. Flags: 
  - `-o <output_file>`
  - `–place=<section_name>@<address>`
  - `-hex`
3. Example: `./linker -hex -place=iv_table@0x0000 -place=text@0x4000 -o mem_content.hex in1.o in2.o`
## Emulator
1. How to run emulator `emulator <input_hex_file>`
2. Example: `./emulator mem_content.hex`

More information about project can be found in ss.pdf file!
