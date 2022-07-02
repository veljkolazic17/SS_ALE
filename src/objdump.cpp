#include "../inc/Assembler.hpp"

// #define RED     "\033[0;31m"
// #define GREEN   "\033[0;32m"
// #define YELLOW  "\033[0;33m"
// #define BLUE    "\033[0;34m"
// #define PURPLE  "\033[0;35m"
// #define RESET   "\033[0m"
// typedef std::string COLOR;

// COLOR COLORS[] = {
//     RED,
//     GREEN,
//     YELLOW,
//     BLUE,
//     PURPLE
// };

void Assembler::objdump(char* filename){
    /**
     * @brief print symbol tables
     * 
     */

    FILE* file = fopen(filename,"w+");

    if(file == 0){
        printf("ERROR_LOADING_FILE\n");
        exit(-1);
    }

    fprintf(file,"NUM\tVALUE\t\tSIZE\tTYPE\tBIND\tNDX\tNAME\n");
    int symbolTableSize = this->symbolTable->size();
    for(int i = 0;i<symbolTableSize;i++){
        SymbolTableElement* ste = this->symbolTable->at(i);
        fprintf(
            file,
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
        // std::cout<<COLORS[i%5];
        fprintf(file,"%s",("#."+section->getSectionName()).c_str());
        int dataSize = section->getDataSize();
        int counter = 0;
        for(int j = 0;j<dataSize;j++){
            if(j%8 == 0){
                fprintf(file,"\n");
                fprintf(file,"%04X: ",(unsigned  int)(counter & 0xFFFF));
                counter+=8;
            }
            else{
                fprintf(file," ");
            }
            fprintf(file,"%02X",(unsigned int)(section->getData(j) & 0xFF));
        }
        int realocationTableSize = section->getRelocationTableSize();
        if(realocationTableSize){
            fprintf(file,"\n\n#.rela.%s\n",section->getSectionName().c_str());
            fprintf(file,"OFFSET\t\tTYPE\t\t\tSYMBOL\tADDEND\n");
            for(int j = 0;j<realocationTableSize;j++){
                std::string type;
                RelocationTableElement relocationTableElement = section->getRelocationTableElement(j);
                switch (relocationTableElement.type){
                    case HYPO_16:
                        type = "HYPO_16  ";
                        break;
                    case HYPO_PC16:
                        type = "HYPO_PC16";
                        break;
                    case HYPO_REL16:
                        type = "HYPO_REL16";
                        break;
                }
                fprintf(
                    file,
                    "%08x\t%s\t\t%s\t%d\n",
                    relocationTableElement.offset,
                    type.c_str(),
                    relocationTableElement.symbol->getSymbolName().c_str(),
                    relocationTableElement.addend
                );
            }     
        }else{
            fprintf(file,"\n");
        }
        // std::cout<<RESET;
    }
    fclose(file);
}