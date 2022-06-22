#include "../inc/SymbolTableElement.hpp"


SymbolTableElement::SymbolTableElement(
    char num,
    long value,
    int size,
    long offset,
    SymbolTableEntryType type,
    Binding binding,
    int Ndx,
    Section* section,
    std::string symbolName
){
    this->num = num;
    this->value = value;
    this->size = size;
    this->offset = offset;
    this->type = type;
    this->binding = binding;
    this->section = section;
    this->Ndx = Ndx;
    this->symbolName = symbolName;

    this->flink = new std::vector<BackpatchElement>();
}

char SymbolTableElement::getNum(){
    return this->num;
}
void SymbolTableElement::setNum(char num){
    this->num = num;
}

long SymbolTableElement::getValue(){
    return this->value;
}
void SymbolTableElement::setValue(long value){
    this->value = value;
}

int SymbolTableElement::getSize(){
    return this->size;
}
void SymbolTableElement::setSize(int size){
    this->size = size;
}

long SymbolTableElement::getOffset(){
    return this->offset;
}
void SymbolTableElement::setOffset(long offset){
    this->offset = offset;
}

SymbolTableEntryType SymbolTableElement::getType(){
    return this->type;
}
void SymbolTableElement::setType(SymbolTableEntryType type){
    this->type = type;
}

Binding SymbolTableElement::getBinding(){
    return this->binding;
}
void SymbolTableElement::setBinding(Binding binding){
    this->binding = binding;
}

Section* SymbolTableElement::getSection(){
    return this->section;
}
void SymbolTableElement::setSection(Section* section){
    this->section = section;
}

bool SymbolTableElement::getDefined(){
    return this->defined;
}
void SymbolTableElement::setDefined(bool defined){
    this->defined = defined;
}

std::string SymbolTableElement::getSymbolName(){
    return this->symbolName;
}
void SymbolTableElement::setSymbolName(std::string symbolName){
    this->symbolName = symbolName;
}

int SymbolTableElement::getNDX(){
    return this->Ndx;
}

void SymbolTableElement::setNDX(int Ndx){
    this->Ndx = Ndx;
}

void SymbolTableElement::backpatch(BackpatchElement backpatchElement){
    this->flink->push_back(backpatchElement);
}