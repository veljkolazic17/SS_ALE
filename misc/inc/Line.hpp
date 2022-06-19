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

    int getLineNumber();
    void setLineNumber(int lineNumber);
    

  private:
    Directive* directive;
    Instruction* instruction;
    Label* label;
    int line_number = 0;
};