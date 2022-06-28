#include "../inc/Emulator.hpp"
#include "../misc/inc/Codes.h"
#include "../misc/inc/Types.h"

void Emulator::handle_HALT(){
    stop = true;
    registers[PC]++;
}
void Emulator::handle_INT(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    if(!(
            regD&0x0F == 0x0F
        &&  regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    registers[SP]-=2;
    *((short*)(memory + (SYSREG)registers[SP])) = psw;
    registers[PC] = *((short*)(memory + ((SYSREG)registers[regD]%8)*2));
}
void Emulator::handle_IRET(){
    psw = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
    registers[PC] = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
}
void Emulator::handle_CALL(){
    if(!handle_upmode(0b0000)){
        return;
    }
    handle_operand(false,PC);
    registers[SP]-=2;
    *((short*)(memory + (SYSREG)registers[SP])) = registers[PC];
}
void Emulator::handle_RET(){
    registers[PC] = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
}
void Emulator::handle_JMP(){
    if(!handle_upmode(0b0000)){
        return;
    }
    handle_operand(true,PC);
}
void Emulator::handle_JEQ(){
    if(!handle_upmode(0b0000)){
        return;
    }
    handle_operand(psw & FZERO,PC);
}
void Emulator::handle_JNE(){
    if(!handle_upmode(0b0000)){
        return;
    }
    handle_operand(!(psw & FZERO),PC);
}
void Emulator::handle_JGT(){
    if(!handle_upmode(0b0000)){
        return;
    }
    handle_operand(!((((psw&0x000F)>>3)^((psw&0x000F)>>1))|(psw&FZERO)),PC);
}
void Emulator::handle_XCHG(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    

    REGISTER temp = registers[regD];
    registers[regD] = registers[regS];
    registers[regS] = temp;

    registers[PC]++;
}
void Emulator::handle_ADD(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }

    registers[regD] = registers[regD] + registers[regS];
    registers[PC]++;
}
void Emulator::handle_SUB(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }

    registers[regD] = registers[regD] - registers[regS];
    registers[PC]++;
}
void Emulator::handle_MUL(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    registers[regD] = registers[regD] * registers[regS];
    registers[PC]++;
}
void Emulator::handle_DIV(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    registers[regD] = registers[regD]/registers[regS];
    registers[PC]++;
}
void Emulator::handle_CMP(){

}
void Emulator::handle_NOT(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    if(!(
            regD&0x0F == 0x0F
        &&  regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    registers[regD] = ~registers[regD];
    registers[PC]++;
}
void Emulator::handle_AND(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    registers[regD] = registers[regD] & registers[regS];
    registers[PC]++;
}
void Emulator::handle_OR(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    registers[regD] = registers[regD] | registers[regS];
    registers[PC]++;
}
void Emulator::handle_XOR(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    BYTE regS = regDS&0x0F;

    if(!(
             regS < 8
        &&   regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    registers[regD] = registers[regD] ^ registers[regS];
}
void Emulator::handle_TEST(){

}
void Emulator::handle_SHL(){

}
void Emulator::handle_SHR(){

}
void Emulator::handle_LDR_POP(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    if(!(
            regD&0x0F == 0x0F
        &&  regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }
    



}
void Emulator::handle_STR_PUSH(){
    BYTE regDS = memory[(SYSREG)registers[PC]];
    BYTE regD = (regDS&0xF0)>>4;
    if(!(
            regD&0x0F == 0x0F
        &&  regD < 8
    )){
        system_interupts[INVALID] = true;
        registers[PC]++;
        return;
    }


}
void Emulator::handle_operand(bool eval,char reg_input){
    SYSREG temp_pc = registers[PC];
    BYTE RegsDescr = memory[temp_pc];
    BYTE AddrMode = memory[temp_pc + 1];
    BYTE adder = 0;

    AddrMode = AddrMode & 0x0F;
    switch (AddrMode){
        case IMMED:{
            if(RegsDescr != 0xFF){
                system_interupts[INVALID] = true;
                registers[PC] += 2;
                return;
            }
            if(!eval){
                registers[PC] += 4;
                return;
            }
            SYSREG immed = *((short*)(memory + temp_pc + 2));
            immed = switch_bytes(immed);
            registers[reg_input] = immed;
            /* if not using jmp ins */
            adder = 4;
        }
        break;

        case REGDIR:{
            if(!(
                    RegsDescr&0xF0 == 0xF0
                &&  RegsDescr&0x0F < 8
            )){
                system_interupts[INVALID] = true;
                registers[PC] += 2;
                return;
            }
            if(!eval){
                registers[PC] += 2;
                return;
            }
            BYTE reg = RegsDescr&0x0F;
            SYSREG reg_val = registers[reg];
            registers[reg_input] = reg_val;
            /* if not using jmp ins */
            adder = 2;
        }
        break;

        case REGDIRPOM:{
            if(!(
                    RegsDescr&0xF0 == 0xF0
                &&  RegsDescr&0x0F < 8
            )){
                system_interupts[INVALID] = true;
                registers[PC] += 2;
                return;
            }
            if(!eval){
                registers[PC] += 4;
                return;
            }
            BYTE reg = RegsDescr&0x0F;
            SYSREG reg_val = registers[reg];
            short pom = *((short*)(memory + temp_pc + 2));
            pom = switch_bytes(pom);
            registers[reg_input] = pom + reg_val;
            /* if not using jmp ins */
            adder = 4;
        }
        break;

        case REGINDIR:{
            if(!(
                    RegsDescr&0xF0 == 0xF0
                &&  RegsDescr&0x0F < 8
            )){
                system_interupts[INVALID] = true;
                registers[PC] += 2;
                return;
            }
            if(!eval){
                registers[PC] += 2;
                return;
            }
            BYTE reg = RegsDescr&0x0F;
            SYSREG reg_val = registers[reg];
            registers[reg_input] = *((SYSREG*)(memory + reg_val));
            /* if not using jmp ins */
            adder = 2;
        }
        break;

        case REGINDIRPOM:{
            if(!(
                    RegsDescr&0xF0 == 0xF0
                &&  RegsDescr&0x0F < 8
            )){
                system_interupts[INVALID] = true;
                registers[PC] += 2;
                return;
            }
            if(!eval){
                registers[PC] += 4;
                return;
            }
            BYTE reg = RegsDescr&0x0F;
            SYSREG reg_val = registers[reg];
            short pom = *((short*)(memory + temp_pc + 2));
            pom = switch_bytes(pom);
            SYSREG mem = *((SYSREG*)(memory + pom + reg_val));
            registers[reg_input] = mem;
            /* if not using jmp ins */
            adder = 4;
        }
        break;

        case MEM:{
            if(RegsDescr != 0xFF){
                system_interupts[INVALID] = true;
                registers[PC] += 2;
                return;
            }
            if(!eval){
                registers[PC] += 4;
                return;
            }
            unsigned short val = *((short*)(memory + temp_pc + 2));
            val = switch_bytes(val);
            unsigned short _jmpaddr = *((short*)(memory + val));
            registers[reg_input] = _jmpaddr;
            /* if not using jmp ins */
            adder = 4;
        }
        break;

        default:{
            system_interupts[INVALID] = true;
            registers[PC] += 2;
            return;
        }
    }
    if(reg_input != PC){
        registers[PC] += adder;
    }
}

bool Emulator::handle_upmode(BYTE upmode){
    BYTE AddrMode = memory[(SYSREG)registers[PC]+1];
    BYTE UpMode = AddrMode >> 4;
    if(UpMode != upmode){
        system_interupts[INVALID] = true;
        registers[PC] += 2;
        return false;
    }
    return true;
}


void Emulator::updatePSW(REGISTER old_value, REGISTER new_value){

}
unsigned short switch_bytes(unsigned short word){
    return (word)>>8 | (word)<<8;
}