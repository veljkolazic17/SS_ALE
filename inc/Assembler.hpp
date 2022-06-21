#pragma once
#include "./SymbolTableElement.hpp"
#include "./Section.hpp"
#include "../misc/inc/Label.hpp"
#include "../misc/inc/Directive.hpp"
#include "../misc/inc/Instruction.hpp"
#include "../misc/inc/Lines.hpp"
#include "../misc/inc/Line.hpp"
#include <vector>

class Assembler{
    public:
        Assembler();

        void objdump();
        void crack(Lines* lines);
        void crackLine(Line* line);

        void insertLabel(Label* label);
        void insertDirective(Directive* Directive);

        void crackGLOBAL(Directive* directive);
        void crackEXTERN(Directive* directive);
        void crackSECTION(Directive* directive);
        void crackWORD(Directive* directive);
        void crackSKIP(Directive* directive);
        void crackEQU(Directive* directive);
        void crackEND(Directive* directive);

        void insertSection(Section* section);

    private:
        std::vector<SymbolTableElement*>* symbolTable;
        std::vector<Section*>* sections;
        Section* currentSection = nullptr;
        int entry = 1;

};