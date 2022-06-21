#pragma once
#include "./SymbolTableElement.hpp"
#include "./Section.hpp"
#include "../misc/inc/Label.hpp"
#include "../misc/inc/Directive.hpp"
#include "../misc/inc/Instruction.hpp"
#include <vector>

class Assembler{
    public:
        void insertLabel(Label* label);
        void insertDirective(Directive* Directive);
    private:
        std::vector<SymbolListElementType*>* symbolTable;
        Section* currentSection = nullptr;

};