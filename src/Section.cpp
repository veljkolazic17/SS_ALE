#include "../inc/Section.hpp"
#include <stdlib.h>
#include <string.h>

Section::Section(std::string sectionName){
    this->sectionName = sectionName;
}

 SymbolTableElement* Section::getSymbolTableEntry(){
     return this->symbolTableEntry;
 }

void Section::setSymbolTableEntry(SymbolTableElement* symbolTableEntry){
    this->symbolTableEntry = symbolTableEntry;
}

int Section::getLocationCounter(){
    return this->locationCounter;
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
    this->symbolTableEntry->setSize(this->dataSize);
}

void Section::setDataByOffsetRMem(int offset, char* data, size_t size){
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
    this->symbolTableEntry->setSize(this->dataSize);
}

void Section::setDataByOffsetMem(int offset, char* data, size_t size){
    if(this->dataSize == 0){
        this->dataSize = size;
        this->data = (char*)malloc(size*sizeof(char));
    }else{
        this->dataSize+=size;
        this->data = (char*)realloc(this->data, this->dataSize);
    }
    memcpy(this->data+offset,data,size);
    this->symbolTableEntry->setSize(this->dataSize);
}

void Section::insertDataByOffsetMem(int offset, char* data, size_t size){
    memcpy(this->data+offset,data,size);
}

char Section::getData(int index){
    return this->data[index];
}

int Section::getDataSize(){
    return this->dataSize;
}

void Section::incrementLocationCounter(int increment){
    this->locationCounter+=increment;
}

RelocationTableElement Section::getRelocationTableElement(int index){
    return this->relocationTable.at(index);
}

void Section::insertRelocationTableElement(RelocationTableElement relocationTableElement){
    this->relocationTable.push_back(relocationTableElement);
}

int Section::getRelocationTableSize(){
    return this->relocationTable.size();
}