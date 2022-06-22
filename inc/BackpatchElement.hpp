#pragma once
#include "./Section.hpp"

#define RELOCATION  0
#define BACKPATCH   1
#define UNDEFINED   2
typedef unsigned char ACTION;

struct BackpatchElement{
    int offset;
    ACTION action; 
    Section* section;
};