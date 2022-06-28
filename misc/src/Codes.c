#include "../inc/Codes.h"

/**
 * @brief instruction opcodes
 * 
 */
OPCODE OPCODES[] = {
    0b00000000,
    0b00010000,
    0b00100000,
    0b00110000,
    0b01000000,
    0b01010000,
    0b01010001,
    0b01010010,
    0b01010011,
    0b10110000,
    0b10100000,
    0b01100000,
    0b01110000,
    0b01110001,
    0b01110010,
    0b01110011,
    0b01110100,
    0b10000000,
    0b10000001,
    0b10000010,
    0b10000011,
    0b10000100,
    0b10010000,
    0b10010001,
    0b10100000,
    0b10110000
};
/**
 * @brief 0xFF is invalid
 * 
 */
ADDRMODE ADDRMODES[] = {
    0xFF,       //REGISTER_TYPE
    /*
        DATA OPERANDS
    */
    0b0000,     //DATA_OPERAND_LIT
    0b0000,     //DATA_OPERAND_SYM
    0b0100,     //DATA_OPERAND_MEMLIT
    0b0100,     //DATA_OPERAND_MEMSYMABS
    0b0011,     //DATA_OPERAND_MEMSYMPCREL
    0b0001,     //DATA_OPERAND_REG
    0b0010,     //DATA_OPERAND_REGMEM
    0b0011,     //DATA_OPERAND_REGMEMLIT
    0b0011,     //DATA_OPERAND_REGMEMSYM
    /*
        JUMP OPERANDS
    */
    0b0000,     //JMP_OPERAND_LIT
    0b0000,     //JMP_OPERAND_SYM
    0b0101,     //JMP_OPERAND_SYMPCREL
    0b0100,     //JMP_OPERAND_MEMLIT
    0b0100,     //JMP_OPERAND_MEMSYM
    0b0001,     //JMP_OPERAND_REG
    0b0010,     //JMP_OPERAND_REGMEM
    0b0011,     //JMP_OPERAND_REGMEMLIT
    0b0011      //JMP_OPERAND_REGMEMLIT
};
/**
 * @brief upmodes for instruction types
 * 
 */
UPMODE UPMODES[] = {
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0010,
    0b0011,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000,
    0b0000
};

INSLEN INSLENS[] = {
    0xFF,
    5,
    5,
    5,
    5,
    5,
    3,
    3,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    3,
    3,
    5,
    5
};