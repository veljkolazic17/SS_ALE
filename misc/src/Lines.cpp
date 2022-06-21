#include "../inc/Lines.hpp"


Lines::Lines(){
  this->lines = new std::vector<Line*>();
}

Line* Lines::getLine(int index){
  return this->lines->at(index);
}

void Lines::putLine(Line* line){
  this->lines->push_back(line);
}
 
int Lines::getLineSize(){
  return this->lines->size();
} 

Lines::~Lines(){
  int size = this->lines->size();
  for(int i = 0;i<size;i++){
    delete this->lines->at(i);
  }
  delete this->lines;
}