#pragma once
#include "./SELF.h"
class Section;

typedef unsigned char ACTION;
typedef unsigned char RELOCATION_TYPE;

struct BackpatchElement{
    int offset;
    ACTION action; 
    Section* section;
};