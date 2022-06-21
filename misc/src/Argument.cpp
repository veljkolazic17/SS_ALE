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
  this->literal = literal;
}

Argument::Argument(ArgumentTypes type, char reg, std::string* symbol){
  this->type = type;
  this->reg = reg;
  this->symbol = symbol;
}

Argument::Argument(ArgumentTypes type, std::string* symbol){
  this->type;
  this->symbol;
}

Argument::~Argument(){
  delete this->symbol;
}