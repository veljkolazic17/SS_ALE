#include "../inc/SymbolListElement.hpp"

SymbolListElement::SymbolListElement(SymbolListElementType type, int literal){
  this->type = type;
  this->literal = literal;
}

SymbolListElement::SymbolListElement(SymbolListElementType type, std::string *symbol){
  this->type = type;
  this->symbol = symbol;
}

std::string SymbolListElement::getSymbol(){
  return this->symbol;
}

int SymbolListElement::getLiteral(){
  return this->literal;
}

