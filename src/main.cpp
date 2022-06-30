#include "../misc/inc/Lines.hpp"
#include "../inc/Assembler.hpp"
#include "../inc/Emulator.hpp"
#include "../inc/Linker.hpp"
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
    Linker linker;

    assembler.crack(lineVec);
    assembler.backpatch();
    assembler.objdump();
    assembler.createSElf("../misc/main.o");

    // emulator.start("../KURAC.txt");

    char* test[1];
    test[0] = (char*)std::string("../misc/main.o").c_str();


    // linker.load(1,test);

    linker.link(1,test);
    linker._hex("out.hex");

    // linker.load(1,test);

}