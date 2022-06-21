#!/bin/bash
lex Lexer.l
bison Parser.y
g++ -g -o executable ./src/* ../src/*
./executable