#!/bin/bash
lex Lexer.l
bison Parser.y
g++ -o executable ./src/* ../src/main.cpp
./executable