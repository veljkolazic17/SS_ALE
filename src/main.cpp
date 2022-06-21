#include "../misc/inc/Lines.hpp"
#include <iostream>
extern int yyparse();
extern FILE* yyin;

Lines* lineVec;

int main(int argc, char** argv){
    yyin = fopen("../test.s","r");
    yyparse();
    int size = lineVec->getLineSize();
    for(int i = 0;i<size;i++){
        std::cout<<lineVec->getLine(i)<<"\n";
    }

}