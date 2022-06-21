#pragma once
#include "../misc/inc/Types.h"
#include "./inc/Section.hpp"
#include<vector>
#include<string>
#define UND -1
#define ABS -2
class SymbolTableElement{
    public:
        SymbolTableElement(char num, long value, int size, long offset,SymbolTableEntryType type, Binding binding, Section* section);    
    private:
        char num;
        long value;
        int size;
        long offset;
        SymbolTableEntryType type;
        Binding binding;
        Section* section;
        bool defined = false;
        std::vector<SymbolTableElement>* flink = nullptr;
};