#include "Argument.hpp"
#include "Types.h"
#include "OPCodes.h"

#include <vector>

class Instruction{
  public:

    Instruction(InstructionTypes instruction_type);
    Instruction(InstructionTypes instruction_type, Argument* argument);
    Instruction(InstructionTypes instruction_type, Argument* argument1, Argument* argument2);

    ~Instruction();

    void addArgument(Argument* argument);
    Argument* getArgument(int index);
    int getNumOfArguments();
    InstructionTypes getInstructionType();

    void setInstructionOPCode(OPCodes instruction_opcode);
    OPCodes getIntstructionOPCode();
  private:

    OPCodes instruction_opcode;
    InstructionTypes instruction_type;
    std::vector<Argument*>* operands;
};