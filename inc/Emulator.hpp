#pragma once
#include <unordered_map>
#include<string>
#include <fstream>
#include "../misc/inc/Codes.h"

class Emulator{

    public:

        Emulator();
        void start(std::string);

    
    private:
        void config_emulator();
        void load(std::string);

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

        bool scoop_operand(OPERAND*, INSLEN*,SOURCE**);
        BYTE get_upmode();
        int check_rd(REGISTER*, BYTE*);
        int check_rs(REGISTER*, BYTE*);

        std::unordered_map<char, void(Emulator::*)()> opcode_map;

        void updatePSW(REGISTER,REGISTER);

        MEMORY memory;
        bool stop = false;

        REGISTER psw = 0;
        REGISTER registers[8] = {0,0,0,0,0,0,0,0};
        INTERRUPT system_interupts[4] = {false,false,false,false};
        INTERRUPT user_interputs[4] = {false,false,false,false};

};