#pragma once
#include<string>

class Section{
    public:
        Section(char index, std::string sectionName);
        char getIndex();
        std::string getSectionName();
        int getLocationCounter();
        void setLocationCounter(int locationCounter);
        void setDataByOffsetByte(int offset, char data, size_t size);
        void setDataByOffsetMem(int offset, char* data, size_t size);
        char getData(int index);
        int getDataSize();
    private:
        int locationCounter = 0;
        int dataSize = 0;
        char index;
        std::string sectionName;
        char* data;
};