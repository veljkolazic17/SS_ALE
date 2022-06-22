#include "../inc/Assembler.hpp"

void Assembler::insertLabel(Label* label){
    SymbolTableElement* symbolTableElement = new SymbolTableElement(
        entry,
        this->currentSection->getLocationCounter(),
        0,
        0,
        NOTYP,
        LOC,
        this->currentSection->getIndex(),
        this->currentSection,
        *label->getLabel()
    );
    entry++;
    this->symbolTable->push_back(symbolTableElement);
}