#include "../inc/Memory.hpp"
#include <stdlib.h>

Memory::Memory(){
    this->memory = (char*)malloc(65536);
}

char& Memory::operator[](short index){
    return this->memory[index];
}