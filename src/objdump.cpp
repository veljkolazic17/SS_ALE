#include "../inc/Assembler.hpp"

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define RESET   "\033[0m"
typedef std::string COLOR;

COLOR COLORS[] = {
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE
};

void Assembler::objdump(){
    /**
     * @brief print symbol tables
     * 
     */
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
    /**
     * @brief print sections
     * 
     */
    int sectionsSize = this->sections->size();
    for(int i = 0;i<sectionsSize;i++){
        Section* section = this->sections->at(i);
        std::cout<<COLORS[i%5];
        printf("%s",("#."+section->getSectionName()).c_str());
        int dataSize = section->getDataSize();
        int counter = 0;
        for(int j = 0;j<dataSize;j++){
            if(j%8 == 0){
                printf("\n");
                printf("%04X: ",(unsigned  int)(counter & 0xFFFF));
                counter+=8;
            }
            else{
                printf(" ");
            }
            printf("%02X",(unsigned int)(section->getData(j) & 0xFF));
        }
        int realocationTableSize = section->getRelocationTableSize();
        if(realocationTableSize){
            printf("\n\n#.rela.%s\n",section->getSectionName().c_str());
            printf("OFFSET\t\tTYPE\t\t\tSYMBOL\tADDEND\n");
            for(int j = 0;j<realocationTableSize;j++){
                std::string type;
                RelocationTableElement relocationTableElement = section->getRelocationTableElement(j);
                switch (relocationTableElement.type){
                    case R_X86_64_16:
                        type = "R_X86_64_16";
                        break;
                    case R_X86_64_PC16:
                        type = "R_X86_64_PC16";
                        break;
                    case R_X86_64_PLT16:
                        type = "R_X86_64_PLT16";
                        break;
                }
                printf(
                    "%08x\t%s\t\t%s\t%d\n",
                    relocationTableElement.offset,
                    type.c_str(),
                    relocationTableElement.symbol->getSymbolName().c_str(),
                    relocationTableElement.addend
                );
            }     
        }else{
            printf("\n");
        }
        std::cout<<RESET;
    }
}