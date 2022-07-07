#include "../inc/Emulator.hpp"
#include "../misc/inc/Types.h"

// CHECKED
void Emulator::handle_HALT(){
    pthread_mutex_lock(&mutex);
    stop = true;
    // registers[IP]++;
    pthread_mutex_unlock(&mutex);
}
// CHECKED
void Emulator::handle_INT(){
    REGISTER regD;
    BYTE _regD;
    if(!(check_rd(&regD,&_regD)==0 && check_rs(0,0)==1)){
        interupts[INVALID] = true;
        registers[IP] += 2;
        return;
    }

    registers[SP] -= 2;
    *((short*)(memory + (SYSREG)registers[SP])) = psw;

    registers[IP] = *((SYSREG*)(memory + ((SYSREG)regD % 8) * 2));
    registers[IP] += 2;
}
// SHOULD CHECKED
void Emulator::handle_IRET(){
    psw = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
    registers[IP] = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
}
// CHECKED
void Emulator::handle_CALL(){
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        registers[SP] -= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = registers[IP] + inslen;
        registers[IP] = operand;
    }
    else{
        interupts[INVALID] = true;
        registers[IP] += inslen;
    }
}
// CHECKED
void Emulator::handle_RET(){
    registers[IP] = *((short*)(memory + (SYSREG)registers[SP]));
    registers[SP]+=2;
}
// CHECKED
void Emulator::handle_JMP(){
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        registers[IP] = operand;
    }
    else{
        interupts[INVALID] = true;
        registers[IP] += inslen;
    }
    
}
// SHOULD CHECK
void Emulator::handle_JEQ(){
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        if(psw & FZERO){
            registers[IP] = operand;
        }else{
            registers[IP] += inslen;
        }  
    }
    else{
        interupts[INVALID] = true;
        registers[IP] += inslen;
    }   
}
// SHOULD CHECK
void Emulator::handle_JNE(){
    OPERAND operand;
    INSLEN inslen;
     if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        if(!(psw & FZERO)){
            registers[IP] = operand;
        }else{
            registers[IP] += inslen;
        }    
    }
    else{
        interupts[INVALID] = true;
        registers[IP] += inslen;
    }  
}
// SHOULD CHECK
void Emulator::handle_JGT(){
    OPERAND operand;
    INSLEN inslen;
     if(scoop_operand(&operand,&inslen,0) && check_rd(0,0)==1){
        if(((((psw&1)>>3)^((psw&1)>>1))|(psw&~FZERO))){
            registers[IP] = operand;
        }else{
            registers[IP] += inslen;
        } 
    }
    else{
        interupts[INVALID] = true;
        registers[IP] += inslen;
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
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_ADD(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD + regS;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_SUB(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD - regS;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_MUL(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD * regS;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_DIV(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD / regS;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_CMP(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(!(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0)){
        interupts[INVALID] = true;
    }else{
        REGISTER res_ref = regD - regS;

        if((regD - regS) & 0x10000){
            psw |= FCARRY;
        }else{
            psw &= ~FCARRY;
        }
        
        if((regD > 0 && regS < 0 && res_ref < 0) || (regD < 0 && regS > 0 && res_ref > 0)){
            psw |= FOVERFLOW;
        }else{
            psw &= ~FOVERFLOW;
        }

        if(regD == regS){
            psw |= FZERO;
        }else{
            psw &= ~FZERO;
        }

        if(res_ref < 0){
            psw |= FNEGATIVE;
        }else{
            psw &= ~FNEGATIVE;
        }
    }
    registers[IP] += 2;
}
void Emulator::handle_NOT(){
    REGISTER regD;
    BYTE _regD;
    if(check_rd(&regD,&_regD)==0 && check_rs(0,0)==1){
        registers[_regD] = ~regD ;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_AND(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD & regS;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_OR(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD | regS;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_XOR(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        registers[_regD] = regD ^ regS;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_TEST(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(!(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0)){
        interupts[INVALID] = true;
    }else{
        REGISTER res_ref = regD & regS;

        if(res_ref  == 0){
            psw |= FZERO;
        }else{
            psw &= ~FZERO;
        }

        if(res_ref < 0){
            psw |= FNEGATIVE;
        }else{
            psw &= ~FNEGATIVE;
        }
    }
    registers[IP] += 2;
}
void Emulator::handle_SHL(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        REGISTER res_ref = regD << regS;
        registers[_regD] = res_ref;

        if(res_ref == 0){
            psw |= FZERO;
        }
        else{
            psw &= ~FZERO;
        }

        if(regD & 0x8000){
            psw |= FCARRY;
        }
        else{
            psw &= ~FCARRY;
        }

        if(res_ref < 0){
            psw |= FNEGATIVE;
        }
        else{
            psw &= ~FNEGATIVE;
        }
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_SHR(){
    REGISTER regD,regS;
    BYTE _regD,_regS;
    if(check_rd(&regD,&_regD)==0 && check_rs(&regS,&_regS)==0){
        REGISTER res_ref = regD >> regS;
        registers[_regD] = res_ref;

        if(res_ref == 0){
            psw |= FZERO;
        }
        else{
            psw &= ~FZERO;
        }

        if(regD & 0x0001){
            psw |= FCARRY;
        }
        else{
            psw &= ~FCARRY;
        }

        if(res_ref < 0){
            psw |= FNEGATIVE;
        }
        else{
            psw &= ~FNEGATIVE;
        }
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += 2;
}
void Emulator::handle_LDR_POP(){
    BYTE _regD;
    OPERAND operand;
    INSLEN inslen;
    if(scoop_operand(&operand,&inslen,0) && check_rd(0,&_regD) == 0){
        registers[_regD] = operand;
    }
    else{
        interupts[INVALID] = true;
    }
    registers[IP] += inslen;
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
        interupts[INVALID] = true;
    }
    registers[IP] += inslen;
}

void Emulator::handle_intr(){
    if(interupts[RESET]){
        interupts[RESET] = false;

        registers[SP]-= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = registers[IP];

        registers[SP] -= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = psw;

        psw |= 0x8000;

        registers[IP] = *((short*)(memory + RESET*2));
    }
    else if(interupts[INVALID]){
        interupts[INVALID] = false;
        
        registers[SP]-= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = registers[IP];

        registers[SP] -= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = psw;

        psw |= 0x8000;

        registers[IP] = *((short*)(memory + INVALID*2));


    }
     else if(interupts[TERMINAL] && ((psw & FINTERRUPT) == 0) && ((psw & FTERMINAL) == 0)){
        interupts[TERMINAL] = false;
        
        registers[SP]-= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = registers[IP];

        registers[SP] -= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = psw;
        
        psw |= 0x8000;

        registers[IP] = *((short*)(memory + TERMINAL*2));
    }   
    else if(interupts[TIMER] && ((psw & FINTERRUPT) == 0) && ((psw & FTIMER) == 0)){
        interupts[TIMER] = false;
        
        registers[SP]-= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = registers[IP];

        registers[SP] -= 2;
        *((short*)(memory + (SYSREG)registers[SP])) = psw;

        psw |= 0x8000;

        registers[IP] = *((short*)(memory + TIMER*2));
    }   
}