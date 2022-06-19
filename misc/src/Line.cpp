#include "../inc/Line.hpp"


Line::Line(Directive* directive){
  this->directive = directive;
}

Line::Line(Instruction* instruction){
  this->instruction = instruction;
}

Line::Line(Label* label){
  this->label = label;
}

Line::Line(Label* label, Directive* directive){
  this->label = label;
  this->directive = directive;
}

Line::Line(Label* label, Instruction* instruction){
  this->label = label;
  this->instruction = instruction;
}

int Line::getLineNumber(){
  return this->line_number;
}

void Line::setLineNumber(int lineNumber){
  this->line_number = line_number;
}

Line::~Line(){
  if(label != nullptr){
    delete label;
  }
  if(instruction != nullptr){
    delete instruction;
  }
  if(directive != nullptr){
    delete directive;
  }
}