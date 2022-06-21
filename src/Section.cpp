#include "../inc/Section.hpp"
#include <stdlib.h>
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

void Section::setDataByOffsetByte(int offset, char data, size_t size){
    if(this->dataSize == 0){
        this->dataSize = size;
        this->data = (char*)malloc(size*sizeof(char));
    }else{
        this->dataSize+=size;
        this->data = (char*)realloc(this->data, this->dataSize);
    }
    for(int i = 0;i < size;i++){
        this->data[offset+i]=data;
    }
}

void Section::setDataByOffsetMem(int offset, char* data, size_t size){
    if(this->dataSize == 0){
        this->dataSize = size;
        this->data = (char*)malloc(size*sizeof(char));
    }else{
        this->dataSize+=size;
        this->data = (char*)realloc(this->data, this->dataSize);
    }
    for(int i = 0;i < size;i++){
        this->data[offset+i]=data[i];
    }
}

char Section::getData(int index){
    return this->data[index];
}

int Section::getDataSize(){
    return this->dataSize;
}

