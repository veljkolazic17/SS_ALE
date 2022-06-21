#include "../inc/Assembler.hpp"

Assembler::Assembler(){
    this->symbolTable = new std::vector<SymbolTableElement*>();
    this->sections = new std::vector<Section*>();
}

void Assembler::insertSection(Section* section){
    this->sections->push_back(section);
}

void Assembler::objdump(){

}

void Assembler::crack(Lines* lines){
    int size = lines->getLineSize();
    for(int i = 0;i<size;i++){
        this->crackLine(lines->getLine(i));
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
        // TODO Implementirati insertInstruction !!!
    }
}

void Assembler::insertDirective(Directive* directive){
    switch (directive->getDirectiveType())
    {
    case GLOBAL_TYPE:
        crackGLOBAL(directive);
        break;
    case EXTERN_TYPE:
        crackEXTERN(directive);
        break;
    case SECTION_TYPE:
        crackSECTION(directive);
        break;
    case WORD_TYPE:
        crackSECTION(directive);
        break;
    case SKIP_TYPE:
        crackSKIP(directive);
        break;
    case END_TYPE:
        crackEND(directive);
        break;
    }
}

void Assembler::crackGLOBAL(Directive* directive){
    int symbolListSize = directive->getSymbolList()->size();
    int symbolTableSize = this->symbolTable->size();
    for(int i = 0;i<symbolListSize;i++){
        bool found = false;
        for(int j = 0;j<symbolListSize;j++){
            if(this->symbolTable->at(j)->getSymbolName() == directive->getSymbolList()->at(i)->getSymbol()){
                this->symbolTable->at(j)->setBinding(GLOB);
                found = true;
                break;
            }
        }
        if(!found){
            SymbolTableElement* symbolTableElement = new SymbolTableElement(
                this->entry++,
                0,
                0,
                0,
                NOTYP,
                GLOB,
                UND,
                nullptr,
                directive->getSymbolList()->at(i)->getSymbol()
            );
            this->symbolTable->push_back(symbolTableElement);
        }
    }
}

void Assembler::crackEXTERN(Directive* directive){
    int symbolListSize = directive->getSymbolList()->size();
    for(int i = 0;i<symbolListSize;i++){
        SymbolTableElement* symbolTableElement = new SymbolTableElement(
            this->entry++,
            0,
            0,
            0,
            NOTYP,
            GLOB,
            UND,
            nullptr,
            directive->getSymbolList()->at(0)->getSymbol()
        );
    this->symbolTable->push_back(symbolTableElement);
    }
}

void Assembler::crackSECTION(Directive* directive){
    this->currentSection = new Section(
        entry,
        directive->getSymbolList()->at(0)->getSymbol()
    );
    this->sections->push_back(this->currentSection);

    SymbolTableElement* symbolTableElement = new SymbolTableElement(
        entry,
        0,
        0,
        0,
        SCTN,
        LOC,
        entry++,
        currentSection,
        currentSection->getSectionName()
    );
    this->symbolTable->push_back(symbolTableElement);
}

void Assembler::crackWORD(Directive* directive){

}

void Assembler::crackSKIP(Directive* directive){

}

void Assembler::crackEQU(Directive* directive){

}

void Assembler::crackEND(Directive* directive){

}

void Assembler::insertLabel(Label* label){

}