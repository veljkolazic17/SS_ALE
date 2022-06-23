#include "../inc/Argument.hpp"


Argument::Argument(ArgumentTypes type, int literal){
  this->type = type;
  this->literal = literal;
}

Argument::Argument(ArgumentTypes type, char reg){
  this->type = type;
  this->reg = reg;
}

Argument::Argument(ArgumentTypes type, char reg, int litreal){
  this->type = type;
  this->reg = reg;
  this->literal = litreal;
}

Argument::Argument(ArgumentTypes type, char reg, std::string* symbol){
  this->type = type;
  this->reg = reg;
  this->symbol = symbol;
}

Argument::Argument(ArgumentTypes type, std::string* symbol){
  this->type = type;
  this->symbol = symbol;
}

Argument::~Argument(){
  delete this->symbol;
}

ArgumentTypes Argument::getArgumentType(){
  return this->type;
}

std::string Argument::getSymbol(){
  return *this->symbol;
}

char Argument::getRegister(){
  return this->reg;
}

int Argument::getLiteral(){
  return this->literal;
}