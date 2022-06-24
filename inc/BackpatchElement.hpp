#pragma once
class Section;

#define UNDEFINED       1
#define R_X86_64_16     2
#define R_X86_64_16S    4
#define R_X86_64_PLT16  8
#define R_X86_64_PC16   16

typedef unsigned char ACTION;
typedef unsigned char RELOCATION_TYPE;

struct BackpatchElement{
    int offset;
    ACTION action; 
    Section* section;
};