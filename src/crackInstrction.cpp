#include "../inc/Assembler.hpp"
#include "../misc/inc/Codes.h"

void Assembler::insertInstruction(Instruction* instruction){
    /**
     * @brief FIRST BYTE
     * 
     */
    InstructionTypes instructionType = instruction->getInstructionType();

    OPCODE opcode = OPCODES[instructionType];
    this->currentSection->setDataByOffsetMem(
        this->currentSection->getLocationCounter(),
        (char*)&opcode,
        1
    );
    this->currentSection->incrementLocationCounter(1);
    /**
     * @brief SECOND BYTE && THIRD BYTE
     * 
     */
    if(!instruction->getNumOfArguments()){
        return;
    }
    char numOfArguments = instruction->getNumOfArguments();

    unsigned char RegDescr = 0xFF;
    unsigned char AddrMode = 0xFF;
    unsigned char DataHigh = 0;
    unsigned char DataLow = 0;
    INSLEN instructionLen;
    
    for(char i = 0;i<numOfArguments;i++){
        Argument* argument = instruction->getArgument(i);
        ArgumentTypes argumentType = argument->getArgumentType();
        // TAKE LAST ARGUMENT TYPE AND DETERMINE INSTRUCTION LENGTH
        instructionLen = INSLENS[argumentType];
        /**
         * @brief check registers
         * 
         */
        if(argumentType == REGISTER_TYPE){
            if(RegDescr == 0xFF){
                RegDescr = 0x0F;
                RegDescr |= (argument->getRegister()<<4);
            }else{
                RegDescr &= 0xF0;
                RegDescr |= argument->getRegister();
            }
        }else{
            /**
             * @brief SECOND BYTE
             * 
             */
            if(
                    argumentType == DATA_OPERAND_REG 
                ||  argumentType == DATA_OPERAND_REGMEM
                ||  argumentType == DATA_OPERAND_REGMEMLIT
                ||  argumentType == DATA_OPERAND_REGMEMSYM
                ||  argumentType == JMP_OPERAND_REG
                ||  argumentType == JMP_OPERAND_REGMEM
                ||  argumentType == JMP_OPERAND_REGMEMLIT
                ||  argumentType == JMP_OPERAND_REGMEMSYM
            ){
                RegDescr &= 0xF0;
                RegDescr |= argument->getRegister();
            }
            else if(
                    argumentType == DATA_OPERAND_MEMSYMPCREL
                ||  argumentType == JMP_OPERAND_SYMPCREL
            ){
                RegDescr &= 0xF0;
                RegDescr |= 7; //PC
            }
            /**
             * @brief THIRD BYTE
             * 
             */
            ADDRMODE addrmode = ADDRMODES[argumentType];
            UPMODE upmode = UPMODES[instructionType];
            AddrMode = (upmode<<4) | (addrmode);
            /**
             * @brief FOURTH AND FIFTH BYTE
             * 
             */
            if(
                    argumentType == DATA_OPERAND_LIT
                ||  argumentType == DATA_OPERAND_MEMLIT
                ||  argumentType == DATA_OPERAND_REGMEMLIT
                ||  argumentType == JMP_OPERAND_LIT
                ||  argumentType == JMP_OPERAND_MEMLIT
                ||  argumentType == JMP_OPERAND_REGMEMLIT
            ){
                //SWAP BITS 0005
                // Data = (argument->getLiteral()<<4) | (0x00FF&(argument->getLiteral()>>4));
                DataHigh = (0xFF00&argument->getLiteral())>>4;
                DataLow = 0x00FF&argument->getLiteral();
            }
            else if(
                    argumentType == DATA_OPERAND_SYM
                ||  argumentType == DATA_OPERAND_REGMEMSYM
                ||  argumentType == DATA_OPERAND_REGMEMSYM
                ||  argumentType == DATA_OPERAND_MEMSYMPCREL
                ||  argumentType == JMP_OPERAND_SYM
                ||  argumentType == JMP_OPERAND_SYMPCREL
                ||  argumentType == JMP_OPERAND_MEMSYM
                ||  argumentType == JMP_OPERAND_REGMEMSYM
            ){   
                bool found = false;
                SymbolTableElement* symbolToPatch;
                int symbolTableSize = this->symbolTable->size();
                int currentLocationCounter = this->currentSection->getLocationCounter();

                for(int j = 0;j<symbolTableSize;j++){
                    if(this->symbolTable->at(j)->getSymbolName() == argument->getSymbol()){
                        symbolToPatch = this->symbolTable->at(j);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    symbolToPatch = new SymbolTableElement(
                        this->entry,
                        0,
                        0,
                        0,
                        NOTYP,
                        LOC,
                        UND,
                        nullptr,
                        argument->getSymbol()
                    );
                    entry++;
                    this->symbolTable->push_back(symbolToPatch);
                }

                if(
                        symbolToPatch->getDefined() 
                    &&  (argumentType == DATA_OPERAND_MEMSYMPCREL ||  argumentType == JMP_OPERAND_SYMPCREL)
                    &&  (this->currentSection == symbolToPatch->getSection())
                ){
                    int symdata = symbolToPatch->getValue() - this->currentSection->getLocationCounter();
                    // Data = (symdata<<4) | (0x00FF&(symdata>>4));
                    DataHigh = (0xFF00&symdata)>>4;
                    DataLow = 0x00FF&symdata;
                }
                else{
                    if(
                            argumentType != DATA_OPERAND_MEMSYMPCREL 
                        &&  argumentType != JMP_OPERAND_SYMPCREL
                    ){
                        symbolToPatch->backpatch({this->currentSection->getLocationCounter(),RELOCATION,this->currentSection});
                    }
                    else{
                        symbolToPatch->backpatch({this->currentSection->getLocationCounter(),UNDEFINED,this->currentSection});
                    }
                }
            }
        }
    }

    //ALWAYS WRITE REGISTERS IF INSTUCTION IS MORE THAN ONE BYTE
    this->currentSection->setDataByOffsetMem(
        this->currentSection->getLocationCounter(),
        (char*)&RegDescr,
        1
    );
    this->currentSection->incrementLocationCounter(1);
    
    if(instructionLen != 0xFF){
        this->currentSection->setDataByOffsetMem(
            this->currentSection->getLocationCounter(),
            (char*)&AddrMode,
            1
        );
        this->currentSection->incrementLocationCounter(1);
    }
    if(instructionLen != 0xFF && instructionLen > 3){
        this->currentSection->setDataByOffsetByte(
            this->currentSection->getLocationCounter(),
            DataHigh,
            1
        );
        this->currentSection->setDataByOffsetByte(
            this->currentSection->getLocationCounter()+1,
            DataLow,
            1
        );
        this->currentSection->incrementLocationCounter(2);
    }
}