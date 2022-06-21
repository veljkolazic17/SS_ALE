#include "../inc/Assembler.hpp"

Assembler::Assembler(){
    this->symbolTable = new std::vector<SymbolTableElement*>();
    this->sections = new std::vector<Section*>();
}

void Assembler::insertSection(Section* section){
    this->sections->push_back(section);
}

void Assembler::objdump(){
    printf("NUM\tVALUE\t\tSIZE\tTYPE\tBIND\tNDX\tNAME\n");
    int symbolTableSize = this->symbolTable->size();
    for(int i = 0;i<symbolTableSize;i++){
        SymbolTableElement* ste = this->symbolTable->at(i);
        printf(
            "%d\t%08lx\t%d\t%s\t%s\t%s\t%s\n",
            ste->getNum(),
            ste->getValue(),
            ste->getSize(),
            (ste->getType()==NOTYP)?"NOTYP":"SCTN",
            (ste->getBinding()==LOC)?"LOC":"GLOB",
            (ste->getNDX()==-1)?"UND":("."+ste->getSection()->getSectionName()).c_str(),
            ste->getSymbolName().c_str()
        );
    }
    int sectionsSize = this->sections->size();
    for(int i = 0;i<sectionsSize;i++){
        printf("%s",("#."+this->sections->at(i)->getSectionName()).c_str());
        int dataSize = this->sections->at(i)->getDataSize();
        for(int j = 0;j<dataSize;j++){
            if(j%8 == 0){
                printf("\n");
            }
            else if(j%4 == 0){
                printf("\t");
            }
            else{
                printf(" ");
            }
            printf("%02x",this->sections->at(i)->getData(j));
        }
        printf("\n");
    }
}

void Assembler::crack(Lines* lines){
    int size = lines->getLineSize();
    for(int i = 0;i<size;i++){
        this->crackLine(lines->getLine(i));
    }
}

void Assembler::crackLine(Line* line){
    if(line->getLabel() != nullptr){
        this->insertLabel(line->getLabel());
    }
    if(line->getDirective() != nullptr){
        this->insertDirective(line->getDirective());
    }
    if(line->getInstruction() != nullptr){
        // TODO Implementirati insertInstruction !!!
    }
}

void Assembler::insertDirective(Directive* directive){
    switch (directive->getDirectiveType())
    {
    case GLOBAL_TYPE:
        crackGLOBAL(directive);
        break;
    case EXTERN_TYPE:
        crackEXTERN(directive);
        break;
    case SECTION_TYPE:
        crackSECTION(directive);
        break;
    case WORD_TYPE:
        crackSECTION(directive);
        break;
    case SKIP_TYPE:
        crackSKIP(directive);
        break;
    case END_TYPE:
        crackEND(directive);
        break;
    }
}

void Assembler::crackGLOBAL(Directive* directive){
    int symbolListSize = directive->getSymbolList()->size();
    int symbolTableSize = this->symbolTable->size();

    for(int i = 0;i<symbolListSize;i++){
        bool found = false;
        for(int j = 0;j<symbolTableSize;j++){
            if(this->symbolTable->at(j)->getSymbolName() == directive->getSymbolList()->at(i)->getSymbol()){
                this->symbolTable->at(j)->setBinding(GLOB);
                found = true;
                break;
            }
        }
        if(!found){
            SymbolTableElement* symbolTableElement = new SymbolTableElement(
                this->entry,
                0,
                0,
                0,
                NOTYP,
                GLOB,
                UND,
                nullptr,
                directive->getSymbolList()->at(i)->getSymbol()
            );
            entry++;
            this->symbolTable->push_back(symbolTableElement);
        }
    }
}

void Assembler::crackEXTERN(Directive* directive){
    int symbolListSize = directive->getSymbolList()->size();
    int symbolTableSize = this->symbolTable->size();

    for(int i = 0;i<symbolListSize;i++){
        bool found = false;
        for(int j = 0;j<symbolTableSize;j++){
            if(this->symbolTable->at(j)->getSymbolName() == directive->getSymbolList()->at(i)->getSymbol()){
                this->symbolTable->at(j)->setBinding(GLOB);
                found = true;
                break;
            }
        }
        if(!found){
            SymbolTableElement* symbolTableElement = new SymbolTableElement(
                this->entry,
                0,
                0,
                0,
                NOTYP,
                GLOB,
                UND,
                nullptr,
                directive->getSymbolList()->at(i)->getSymbol()
            );
            entry++;
            this->symbolTable->push_back(symbolTableElement);
        }
    }
}

void Assembler::crackSECTION(Directive* directive){ 
    this->currentSection = new Section(
        entry,
        directive->getSectionName()
    );
    this->sections->push_back(this->currentSection);

    SymbolTableElement* symbolTableElement = new SymbolTableElement(
        entry,
        0,
        0,
        0,
        SCTN,
        LOC,
        entry,
        currentSection,
        currentSection->getSectionName()
    );
    entry++;
    this->symbolTable->push_back(symbolTableElement);
}

void Assembler::crackWORD(Directive* directive){
    
}

void Assembler::crackSKIP(Directive* directive){
    int currentLocationCounter = this->currentSection->getLocationCounter();
    int directiveLiteral = directive->getLiteral();
    this->currentSection->setDataByOffsetByte(currentLocationCounter,0,directiveLiteral);
    this->currentSection->setLocationCounter(
        currentLocationCounter + directiveLiteral
    );
    
}

void Assembler::crackEND(Directive* directive){

}

void Assembler::insertLabel(Label* label){
    SymbolTableElement* symbolTableElement = new SymbolTableElement(
        entry,
        this->currentSection->getLocationCounter(),
        0,
        0,
        NOTYP,
        LOC,
        this->currentSection->getIndex(),
        this->currentSection,
        *label->getLabel()
    );
    entry++;
    this->symbolTable->push_back(symbolTableElement);
}