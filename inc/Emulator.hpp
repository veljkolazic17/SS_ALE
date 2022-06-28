#pragma once
#include "../inc/Memory.hpp"
#include <unordered_map>
#include<string>
#include <fstream>

#define PC          7
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

#define FZERO        1
#define FOVERFLOW    2
#define FCARRY       4
#define FNEGATIVE    8
#define FTIMER       8192
#define FTERMINAL    16384
#define FINTERRUPT    32768

class Emulator{

    public:

        Emulator();
        void start(std::string);
        void load(std::string);
    
    private:
        void config_emulator();

        void handle_intr();

        void handle_HALT();
        void handle_INT();
        void handle_IRET();
        void handle_CALL();
        void handle_RET();
        void handle_JMP();
        void handle_JEQ();
        void handle_JNE();
        void handle_JGT();
        void handle_XCHG();
        void handle_ADD();
        void handle_SUB();
        void handle_MUL();
        void handle_DIV();
        void handle_CMP();
        void handle_NOT();
        void handle_AND();
        void handle_OR();
        void handle_XOR();
        void handle_TEST();
        void handle_SHL();
        void handle_SHR();
        void handle_LDR_POP();
        void handle_STR_PUSH();

        void handle_operand(bool,char);
        bool handle_upmode(BYTE);

        std::unordered_map<char, void(Emulator::*)()> opcode_map;

        void updatePSW(REGISTER,REGISTER);

        MEMORY memory;
        bool stop = false;

        REGISTER psw;
        REGISTER registers[8];
        INTERRUPT system_interupts[4] = {false,false,false,false};
        INTERRUPT user_interputs[4] = {false,false,false,false};

};