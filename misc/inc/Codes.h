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

#define IP          7
#define SP          6
#define PSW         8

#define RESET       0
#define INVALID     1
#define TIMER       2
#define TERMINAL    3

typedef short REGISTER;
typedef unsigned short SYSREG;
typedef bool INTERRUPT;
typedef unsigned char BYTE;
typedef unsigned char * MEMORY;
typedef unsigned char MODE;
typedef short OPERAND;
typedef short SOURCE;

#define FZERO        1
#define FOVERFLOW    2
#define FCARRY       4
#define FNEGATIVE    8
#define FTIMER       8192
#define FTERMINAL    16384
#define FINTERRUPT    32768