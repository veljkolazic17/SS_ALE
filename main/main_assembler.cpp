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

        char* out = 0;
        char* in = 0;
        char* objdump_filename = 0;


        std::string arg(argv[i]);

        if(arg == "-o"){
            out = argv[++i];
            in = argv[++i];
        }else{
            objdump_filename = argv[++i];
        }

        yyin = fopen(in,"r");
        yyparse();
        int size = lineVec->getLineSize();
        
        Assembler assembler;
 
        assembler.crack(lineVec);
        assembler.backpatch();
        if(objdump_filename){
            assembler.objdump(objdump_filename);
        }  
        assembler.createSElf(out);
    }
}