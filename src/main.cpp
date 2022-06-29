#include "../misc/inc/Lines.hpp"
#include "../inc/Assembler.hpp"
#include "../inc/Emulator.hpp"
#include <iostream>
extern int yyparse();
extern FILE* yyin;

Lines* lineVec;

int main(int argc, char** argv){
    yyin = fopen("../test.s","r");
    yyparse();
    int size = lineVec->getLineSize();
    
    Assembler assembler;
    Emulator emulator;

//     assembler.crack(lineVec);
//     assembler.backpatch();
//     assembler.objdump();
//     assembler.createSElf("../misc/main.o");

    emulator.start("../KURAC.txt");

}