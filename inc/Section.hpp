#pragma once
#include "./SymbolTableElement.hpp"
#include "./Section.hpp"
#include<string>

class Section{
    public:
        Section(std::string);
        std::string getSectionName();
        int getLocationCounter();
        void setLocationCounter(int);
        void setDataByOffsetByte(int, char, size_t);
        void setDataByOffsetMem(int, char*, size_t);
        char getData(int);
        int getDataSize();
        void incrementLocationCounter(int);

        SymbolTableElement* getSymbolTableEntry();
        void setSymbolTableEntry(SymbolTableElement*);

    private:
        int locationCounter = 0;
        int dataSize = 0;
        SymbolTableElement* symbolTableEntry;
        std::string sectionName;
        char* data;
};