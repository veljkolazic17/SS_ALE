#pragma once
#include "../inc/Types.h"
#include "../inc/SymbolListElement.hpp"
#include <iostream>
#include <vector>
#include <string>

class Directive{

  public:
    Directive(DirectiveType directiveType);
    Directive(DirectiveType directiveType, std::string* section);
    Directive(DirectiveType directiveType, int literal);
    Directive(DirectiveType directiveType, std::vector<SymbolListElement*>* symbolList);
    DirectiveType getDirectiveType();
    std::string getSectionName();
    int getLiteral();

    std::vector<SymbolListElement*>* getSymbolList();
    std::string toString();

    ~Directive();
  private:
    DirectiveType directive_type;
    std::vector<SymbolListElement*>* symbolList;
    int literal;
    std::string *section;

};