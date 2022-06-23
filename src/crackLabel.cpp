#include "../inc/Assembler.hpp"

void Assembler::insertLabel(Label* label){

    bool found = false;
    int symbolTableSize = this->symbolTable->size();

    for(int j = 0;j<symbolTableSize;j++){
        SymbolTableElement* symbol = this->symbolTable->at(j);
        if(symbol->getSymbolName() == *label->getLabel()){
            
            symbol->setValue(this->currentSection->getLocationCounter());
            symbol->setDefined(true);
            symbol->setNDX(this->currentSection->getSymbolTableEntry()->getNum());
            symbol->setSection(this->currentSection);
            found = true;
            break;
        }
    }
    if(!found){
        SymbolTableElement* symbolTableElement = new SymbolTableElement(
            entry,
            this->currentSection->getLocationCounter(),
            0,
            0,
            NOTYP,
            LOC,
            this->currentSection->getSymbolTableEntry()->getNum(),
            this->currentSection,
            *label->getLabel()
        );
        symbolTableElement->setDefined(true);
        entry++;
        this->symbolTable->push_back(symbolTableElement);
    }  
}