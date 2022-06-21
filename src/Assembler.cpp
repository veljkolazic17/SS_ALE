#include "../inc/Assembler.hpp"

Assembler::Assembler(){
    this->symbolTable = new std::vector<SymbolTableElement*>();
}

void Assembler::insertSection(Section* section){
    this->sections->push_back(section);
}

void Assembler::insertDirective(Directive* directive){
    switch (directive->getDirectiveType())
    {
    case GLOBAL_TYPE:
        crackGLOBAL(directive);
        break;
    case EXTERN_TYPE:
        break;
    case SECTION_TYPE:
        break;
    case WORD_TYPE:
        break;
    case SKIP_TYPE:
        break;
    case EQU_TYPE:
        break;
    case END_TYPE:
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
        entry++,
        directive->getSymbolList()->at(0)->getSymbol()
    );
    this->sections->push_back(this->currentSection);
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