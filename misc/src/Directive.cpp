#include "../inc/Directive.hpp"

using namespace std;

Directive::Directive(DirectiveType directiveType){
  this->directive_type = directiveType;
}

Directive::Directive(DirectiveType directiveType, std::string* section){
  this->directive_type = directiveType;
  this->section = section;
  this->symbolList = new std::vector<SymbolListElement*>(); 
}

Directive::Directive(DirectiveType directiveType, Expression* expression){
  this->directive_type = directiveType;
  this->expression = expression;
}

Directive::Directive(DirectiveType directiveType, int literal){
  this->directive_type = directiveType;
  this->literal = literal;
  this->symbolList = new std::vector<SymbolListElement*>();
}

Directive::Directive(DirectiveType directiveType, std::vector<SymbolListElement*>* symbolList){
  this->directive_type = directiveType;
  this->symbolList = symbolList;
}

std::vector<SymbolListElement*>*  Directive::getSymbolList(){
  return this->symbolList;
}

DirectiveType Directive::getDirectiveType(){
  return this->directive_type;
}

std::string Directive::getSectionName(){
  return *this->section;
}

int Directive::getLiteral(){
  return this->literal;
}

Expression* Directive::getExpression(){
  return this->expression;
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

std::string Directive::toString(){
  std::string str;
  switch (this->directive_type)
  {
  case GLOBAL_TYPE:
    str+="global ";
    break;
  case EXTERN_TYPE:
    str+="extern ";
    break;
  case SECTION_TYPE:
    str+="section " + *this->section;
    break;
  case WORD_TYPE:
    str+="word ";
    break;
  }
  int size = this->symbolList->size();
  for(int i = 0;i<size;i++){
    if(this->symbolList->at(i)->getSymbolListElementType() == SYMBOL_TYPE){
      // printf("NAISAO NA SIMBOL\n");
      str+=this->symbolList->at(i)->getSymbol()+" ";
    }else{
      // printf("NAISAO NA LITERAL %d\n",this->symbolList->at(i)->getLiteral());
      str+=this->symbolList->at(i)->getLiteral()+" ";
    }
  }
  return str;
}