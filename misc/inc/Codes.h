#pragma once
typedef unsigned char OPCODE;
typedef unsigned char ADDRMODE;
typedef unsigned char UPMODE;
typedef unsigned char INSLEN;

extern OPCODE   OPCODES[];
extern ADDRMODE ADDRMODES[];
extern UPMODE   UPMODES[];
extern INSLEN   INSLENS[];

#define IMMED       0b0000
#define REGDIR      0b0001
#define REGDIRPOM   0b0101
#define REGINDIR    0b0010
#define REGINDPOM   0b0011
#define MEM         0b0100