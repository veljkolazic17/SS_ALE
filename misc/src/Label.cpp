#include "../inc/Label.hpp"

Label::Label(std::string* label){
  this->label = label;
}

std::string* Label::getLabel(){
  return this->label;
}

Label::~Label(){
  delete this->label;
}