#include "../misc/inc/Lines.hpp"
#include "../inc/Assembler.hpp"
#include "../inc/Emulator.hpp"
#include "../inc/Linker.hpp"
#include <iostream>
extern int yyparse();
extern FILE* yyin;

Lines* lineVec;

int main(int argc, char** argv){
   
    Linker linker;
    
    for(int i = 1; i < argc; i ++){

        char* out;
        char* in;

        if(argv[i][0] == '-' && argv[i][1] == 'o'){
            out = argv[++i];
            in = argv[++i];
        }

        yyin = fopen(in,"r");
        yyparse();
        int size = lineVec->getLineSize();
        
        Assembler assembler;
 
        assembler.crack(lineVec);
        assembler.backpatch();
        assembler.objdump();
        assembler.createSElf(out);
    }
}