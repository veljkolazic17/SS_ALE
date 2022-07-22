#pragma once
#include "../inc/Types.h"
#include "../inc/SymbolListElement.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "ExpressionElement.hpp"

class Directive{

  public:
    Directive(DirectiveType);
    Directive(DirectiveType, Expression*);
    Directive(DirectiveType, std::string*);
    Directive(DirectiveType, int);
    Directive(DirectiveType, std::vector<SymbolListElement*>*);
    DirectiveType getDirectiveType();
    std::string getSectionName();
    int getLiteral();

    std::vector<SymbolListElement*>* getSymbolList();
    std::string toString();
    Expression* getExpression();

    ~Directive();
  private:
    DirectiveType directive_type;
    std::vector<SymbolListElement*>* symbolList;
    Expression* expression;
    int literal;
    std::string *section;

};