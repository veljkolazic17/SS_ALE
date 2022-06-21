#include "../misc/inc/Lines.hpp"
#include "../inc/Assembler.hpp"
#include <iostream>
extern int yyparse();
extern FILE* yyin;

Lines* lineVec;

void printLines(Lines* lines){

    int size = lines->getLineSize();
    for(int i = 0;i<size;i++){
        if(lines->getLine(i)->getLabel() != nullptr){
            std::cout<<lines->getLine(i)->getLabel()->toString()+"\n";
        }
        if(lines->getLine(i)->getDirective() != nullptr){
            std::cout<<lines->getLine(i)->getDirective()->toString()+"\n";
        }
        if(lines->getLine(i)->getInstruction() != nullptr){
        // TODO Implementirati insertInstruction !!!
        }   
    }    
}



int main(int argc, char** argv){
    yyin = fopen("../test.s","r");
    yyparse();
    int size = lineVec->getLineSize();
    
    Assembler assembler;

    assembler.crack(lineVec);
    assembler.objdump();
    // printLines(lineVec);

}