#pragma once
#include<iostream>
#include <string>

class Label{
  public:
    Label(std::string* label);
    std::string* getLabel();

    ~Label();
    
    std::string toString();

  private:
    std::string* label;
};