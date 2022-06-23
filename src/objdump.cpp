#include "../inc/Assembler.hpp"

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
            printf("%02X",(unsigned int)(this->sections->at(i)->getData(j) & 0xFF));
        }
        printf("\n");
    }
}