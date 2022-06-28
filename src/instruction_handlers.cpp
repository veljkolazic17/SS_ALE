#include "../inc/Emulator.hpp"
#include "../misc/inc/Types.h"

void Emulator::handle_HALT(){
    stop = true;
    registers[PC]++;
}
void Emulator::handle_INT(){
    REGISTER regD;
    BYTE _regD;
    if(!(check_rd(&regD,&_regD)==0 && check_rs(0,0)==1)){
        system_interupts[INVALID] = true;
        registers[PC] += 2;
        return;
    }

    registers[SP] -= 2;
    *((short*)(memory + (SYSREG)registers[SP])) = psw;

    registers[PC] = *((SYSREG*)(memory + ((SYSREG)regD % 8)*2));
    registers[PC] += 2;
}
void Emulator::handle_IRET(){
    psw = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
    registers[PC] = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
}
void Emulator::handle_CALL(){
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        registers[SP] -= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = registers[PC] + inslen;
        registers[PC] = operand;
    }
    else{
        system_interupts[INVALID] = true;
        registers[PC] += inslen;
    }
}
void Emulator::handle_RET(){
    registers[PC] = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
}
void Emulator::handle_JMP(){
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        registers[PC] = operand;
    }
    else{
        system_interupts[INVALID] = true;
        registers[PC] += inslen;
    }
    
}
void Emulator::handle_JEQ(){
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        if(psw & FZERO){
            registers[PC] = operand;
        }else{
            registers[PC] += inslen;
        }  
    }
    else{
        system_interupts[INVALID] = true;
        registers[PC] += inslen;
    }   
}
void Emulator::handle_JNE(){
    OPERAND operand;
    INSLEN inslen;
     if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        if(!(psw & FZERO)){
            registers[PC] = operand;
        }else{
            registers[PC] += inslen;
        }    
    }
    else{
        system_interupts[INVALID] = true;
        registers[PC] += inslen;
    }  
}
void Emulator::handle_JGT(){
    OPERAND operand;
    INSLEN inslen;
     if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        if(((((psw&0x000F)>>3)^((psw&0x000F)>>1))|(psw&FZERO))){
            registers[PC] = operand;
        }else{
            registers[PC] += inslen;
        } 
    }
    else{
        system_interupts[INVALID] = true;
        registers[PC] += inslen;
    }  
}
void Emulator::handle_XCHG(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regS;
        registers[_regS] = regD;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_ADD(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD + regS;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_SUB(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD - regS;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_MUL(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD * regS;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_DIV(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD / regS;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_CMP(){
    
}
void Emulator::handle_NOT(){
    REGISTER regD;
    BYTE _regD;
    if(check_rd(&regD,&_regD)==0 && check_rs(0,0)==1){
        registers[_regD] = ~regD ;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_AND(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD & regS;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_OR(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD | regS;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_XOR(){
     REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD ^ regS;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += 2;
}
void Emulator::handle_TEST(){

}
void Emulator::handle_SHL(){

}
void Emulator::handle_SHR(){

}
void Emulator::handle_LDR_POP(){
    BYTE _regD;
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,&_regD) == 0){
        registers[_regD] = operand;
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += inslen;
}
void Emulator::handle_STR_PUSH(){
    SOURCE* source;
    BYTE _regD;
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,&source) && check_rd(0,&_regD) == 0){
        *source = registers[_regD];
    }
    else{
        system_interupts[INVALID] = true;
    }
    registers[PC] += inslen;
}

void Emulator::handle_intr(){
    
}