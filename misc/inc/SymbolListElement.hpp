#pragma once

#include "Types.h"
#include <string>
class SymbolListElement{

  public:
    SymbolListElement(SymbolListElementType type, int literal);
    SymbolListElement(SymbolListElementType type, std::string* symbol);
    std::string getSymbol();
    int getLiteral();

  private:
    SymbolListElementType type;
    int literal;
    std::string symbol;
};