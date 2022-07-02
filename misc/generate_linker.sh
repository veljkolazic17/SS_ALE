#!/bin/bash
# clear
# lex Lexer.l
# bison Parser.y
g++ -g -o linker ./src/Codes.c ../src/hex.cpp ../src/linker_loader.cpp ../src/Linker.cpp ../pmains/main_linker.cpp
# ./executable
# hexdump -C main.o