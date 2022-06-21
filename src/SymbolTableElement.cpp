#include "../inc/SymbolTableElement.hpp"

SymbolTableElement::SymbolTableElement(
    char num,
    long value,
    int size,
    long offset,
    SymbolTableEntryType type,
    Binding binding,
    Section* section
){
    this->num = num;
    this->value = value;
    this->size = size;
    this->offset = offset;
    this->type = type;
    this->binding = binding;
    this->section = section;
}