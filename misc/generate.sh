#!/bin/bash
# clear
# lex Lexer.l
# bison Parser.y
g++ -g -o executable ./src/* ../src/*
./executable
# hexdump -C main.o