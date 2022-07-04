#pragma once
#include <unordered_map>
#include<string>
#include <fstream>
#include "../misc/inc/Codes.h"

class InputThread;
class OutputThread;

/* macro for prinf binary */
#define PRINTF_BINARY_PATTERN_INT8 "%c%c%c%c%c%c%c%c"
#define PRINTF_BYTE_TO_BINARY_INT8(i)    \
    (((i) & 0x80ll) ? '1' : '0'), \
    (((i) & 0x40ll) ? '1' : '0'), \
    (((i) & 0x20ll) ? '1' : '0'), \
    (((i) & 0x10ll) ? '1' : '0'), \
    (((i) & 0x08ll) ? '1' : '0'), \
    (((i) & 0x04ll) ? '1' : '0'), \
    (((i) & 0x02ll) ? '1' : '0'), \
    (((i) & 0x01ll) ? '1' : '0')

#define PRINTF_BINARY_PATTERN_INT16 \
    PRINTF_BINARY_PATTERN_INT8              PRINTF_BINARY_PATTERN_INT8
#define PRINTF_BYTE_TO_BINARY_INT16(i) \
    PRINTF_BYTE_TO_BINARY_INT8((i) >> 8),   PRINTF_BYTE_TO_BINARY_INT8(i)
#define PRINTF_BINARY_PATTERN_INT32 \
    PRINTF_BINARY_PATTERN_INT16             PRINTF_BINARY_PATTERN_INT16
#define PRINTF_BYTE_TO_BINARY_INT32(i) \
    PRINTF_BYTE_TO_BINARY_INT16((i) >> 16), PRINTF_BYTE_TO_BINARY_INT16(i)
#define PRINTF_BINARY_PATTERN_INT64    \
    PRINTF_BINARY_PATTERN_INT32             PRINTF_BINARY_PATTERN_INT32
#define PRINTF_BYTE_TO_BINARY_INT64(i) \
    PRINTF_BYTE_TO_BINARY_INT32((i) >> 32), PRINTF_BYTE_TO_BINARY_INT32(i)



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

        void exit_routine();

        void updatePSW(REGISTER,REGISTER);

        MEMORY memory;
        bool stop = false;

        SYSREG psw;
        REGISTER registers[8] = {0,0,0,0,0,0,0,0};
        INTERRUPT interupts[8] = {false,false,false,false,false,false,false,false};

        InputThread* input;
        OutputThread* output;


    friend InputThread;
    friend OutputThread;
};