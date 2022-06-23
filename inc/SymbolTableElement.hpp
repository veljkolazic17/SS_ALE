#pragma once
#include "../misc/inc/Types.h"
#include "../inc/BackpatchElement.hpp"
#include<vector>
#include<string>
class Section;
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

        void backpatch(BackpatchElement);

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
        std::vector<BackpatchElement>* flink = nullptr;
};