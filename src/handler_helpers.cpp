#include "../inc/Emulator.hpp"
#include "../misc/inc/Types.h"
int Emulator::check_rd(REGISTER* regD, BYTE* _regD){
    BYTE regs = memory[(SYSREG)registers[IP] + 1];
    BYTE regD_num = (regs&0xF0)>>4;
    if(_regD){
        *_regD = regD_num;
    }
    if(regD_num < 8){
        if(regD){
            if(regD_num == IP){
                *regD = registers[regD_num] + 5;
            }else{
                *regD = registers[regD_num];
            }
        }
        return 0;
    }
    else{
        if(regD_num == 0x0F){
            return 1;
        }
        else{
            return -1;
        }
    }
}
int Emulator::check_rs(REGISTER* regS, BYTE* _regS){
    BYTE regs = memory[(SYSREG)registers[IP] + 1];
    BYTE regS_num = (regs&0x0F);
    if(_regS){
        *_regS = regS_num;
    }
    if(regS_num < 8){
        if(regS){
            if(regS_num == IP){
                *regS = registers[regS_num] + 5;
            }else{
                *regS = registers[regS_num];
            }
        }
        return 0;
    }
    else{
        if(regS_num == 0x0F){
            return 1;
        }
        else{
            return -1;
        }
    }
}
bool Emulator::scoop_operand(OPERAND* operand, INSLEN* inslen, SOURCE** source){
    ADDRMODE AddrMode = (memory[(SYSREG)registers[IP] + 2] & 0x0F);
    switch (AddrMode){
        case IMMED:{      
            if(check_rs(0,0) < 1){
                interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            OPERAND immed = *((OPERAND*)(memory + (SYSREG)registers[IP] + 3));
            immed = switch_bytes(immed);
            *operand = immed;
            *inslen = 5;
        }    
        break;

        case REGDIR:{
            REGISTER regS;
            BYTE _regS;
            int res = check_rs(&regS,&_regS);
            if(res == 1 || res == -1){
                interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            switch (get_upmode()){
                case 0b0000:
                    *operand = regS;
                    *inslen = 3;
                    break; 
                case 0b0001:
                    registers[_regS]-=2;
                    regS-=2;
                    *operand = regS;
                    *inslen = 3;
                    break;
                case 0b0010:
                    registers[_regS]+=2;
                    regS+=2;
                    *operand = regS;
                    *inslen = 3;
                    break;
                case 0b0011:  
                    *operand = regS;
                    *inslen = 3;
                    registers[_regS]-=2;
                    regS-=2;
                    break;
                case 0b0100:
                    *operand = regS;
                    *inslen = 3;
                    registers[_regS]+=2;
                    regS+=2;
                default:
                    interupts[INVALID] = true;
                    *inslen = 3;
                    return false;
            }
            if(source){
                *source = &registers[_regS];
            }
        }
        break;

        case REGDIRPOM:{
            REGISTER regS;
            BYTE _regS;
            int res = check_rs(&regS,&_regS);
            if(res == 1 || res == -1){
                interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            OPERAND pom = switch_bytes(*((SYSREG*)(memory + (SYSREG)registers[IP] + 3)));
            switch (get_upmode()){
                case 0b0000:
                    *operand = regS + pom;
                    *inslen = 5;
                    break; 
                case 0b0001:
                    registers[_regS]-=2;
                    regS-=2;
                    *operand = regS + pom;
                    *inslen = 5;
                    break;
                case 0b0010:
                    registers[_regS]+=2;
                    regS+=2;
                    *operand = regS + pom;
                    *inslen = 5;
                    break;
                case 0b0011:  
                    *operand = regS + pom;
                    *inslen = 5;
                    registers[_regS]-=2;
                    regS-=2;
                    break;
                case 0b0100:
                    *operand = regS + pom;
                    *inslen = 5;
                    registers[_regS]+=2;
                    regS+=2;
                default:
                    interupts[INVALID] = true;
                    *inslen = 3;
                    return false;
            }
        }
        break;

        case REGINDIR:{
            REGISTER regS;
            BYTE _regS;
            int res = check_rs(&regS,&_regS);
            if(res == 1 || res == -1){
                interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }  
            switch (get_upmode()){
                case 0b0000:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    *inslen = 3;
                    break; 
                case 0b0001:
                    registers[_regS]-=2;
                    regS-=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    *inslen = 3;
                    break;
                case 0b0010:
                    registers[_regS]+=2;
                    regS+=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    *inslen = 3;
                    break;
                case 0b0011:  
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    *inslen = 3;
                    registers[_regS]-=2;
                    regS-=2;
                    break;
                case 0b0100:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    *inslen = 3;
                    registers[_regS]+=2;
                    regS+=2;
                    break;
                default:
                    interupts[INVALID] = true;
                    *inslen = 3;
                    return false;
            }
            if(source){
                *source = (SOURCE*)(memory + (SYSREG)regS);
            }
        }
        break;

        case REGINDPOM:{
            REGISTER regS;
            BYTE _regS;
            int res = check_rs(&regS,&_regS);
            if(res == 1 || res == -1){
                interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            OPERAND pom = switch_bytes(*((SYSREG*)(memory + (SYSREG)registers[IP] + 3)));

            switch (get_upmode()){
                case 0b0000:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    *inslen = 5; 
                    break; 
                case 0b0001:
                    registers[_regS]-=2;
                    regS-=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    *inslen = 5;
                    break;
                case 0b0010:
                    registers[_regS]+=2;
                    regS+=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    *inslen = 5;
                    break;
                case 0b0011:  
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    *inslen = 5;
                    registers[_regS]-=2;
                    regS-=2;
                    break;
                case 0b0100:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    *inslen = 5;
                    registers[_regS]+=2;
                    regS+=2;
                default:
                    interupts[INVALID] = true;
                    *inslen = 3;
                    return false;
            }
            if(source){
                *source = (SOURCE*)(memory + (SYSREG)regS + pom);
            }
        }
        break;

        case MEM:{
            if(check_rs(0,0) < 1){
                interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            OPERAND immed = *((OPERAND*)(memory + registers[IP] + 3));
            immed = switch_bytes(immed);
            *operand = *((OPERAND*)(memory + (SYSREG)immed));
            if(source){
                *source = (SOURCE*)(memory + (SYSREG)immed);
            }
            *inslen = 5;
        }
        break;

        default:{
            interupts[INVALID] = true;
            *inslen = 3;   
            return false;
        }
        break;
    }
    return true;
}
BYTE Emulator::get_upmode(){
    return (memory[(SYSREG)registers[IP] + 2] & 0xF0) >> 4;
}
