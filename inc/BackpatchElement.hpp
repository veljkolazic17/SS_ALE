#pragma once
class Section;

#define RELOCATION  0
#define UNDEFINED   2
typedef unsigned char ACTION;

struct BackpatchElement{
    int offset;
    ACTION action; 
    Section* section;
};