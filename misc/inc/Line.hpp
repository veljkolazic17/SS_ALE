#pragma once

#include "Directive.hpp"
#include "Label.hpp"
#include "Instruction.hpp"

class Line{
  public:
    Line(Directive* directive);
    Line(Instruction* instruction);
    Line(Label* label);
    Line(Label* label, Directive* directive);
    Line(Label* label, Instruction* instruction);

    ~Line();

    int getLineNumber();
    void setLineNumber(int lineNumber);

    Directive* getDirective();
    Instruction* getInstruction();
    Label* getLabel();

  private:
    Directive* directive = nullptr;
    Instruction* instruction = nullptr;
    Label* label = nullptr;
    int line_number = 0;
};