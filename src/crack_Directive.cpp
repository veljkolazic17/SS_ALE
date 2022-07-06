#include "../inc/Assembler.hpp"
#include "../misc/inc/ExpressionElement.hpp"

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
        crackWORD(directive);
        break;
    case SKIP_TYPE:
        crackSKIP(directive);
        break;
    case ASCII_TYPE:
        crackASCII(directive);
        break;
    case END_TYPE:
        crackEND(directive);
        break;
    case EQU_TYPE:
        crackEQU(directive);
        break;
    }
}

void Assembler::crackEQU(Directive* directive){
    Expression* expression = directive->getExpression();

    std::vector<Expression::ExpressionElement> expression_ = *expression->getExpression();
    int symbolTableSize = this->symbolTable->size();

    int value = 0;

    bool literal_present = false;
    int literal;

    bool found = false;
    bool should_write = true;


    for(int i = expression_.size() - 1; i >= 0; i--){
        Expression::ExpressionElement element = expression_.at(i);
        switch (element.type){
        case SYMBOL_TYPE_EXP:
            for(int j = 0;j<symbolTableSize;j++){
                if(this->symbolTable->at(j)->getSymbolName() == element.value){

                    found = true;

                    if(this->symbolTable->at(j)->getDefined() == true){
                        if(i == 0){
                            value += this->symbolTable->at(j)->getValue();
                        }else{
                            literal = this->symbolTable->at(j)->getValue();
                            literal_present = true;
                        }
                        break;
                    }else{
                        TNSElement tns;
                        tns.expression = expression;
                        insertTNSElement(tns);
                        should_write = false;
                        break;
                    }
                }
            }

            if(!found){
                TNSElement tns;
                tns.expression = expression;
                insertTNSElement(tns); 
                should_write = false;
            }

            break;
        case LITERAL_TYPE_EXP:
            literal = stoi(element.value);
            literal_present = true;
            if(i == 0){
                value += literal;
            }
            break;
        case MINUS_TYPE_EXP:
            if(literal_present){
                value-=literal;
                literal_present = false;
            }
            break;
        case PLUS_TYPE_EXP:
            if(literal_present){
                value+=literal;
                literal_present = false;
            }
            break;
        }
    }
 
    if(should_write){
        SymbolTableElement* symbolTableElement = new SymbolTableElement(
            this->entry,
            value,
            0,
            0,
            NOTYP,
            LOC,
            1,
            ABS_section,
            expression->getSymbol()
        );
        entry++;
        symbolTableElement->setDefined(true);
        this->symbolTable->push_back(symbolTableElement);
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
    this->currentSection->setSymbolTableEntry(symbolTableElement);
    entry++;
    this->symbolTable->push_back(symbolTableElement);
}

void Assembler::crackWORD(Directive* directive){
    int symbolListSize = directive->getSymbolList()->size();
    int symbolTableSize = this->symbolTable->size();

    for(int i = 0;i<symbolListSize;i++){

        SymbolListElement* currentSymbolListElement = directive->getSymbolList()->at(i);
        int currentLocationCounter = this->currentSection->getLocationCounter();
        
        if(currentSymbolListElement->getSymbolListElementType() == LITERAL_TYPE){
            int literal = currentSymbolListElement->getLiteral();
            this->currentSection->setDataByOffsetMem(currentLocationCounter,(char*)(&literal),2);
            this->currentSection->setLocationCounter(
                this->currentSection->getLocationCounter()+2
            );
        }else{
            bool found = false;

            SymbolTableElement* symbolToPatch;

            for(int j = 0;j<symbolTableSize;j++){
                if(this->symbolTable->at(j)->getSymbolName() == directive->getSymbolList()->at(i)->getSymbol()){
                    symbolToPatch = this->symbolTable->at(j);
                    found = true;
                    break;
                }
            }
            if(!found){
                symbolToPatch = new SymbolTableElement(
                    this->entry,
                    0,
                    0,
                    0,
                    NOTYP,
                    LOC,
                    UND,
                    nullptr,
                    directive->getSymbolList()->at(i)->getSymbol()
                );
                entry++;
                this->symbolTable->push_back(symbolToPatch);
            }
            symbolToPatch->insertFlink({this->currentSection->getLocationCounter(),HYPO_16_BIG,this->currentSection});
            
            this->currentSection->setDataByOffsetByte(currentLocationCounter,0,2);
            this->currentSection->setLocationCounter(
                this->currentSection->getLocationCounter()+2
            );
        }
    }
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
    this->ASMSTATE = END;
    this->currentSection = nullptr;
}

void Assembler::crackASCII(Directive* directive){
    std::string ascii_string = directive->getSectionName();
    if(ascii_string.size() == 2){
        ascii_string = "\0";
    }else{
        ascii_string = ascii_string.substr(1,ascii_string.size()-2);
    }

    
    int size = ascii_string.size();

    int currentLocationCounter = this->currentSection->getLocationCounter();
    this->currentSection->setDataByOffsetRMem(currentLocationCounter,(char*)ascii_string.c_str(),size);
    this->currentSection->setLocationCounter(
        currentLocationCounter + size
    );
}