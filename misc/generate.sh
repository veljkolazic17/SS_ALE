#!/bin/bash
# clear
# lex Lexer.l
# bison Parser.y
g++ -g -o executable ./src/* ../src/* ../pmains/main_assembler.cpp
# ./executable
# hexdump -C main.o