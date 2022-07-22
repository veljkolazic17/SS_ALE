#include "../inc/Codes.h"

/**
 * @brief instruction opcodes
 * 
 */
OPCODE OPCODES[] = {
    0b00000000,     // HALT
    0b00010000,     // INT
    0b00100000,     // IRET
    0b00110000,     // CALL
    0b01000000,     // RET
    0b01010000,     // JMP
    0b01010001,     // JEQ
    0b01010010,     // JNE
    0b01010011,     // JGT
    0b10110000,     // PUSH
    0b10100000,     // POP
    0b01100000,     // XCHG
    0b01110000,     // ADD
    0b01110001,     // SUB
    0b01110010,     // MUL
    0b01110011,     // DIV
    0b01110100,     // CMP
    0b10000000,     // NOT
    0b10000001,     // AND
    0b10000010,     // OR
    0b10000011,     // XOR
    0b10000100,     // TEST
    0b10010000,     // SHL
    0b10010001,     // SHR
    0b10100000,     // LDR
    0b10110000      // STR
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
    0b0001,
    0b0100,
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

unsigned short switch_bytes(unsigned short word){
    return (word)>>8 | (word)<<8;
}