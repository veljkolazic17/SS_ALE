#pragma once

#include <string>

class Label{
  public:
    Label(std::string* label);
    std::string* getLabel();

    ~Label();
    
  private:
    std::string* label;
};