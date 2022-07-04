#include "../inc/Emulator.hpp"
#include "../inc/InputThread.hpp"
#include "../inc/OutputThread.hpp"
#include <algorithm>
#include <string.h>
#include <iostream>

Emulator::Emulator(){ 
    this->config_emulator();
}

void Emulator::config_emulator(){
    this->memory = (MEMORY)malloc(65536);
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
    Emulator::opcode_map[0b10000010] = &Emulator::handle_OR;
    Emulator::opcode_map[0b10000011] = &Emulator::handle_XOR;
    Emulator::opcode_map[0b10000100] = &Emulator::handle_TEST;
    Emulator::opcode_map[0b10010000] = &Emulator::handle_SHL;
    Emulator::opcode_map[0b10010001] = &Emulator::handle_SHR;
    Emulator::opcode_map[0b10100000] = &Emulator::handle_LDR_POP;
    Emulator::opcode_map[0b10110000] = &Emulator::handle_STR_PUSH;    

    psw = 0b0110000000000000;

    input = new InputThread(this);
    output = new OutputThread(this);
}

 void Emulator::exit_routine(){
    printf("------------------------------------------------\n"
    "Emulated processor state: psw=0b"
    PRINTF_BINARY_PATTERN_INT16
    "\nr0=0x%04X\t"
    "r1=0x%04X\t"
    "r2=0x%04X\t"
    "r3=0x%04X\n"
    "r4=0x%04X\t"
    "r5=0x%04X\t"
    "r6=0x%04X\t"
    "r7=0x%04X\n",
    PRINTF_BYTE_TO_BINARY_INT16(psw),
    (unsigned int)(registers[0] & 0xFFFF),
    (unsigned int)(registers[1] & 0xFFFF),
    (unsigned int)(registers[2] & 0xFFFF),
    (unsigned int)(registers[3] & 0xFFFF),
    (unsigned int)(registers[4] & 0xFFFF),
    (unsigned int)(registers[5] & 0xFFFF),
    (unsigned int)(registers[6] & 0xFFFF),
    (unsigned int)(registers[7] & 0xFFFF)
    );
 }

void Emulator::start(std::string filename){
    this->load(filename);



    input->start();
    output->start();

    while(!stop){
        /* instruction fetch decode and execute */
        if(this->opcode_map.find(this->memory[(SYSREG)this->registers[IP]]) == this->opcode_map.end()){
            this->registers[IP]++;
            this->interupts[INVALID] = true;
        }else{
            (this->*(this->opcode_map[this->memory[(SYSREG)this->registers[IP]]]))();
        }
        /* interrupts */
        this->handle_intr();
    }
    this->exit_routine();
    this->input->stop();
    this->output->stop();
}