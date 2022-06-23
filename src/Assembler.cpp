#include "../inc/Assembler.hpp"

Assembler::Assembler(){
    this->symbolTable = new std::vector<SymbolTableElement*>();
    this->sections = new std::vector<Section*>();
}

void Assembler::insertSection(Section* section){
    this->sections->push_back(section);
}

void Assembler::crack(Lines* lines){
    int size = lines->getLineSize();
    for(int i = 0;i<size;i++){
        this->crackLine(lines->getLine(i));
        if(this->ASMSTATE == END){
            break;
        }
    }
}

void Assembler::crackLine(Line* line){
    if(line->getLabel() != nullptr){
        this->insertLabel(line->getLabel());
    }
    if(line->getDirective() != nullptr){
        this->insertDirective(line->getDirective());
    }
    if(line->getInstruction() != nullptr){
        this->insertInstruction(line->getInstruction());
    }
}