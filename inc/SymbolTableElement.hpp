#pragma once
#include "../misc/inc/Types.h"
#include "../inc/Section.hpp"
#include<vector>
#include<string>
#define UND -1
#define ABS -2
class SymbolTableElement{
    public:
        SymbolTableElement(
        char num, 
        long value, 
        int size, 
        long offset,
        SymbolTableEntryType type, 
        Binding binding,
        int Ndx, 
        Section* section, 
        std::string symbolName
        );

        char getNum();
        void setNum(char);

        long getValue();
        void setValue(long);

        int getSize();
        void setSize(int);

        long getOffset();
        void setOffset(long);

        SymbolTableEntryType getType();
        void setType(SymbolTableEntryType);

        Binding getBinding();
        void setBinding(Binding);

        Section* getSection();
        void setSection(Section*);

        bool getDefined();
        void setDefined(bool);

        int getNDX();
        void setNDX(int Ndx);

        std::string getSymbolName();
        void setSymbolName(std::string);

    private:
        char num;
        long value;
        int size;
        long offset;
        SymbolTableEntryType type;
        Binding binding;
        int Ndx;
        Section* section;
        std::string symbolName;
        bool defined = false;
        std::vector<SymbolTableElement>* flink = nullptr;
};