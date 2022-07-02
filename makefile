CC = g++
CFLAGS = -g

filenames := assembler linker
files := $(strip $(foreach f,$(filenames),$(wildcard $(f))))

ASSEMBLER = assembler
LINKER = linker

ASSEMBLER_FILES = ./misc/src/* ./src/Assembler.cpp ./src/crack_Directive.cpp ./src/crack_Instruction.cpp ./src/crack_Label.cpp ./src/RelocationTableElement.cpp ./src/Section.cpp ./src/SymbolTableElement.cpp ./src/objdump.cpp ./src/create_SElf.cpp ./main/main_assembler.cpp
LINKER_FILES = ./misc/src/Codes.c ./src/hex.cpp ./src/linker_loader.cpp ./src/Linker.cpp ./main/main_linker.cpp

all: $(ASSEMBLER) $(LINKER)

$(ASSEMBLER): 
			$(CC) $(CFLAGS) -o $(ASSEMBLER) $(ASSEMBLER_FILES)
$(LINKER):
			$(CC) $(CFLAGS) -o $(LINKER) $(LINKER_FILES)

clean:
ifneq ($(files),)
	rm -f $(files)
endif