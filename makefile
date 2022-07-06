CC = g++
CFLAGS = -g

filenames := assembler linker emulator
files := $(strip $(foreach f,$(filenames),$(wildcard $(f))))

ASSEMBLER = assembler
LINKER = linker
EMULATOR = emulator

ASSEMBLER_FILES = ./misc/src/* ./src/Assembler.cpp ./src/crack_Directive.cpp ./src/crack_Instruction.cpp ./src/crack_Label.cpp ./src/RelocationTableElement.cpp ./src/Section.cpp ./src/SymbolTableElement.cpp ./src/objdump.cpp ./src/create_SElf.cpp ./main/main_assembler.cpp
LINKER_FILES = ./misc/src/Codes.c ./src/hex.cpp ./src/linker_loader.cpp ./src/Linker.cpp ./main/main_linker.cpp
EMULATOR_FILES = ./misc/src/Codes.c ./src/Emulator.cpp ./src/handler_helpers.cpp ./src/emulator_loader.cpp ./src/instruction_handlers.cpp ./main/main_emulator.cpp ./src/Thread.cpp ./src/InputThread.cpp ./src/OutputThread.cpp ./src/Timer.cpp

all: $(ASSEMBLER) $(LINKER) $(EMULATOR)

$(ASSEMBLER): 
			$(CC) $(CFLAGS) -o $(ASSEMBLER) $(ASSEMBLER_FILES)
$(LINKER):
			$(CC) $(CFLAGS) -o $(LINKER) $(LINKER_FILES)
$(EMULATOR):
			$(CC) $(CFLAGS) -pthread -o $(EMULATOR) $(EMULATOR_FILES)

clean:
ifneq ($(files),)
	rm -f $(files)
endif