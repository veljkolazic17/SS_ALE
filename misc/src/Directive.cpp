#include "../inc/Directive.hpp"

using namespace std;

Directive::Directive(DirectiveType directiveType){
  this->directive_type = directiveType;
}

Directive::Directive(DirectiveType directiveType, std::string* section){
  this->directive_type = directiveType;
  this->section = section;
}

Directive::Directive(DirectiveType directiveType, int literal){
  this->directive_type = directiveType;
  this->literal = literal;
}

Directive::Directive(DirectiveType directiveType, std::vector<SymbolListElement*>* symbolList){
  this->directive_type = directive_type;
  this->symbolList = symbolList;
}

std::vector<SymbolListElement*>*  Directive::getSymbolList(){
  return this->symbolList;
}

DirectiveType Directive::getDirectiveType(){
  return this->directive_type;
}

Directive::~Directive(){
  int size = this->symbolList->size();
  for(int i = 0; i < size ; i++){
    delete this->symbolList->at(i);
  }
  // CHECK proveri treba li brisati section
  delete this->section;
  delete this->symbolList;
}