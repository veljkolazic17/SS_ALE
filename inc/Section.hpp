#pragma once
#include<string>

class Section{
    public:
        Section(char index, std::string sectionName);
        int getLocationCounter();
        char getIndex();
        std::string getSectionName();
        void setLocationCounter(int locationCounter);
        void setDataByOffset(int offset, char* data, size_t size);
    private:
        int locationCounter = 0;
        char index;
        std::string sectionName;
        char* data;
};