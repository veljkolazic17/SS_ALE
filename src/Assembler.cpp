#include "../inc/Assembler.hpp"
#include "../inc/SELF.h"
#include <string.h>
#include <stdlib.h>

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

void Assembler::backpatch(){
    int size = this->symbolTable->size();
    for(int i = 0;i<size;i++){
        this->backpatchSingle(
            this->symbolTable->at(i)
        );
    }
}

void Assembler::backpatchSingle(SymbolTableElement* symbolTableElement){
    if(symbolTableElement->getType() == SCTN)
        return;
 
    int flinkSize = symbolTableElement->getFlinkSize();
    Binding BIND = symbolTableElement->getBinding();
    //iterate over flinks
    for(int i = 0;i<flinkSize;i++){
        BackpatchElement backpatchElement = symbolTableElement->getBackpatchElement(i);
        //consider backpatching
        if(
                backpatchElement.action & UNDEFINED
            &&  symbolTableElement->getSection() == backpatchElement.section
            &&  symbolTableElement->getDefined()
        ){
            
            uint16_t Data = symbolTableElement->getValue() - 5;
            Data = Data>>8 | Data<<8;
            backpatchElement.section->insertDataByOffsetMem(
                backpatchElement.offset,
                (char*)&Data,
                2
            );
        }
        //should enter relocation table
        else{
            if(BIND == LOC){
                if(backpatchElement.action & R_X86_64_PC16){
                    backpatchElement.section->insertRelocationTableElement({
                        backpatchElement.offset,
                        -2+(int)symbolTableElement->getValue(),
                        R_X86_64_PC16,
                        symbolTableElement->getSection()->getSymbolTableEntry()
                    });
                }
                else if(backpatchElement.action & R_X86_64_16){
                    backpatchElement.section->insertRelocationTableElement({
                        backpatchElement.offset,
                        (int)symbolTableElement->getValue(),
                        R_X86_64_16,
                        symbolTableElement->getSection()->getSymbolTableEntry()
                    });
                }
            }else{
                if(backpatchElement.action & R_X86_64_PLT16){
                    backpatchElement.section->insertRelocationTableElement({
                        backpatchElement.offset,
                        -2,
                        R_X86_64_PLT16,
                        symbolTableElement
                    });
                }
                else if(backpatchElement.action & R_X86_64_16){
                    backpatchElement.section->insertRelocationTableElement({
                        backpatchElement.offset,
                        0,
                        R_X86_64_16,
                        symbolTableElement
                    });
                }
            }
        }
    }
}