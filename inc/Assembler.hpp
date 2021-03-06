#pragma once
#include "./SymbolTableElement.hpp"
#include "./Section.hpp"
#include "../misc/inc/Label.hpp"
#include "../misc/inc/Directive.hpp"
#include "../misc/inc/Instruction.hpp"
#include "../misc/inc/Lines.hpp"
#include "../misc/inc/Line.hpp"
#include <vector>

#define PROCESSING 0
#define END 1
typedef unsigned char STATE;

class Assembler{
    public:
        struct TNSElement{
            Expression* expression;
        };

        Assembler();
        /**
         * @brief used for printing tables and contetn
         * 
         */
        void objdump(char*);
        /**
         * @brief assembler main loop instructions
         * 
         */
        void crack(Lines*);
        void crackLine(Line*);
        void insertLabel(Label*);
        void insertDirective(Directive*);
        void insertInstruction(Instruction*);
        /**
         * @brief handle directive types
         * 
         */
        void crackGLOBAL(Directive*);
        void crackEXTERN(Directive*);
        void crackSECTION(Directive*);
        void crackWORD(Directive*);
        void crackSKIP(Directive*);
        void crackEQU(Directive*);
        void crackEND(Directive*);
        void crackASCII(Directive*);
        /**
         * @brief helper functions
         * 
         */
        void insertSection(Section*);
        /**
         * @brief backpatcing method
         * 
         */
        void backpatchSingle(SymbolTableElement*);
        void backpatch();
        /**
         * @brief form SElf file and .o file
         * 
         */
        void createSElf(char* obj_filename);

        void insertTNSElement(TNSElement);

    private:
        std::vector<SymbolTableElement*>* symbolTable;
        std::vector<Section*>* sections;
        Section* currentSection = nullptr;
        Section* ABS_section = nullptr;
        int entry = 1;
        STATE ASMSTATE = PROCESSING;
        std::vector<TNSElement> TNS;
};