#include "../inc/Instruction.hpp"

Instruction::Instruction(InstructionTypes instruction_type){
  this->operands = new std::vector<Argument*>();

  this->instruction_type = instruction_type;
}

Instruction::Instruction(InstructionTypes instruction_type, Argument* argument){
  this->operands = new std::vector<Argument*>();

  this->instruction_type = instruction_type;
  this->operands->push_back(argument);
}

Instruction::Instruction(InstructionTypes instruction_type, Argument* argument1, Argument* argument2){
  this->operands = new std::vector<Argument*>();

  this->instruction_type = instruction_type;
  this->operands->push_back(argument1);
  this->operands->push_back(argument2);
}

void Instruction::addArgument(Argument* argument){
  if(this->operands != nullptr){
    this->operands->push_back(argument);
  }
}

Argument* Instruction::getArgument(int index){
  if(this->operands != nullptr){
    return this->operands->at(index);
  }
  return nullptr;
}

int Instruction::getNumOfArguments(){
  return this->operands->size();
}

InstructionTypes Instruction::getInstructionType(){
  return this->instruction_type;
}

Instruction::~Instruction(){
  int size = this->operands->size();
  for(int i = 0; i < size ;i++){
    delete this->operands->at(i);
  }
  delete operands;
}