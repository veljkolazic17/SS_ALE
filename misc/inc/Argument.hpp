#pragma once

#include "Types.h"
#include <string>

class Argument{
  public:
    Argument(ArgumentTypes type, int literal);
    Argument(ArgumentTypes type, char reg);
    Argument(ArgumentTypes type, char reg, int litreal);
    Argument(ArgumentTypes type, std::string* symbol);
    Argument(ArgumentTypes type, char reg, std::string* symbol);
    ~Argument();

    ArgumentTypes getArgumentType();
    std::string getSymbol();
    char getRegister();
    int getLiteral();
  
  private:
    ArgumentTypes type;

    int literal;
    std::string* symbol;
    char reg;

};