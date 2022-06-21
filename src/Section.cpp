#include "../inc/Section.hpp"
#include <string.h>

Section::Section(char index, std::string sectionName){
    this->index = index;
    this->sectionName = sectionName;
}

int Section::getLocationCounter(){
    return this->locationCounter;
}

char Section::getIndex(){
    return this->index;
}

std::string Section::getSectionName(){
    return this->sectionName;
}

void Section::setLocationCounter(int locationCounter){
    this->locationCounter = locationCounter;
}

void Section::setDataByOffset(int offset, char* data, size_t size){
    memcpy(this->data+offset, data, size);
}


