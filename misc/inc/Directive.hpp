#include "Types.h"
#include "SymbolListElement.hpp"
#include <vector>
#include <string>

class Directive{

  public:
    Directive(DirectiveType directiveType);
    Directive(DirectiveType directiveType, std::string* section);
    Directive(DirectiveType directiveType, int literal);
    Directive(DirectiveType directiveType, std::vector<SymbolListElement*>* symbolList);
    std::vector<SymbolListElement*>* getSymbolList();
  private:
    DirectiveType directive_type;
    std::vector<SymbolListElement*>* symbolList;
    int literal;
    std::string section;

};