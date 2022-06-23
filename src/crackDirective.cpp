#include "../inc/Assembler.hpp"

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
        crackWORD(directive);
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
        for(int j = 0;j<symbolTableSize;j++){
            if(this->symbolTable->at(j)->getSymbolName() == directive->getSymbolList()->at(i)->getSymbol()){
                this->symbolTable->at(j)->setBinding(GLOB);
                found = true;
                break;
            }
        }
        if(!found){
            SymbolTableElement* symbolTableElement = new SymbolTableElement(
                this->entry,
                0,
                0,
                0,
                NOTYP,
                GLOB,
                UND,
                nullptr,
                directive->getSymbolList()->at(i)->getSymbol()
            );
            entry++;
            this->symbolTable->push_back(symbolTableElement);
        }
    }
}

void Assembler::crackEXTERN(Directive* directive){
    int symbolListSize = directive->getSymbolList()->size();
    int symbolTableSize = this->symbolTable->size();

    for(int i = 0;i<symbolListSize;i++){
        bool found = false;
        for(int j = 0;j<symbolTableSize;j++){
            if(this->symbolTable->at(j)->getSymbolName() == directive->getSymbolList()->at(i)->getSymbol()){
                this->symbolTable->at(j)->setBinding(GLOB);
                found = true;
                break;
            }
        }
        if(!found){
            SymbolTableElement* symbolTableElement = new SymbolTableElement(
                this->entry,
                0,
                0,
                0,
                NOTYP,
                GLOB,
                UND,
                nullptr,
                directive->getSymbolList()->at(i)->getSymbol()
            );
            entry++;
            this->symbolTable->push_back(symbolTableElement);
        }
    }
}

void Assembler::crackSECTION(Directive* directive){ 
    this->currentSection = new Section(
        directive->getSectionName()
    );
    
    this->sections->push_back(this->currentSection);
    SymbolTableElement* symbolTableElement = new SymbolTableElement(
        entry,
        0,
        0,
        0,
        SCTN,
        LOC,
        entry,
        currentSection,
        currentSection->getSectionName()
    );
    this->currentSection->setSymbolTableEntry(symbolTableElement);
    entry++;
    this->symbolTable->push_back(symbolTableElement);
}

void Assembler::crackWORD(Directive* directive){
    int symbolListSize = directive->getSymbolList()->size();
    int symbolTableSize = this->symbolTable->size();

    for(int i = 0;i<symbolListSize;i++){

        SymbolListElement* currentSymbolListElement = directive->getSymbolList()->at(i);
        int currentLocationCounter = this->currentSection->getLocationCounter();
        
        if(currentSymbolListElement->getSymbolListElementType() == LITERAL_TYPE){
            int literal = currentSymbolListElement->getLiteral();
            this->currentSection->setDataByOffsetMem(currentLocationCounter,(char*)(&literal),2);
            this->currentSection->setLocationCounter(
                this->currentSection->getLocationCounter()+2
            );
        }else{
            bool found = false;

            SymbolTableElement* symbolToPatch;

            for(int j = 0;j<symbolTableSize;j++){
                if(this->symbolTable->at(j)->getSymbolName() == directive->getSymbolList()->at(i)->getSymbol()){
                    symbolToPatch = this->symbolTable->at(j);
                    found = true;
                    break;
                }
            }
            if(!found){
                symbolToPatch = new SymbolTableElement(
                    this->entry,
                    0,
                    0,
                    0,
                    NOTYP,
                    LOC,
                    UND,
                    nullptr,
                    directive->getSymbolList()->at(i)->getSymbol()
                );
                entry++;
                this->symbolTable->push_back(symbolToPatch);
            }
            symbolToPatch->backpatch({this->currentSection->getLocationCounter(),RELOCATION,this->currentSection});
            
            this->currentSection->setDataByOffsetByte(currentLocationCounter,0,2);
            this->currentSection->setLocationCounter(
                this->currentSection->getLocationCounter()+2
            );
        }
    }
}

void Assembler::crackSKIP(Directive* directive){
    int currentLocationCounter = this->currentSection->getLocationCounter();
    int directiveLiteral = directive->getLiteral();
    this->currentSection->setDataByOffsetByte(currentLocationCounter,0,directiveLiteral);
    this->currentSection->setLocationCounter(
        currentLocationCounter + directiveLiteral
    );
    
}

void Assembler::crackEND(Directive* directive){
    this->ASMSTATE = END;
    this->currentSection = nullptr;
}