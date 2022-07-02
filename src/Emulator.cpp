#include "../inc/Emulator.hpp"
#include <algorithm>
#include <string.h>
#include <iostream>

Emulator::Emulator(){
    this->memory = (MEMORY)malloc(65536);
    this->config_emulator();
}

void Emulator::config_emulator(){
    this->opcode_map = std::unordered_map<char, void(Emulator::*)()>();

    Emulator::opcode_map[0b00000000] = &Emulator::handle_HALT;
    Emulator::opcode_map[0b00010000] = &Emulator::handle_INT;
    Emulator::opcode_map[0b00100000] = &Emulator::handle_IRET;
    Emulator::opcode_map[0b00110000] = &Emulator::handle_CALL;
    Emulator::opcode_map[0b01000000] = &Emulator::handle_RET;
    Emulator::opcode_map[0b01010000] = &Emulator::handle_JMP;
    Emulator::opcode_map[0b01010001] = &Emulator::handle_JEQ;
    Emulator::opcode_map[0b01010010] = &Emulator::handle_JNE;
    Emulator::opcode_map[0b01010011] = &Emulator::handle_JGT;
    Emulator::opcode_map[0b01100000] = &Emulator::handle_XCHG;
    Emulator::opcode_map[0b01110000] = &Emulator::handle_ADD;
    Emulator::opcode_map[0b01110001] = &Emulator::handle_SUB;
    Emulator::opcode_map[0b01110010] = &Emulator::handle_MUL;
    Emulator::opcode_map[0b01110011] = &Emulator::handle_DIV;
    Emulator::opcode_map[0b01110100] = &Emulator::handle_CMP;
    Emulator::opcode_map[0b10000000] = &Emulator::handle_NOT;
    Emulator::opcode_map[0b10000001] = &Emulator::handle_AND;
    Emulator::opcode_map[0b10000001] = &Emulator::handle_AND;
    Emulator::opcode_map[0b10000010] = &Emulator::handle_OR;
    Emulator::opcode_map[0b10000011] = &Emulator::handle_XOR;
    Emulator::opcode_map[0b10000100] = &Emulator::handle_TEST;
    Emulator::opcode_map[0b10010000] = &Emulator::handle_SHL;
    Emulator::opcode_map[0b10010001] = &Emulator::handle_SHR;
    Emulator::opcode_map[0b10100000] = &Emulator::handle_LDR_POP;
    Emulator::opcode_map[0b10110000] = &Emulator::handle_STR_PUSH;    
}



void Emulator::start(std::string filename){
    load(filename);

    while(!stop){
        /* instruction fetch decode and execute */
        if(this->opcode_map.find(this->memory[(SYSREG)this->registers[IP]]) == this->opcode_map.end()){
            this->registers[IP]++;
            this->system_interupts[INVALID] = true;
        }else{
            (this->*(this->opcode_map[this->memory[(SYSREG)this->registers[IP]]]))();
        }
        /* interrupts */
        this->handle_intr();
    }
}


