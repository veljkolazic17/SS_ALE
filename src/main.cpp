#include "../misc/inc/Lines.hpp"
#include "../inc/Assembler.hpp"
#include "../inc/Emulator.hpp"
#include "../inc/Linker.hpp"
#include <iostream>
extern int yyparse();
extern FILE* yyin;

Lines* lineVec;

int main(int argc, char** argv){
   

    // emulator.start("../KURAC.txt");

    Linker linker;
    char* test[2];
    test[0] = (char*)std::string("../misc/main1.o").c_str();
    test[1] = (char*)std::string("../misc/main2.o").c_str();

    char* in[2];
    in[0] = (char*)std::string("../test1.s").c_str();
    in[1] = (char*)std::string("../test2.s").c_str();

    for(int i = 0; i < 2; i ++){
         yyin = fopen(in[i],"r");
        yyparse();
        int size = lineVec->getLineSize();
        
        Assembler assembler;
 
        assembler.crack(lineVec);
        assembler.backpatch();
        assembler.objdump();
        assembler.createSElf(test[i]);
    }


    // linker.load(1,test);

    linker.link(2,test);
    linker._hex("out.hex");

    // linker.load(1,test);

}