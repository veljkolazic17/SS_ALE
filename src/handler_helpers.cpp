#include "../inc/Emulator.hpp"
#include "../misc/inc/Types.h"
int Emulator::check_rd(REGISTER* regD, BYTE* _regD){
    BYTE regs = memory[(SYSREG)registers[PC]];
    BYTE regD_num = (regs&0xF0)>>4;
    if(_regD){
        *_regD = regD_num;
    }
    if(regD_num < 8){
        if(regD){
            *regD = registers[regD_num];
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
    BYTE regs = memory[(SYSREG)registers[PC]];
    BYTE regS_num = (regs&0x0F);
    if(_regS){
        *_regS = regS_num;
    }
    if(regS_num < 8){
        if(regS){
            *regS = registers[regS_num];
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
    ADDRMODE AddrMode = (memory[(SYSREG)registers[PC] + 2] & 0x0F) >> 4;
    switch (AddrMode){
        case IMMED:{      
            if(check_rs(0,0) < 1){
                system_interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            OPERAND immed = *((OPERAND*)(memory + 3));
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
                system_interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            *operand = regS;
            *inslen = 3;
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
                system_interupts[INVALID] = true;
                *inslen = 5;   
                return false;
            }
            OPERAND pom = *((OPERAND*)(memory + 3));
            pom = switch_bytes(pom);
            *operand = pom + regS;
            *inslen = 5;
        }
        break;

        case REGINDIR:{
            REGISTER regS;
            BYTE _regS;
            int res = check_rs(&regS,&_regS);
            if(res == 1 || res == -1){
                system_interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            
            switch (get_upmode()){
                case 0b0000:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS);
                    }
                    *inslen = 3;
                    break; 
                case 0b0001:
                    registers[_regS]-=2;
                    regS-=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS);
                    }
                    *inslen = 3;
                    break;
                case 0b0010:
                    registers[_regS]+=2;
                    regS+=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS);
                    }
                    *inslen = 3;
                    break;
                case 0b0011:  
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS);
                    }
                    *inslen = 3;
                    registers[_regS]-=2;
                    regS-=2;
                    break;
                case 0b0100:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS);
                    }
                    *inslen = 3;
                    registers[_regS]+=2;
                    regS+=2;
                default:
                    system_interupts[INVALID] = true;
                    *inslen = 3;
                    return false;
            }
        }
        break;

        case REGINDPOM:{
            REGISTER regS;
            BYTE _regS;
            int res = check_rs(&regS,&_regS);
            if(res == 1 || res == -1){
                system_interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            OPERAND pom = *((OPERAND*)(memory + 3));
            pom = switch_bytes(pom);

            switch (get_upmode()){
                case 0b0000:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS + pom);
                    }
                    *inslen = 3;
                    break; 
                case 0b0001:
                    registers[_regS]-=2;
                    regS-=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS + pom);
                    }
                    *inslen = 3;
                    break;
                case 0b0010:
                    registers[_regS]+=2;
                    regS+=2;
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS + pom);
                    }
                    *inslen = 3;
                    break;
                case 0b0011:  
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS + pom);
                    }
                    *inslen = 3;
                    registers[_regS]-=2;
                    regS-=2;
                    break;
                case 0b0100:
                    *operand = *((OPERAND*)(memory + (SYSREG)regS + pom));
                    if(source){
                        *source = (SOURCE*)(memory + (SYSREG)regS + pom);
                    }
                    *inslen = 3;
                    registers[_regS]+=2;
                    regS+=2;
                default:
                    system_interupts[INVALID] = true;
                    *inslen = 3;
                    return false;
            }
        }
        break;

        case MEM:{
            if(check_rs(0,0) < 1){
                system_interupts[INVALID] = true;
                *inslen = 3;   
                return false;
            }
            OPERAND immed = *((OPERAND*)(memory + 3));
            immed = switch_bytes(immed);
            *operand = *((OPERAND*)(memory + (SYSREG)immed));
            if(source){
                        *source = (SOURCE*)(memory + (SYSREG)immed);
            }
            *inslen = 5;
        }
        break;

        default:{
            system_interupts[INVALID] = true;
            *inslen = 3;   
            return false;
        }
        break;
    }
    return true;
}
BYTE Emulator::get_upmode(){
    return (memory[(SYSREG)registers[PC] + 2] & 0xF0) >> 4;
    
}
unsigned short switch_bytes(unsigned short word){
    return (word)>>8 | (word)<<8;
}