#include "../inc/Assembler.hpp"
#include "../inc/SELF.h"
#include <string.h>
#include <stdlib.h>

void Assembler::createSElf(char* obj_filename){

    __u8* data = (__u8*)malloc(sizeof(self16_hdr));
    __u8* string_table = 0;
    __u16 offset = 0;
    __u16 name_offset = 0;



    self16_hdr header = {
        "SELF",             /* SELF "magic number" */
        SELFDATALSB,        /* Data representation type */
        SET_REL,            /* Type of file (always will be REL) */
        0,                  /* Entry virtual address */
        0,                  /* Section header table offset */
        sizeof(self16_hdr), /* Size of SELF header */
        0,                  /* Section header table entry size */
        0,                  /* Section header table number of entries */
        0,                  /* Section name string table index in section header table*/
    };
    offset += sizeof(self16_hdr);

    int sections_size = this->sections->size();
    self16_shdr* section_headers = (self16_shdr*)malloc(sections_size*sizeof(self16_shdr));

    /* writing sections */
    //----------------------------------------------------------------
    for(int i = 0;i<sections_size;i++){
        Section* section = this->sections->at(i);

        /* write name in string table */
        if(string_table == 0){
            string_table = (__u8*)malloc((section->sectionName.length()+1)*sizeof(__u8));
        }else{
            string_table = (__u8*)realloc(string_table,name_offset+section->sectionName.length());
        }
        memcpy(string_table+name_offset,(section->sectionName+'\0').c_str(),section->sectionName.length()+1);
       
        /* create section header */
        section_headers[i] = {
            name_offset,
            SHT_PROGBITS, // CHECK IF THIS IS GOOD
            0,
            offset,
            (__u16)section->dataSize,
            0,
            0,
            0
        };

        name_offset += section->getSectionName().length()+1;
        
        /* write section data */
        data = (__u8*)realloc(data,offset+section->dataSize);
        memcpy(
            data+offset,
            section->data,
            section->dataSize
        );
        offset += section->dataSize;
    }
    //----------------------------------------------------------------
    

    /* write symbol table elements */
    //----------------------------------------------------------------
    SElf16_Word symbol_table_size = this->symbolTable->size(); 
    SElf16_Word symbol_table_size_bytes = symbol_table_size*sizeof(slef16_sym);
    slef16_sym* symbol_table_section = (slef16_sym*)malloc(symbol_table_size_bytes);

    self16_shdr symbol_table_header;
    SElf16_Half last_index = 0;

    if(symbol_table_size){
        for(int i = 0;i<symbol_table_size;i++){
            SymbolTableElement* symbolTableElement = this->symbolTable->at(i);
            string_table = (__u8*)realloc(string_table,name_offset+symbolTableElement->getSymbolName().length()+1);
            memcpy(
                string_table+name_offset,
                (symbolTableElement->getSymbolName() + '\0').c_str(),
                symbolTableElement->getSymbolName().length()+1
            );


            /* undefined section (extern symbol) */
            SElf16_Off ndx = 0;
            if(symbolTableElement->getSection()){
                ndx = symbolTableElement->getSection()->getSymbolTableEntry()->getNum();
                last_index = ndx;
            }
            symbol_table_section[i] = {
                name_offset,
                (SElf16_Half)symbolTableElement->getBinding(),
                (SElf16_Half)symbolTableElement->getType(),
                ndx,
                (SElf16_Sword)symbolTableElement->getValue(),
                (SElf16_Word)symbolTableElement->getSize()
            };
            name_offset += symbolTableElement->getSymbolName().length()+1;
        }
         /* symbol table header */
        symbol_table_header = {
            0,
            SHT_SYMTAB,
            0,
            offset,
            symbol_table_size_bytes,
            0,
            last_index,
            sizeof(slef16_sym)
        };
        data = (__u8*)realloc(data,offset+symbol_table_size_bytes);
        memcpy(
            data+offset,
            symbol_table_section,
            symbol_table_size_bytes
        );
        offset += symbol_table_size_bytes;
    }
    //----------------------------------------------------------------

   

    /* write relocation section */
    //----------------------------------------------------------------
    self16_shdr* relocation_headers;
    int number_of_relocation_headers = 0;

    relocation_headers = (self16_shdr*)malloc(sections_size*sizeof(self16_shdr));
    for(int i = 0;i<sections_size;i++){
        Section* section = this->sections->at(i);
        /* relocations for this section */
        int relocations_per_section_size = section->relocationTable.size();
        int relocations_per_section_size_byte = relocations_per_section_size*sizeof(self16_rela);

        self16_rela* relocations_section = (self16_rela*)malloc(relocations_per_section_size_byte);
        for(int j = 0;j<relocations_per_section_size;j++){

            RelocationTableElement relocationTableElement = section->getRelocationTableElement(j);

            relocations_section[j] = {
                (SElf16_Addr)relocationTableElement.offset,
                (SElf16_Word)relocationTableElement.addend,
                relocationTableElement.type,
                (SElf16_Off)relocationTableElement.symbol->getNDX()
            };
        }

        /* write relocations of section i  */
        if(relocations_per_section_size){
            data = (__u8*)realloc(data,offset+relocations_per_section_size_byte);

            memcpy(
                data+offset,
                relocations_section,
                relocations_per_section_size_byte
            );
            
            relocation_headers[number_of_relocation_headers].sh_type = SHT_RELA;
            relocation_headers[number_of_relocation_headers].sh_offset = offset;
            relocation_headers[number_of_relocation_headers].sh_size = relocations_per_section_size_byte;
            relocation_headers[number_of_relocation_headers].sh_link = sections_size +1; //CHECK IF RIGHT
            relocation_headers[number_of_relocation_headers].sh_info = i+1;
            relocation_headers[number_of_relocation_headers].sh_entsize = sizeof(self16_rela);
            number_of_relocation_headers++;
            
            offset += relocations_per_section_size_byte;   
        }
    }
    
    //----------------------------------------------------------------
    


    /* writing string name table */
    //----------------------------------------------------------------
    data = (__u8*)realloc(data,offset+name_offset);
    memcpy(
        data+offset,
        string_table,
        name_offset
    );
    self16_shdr string_table_header;
    string_table_header.sh_type = SHT_STRTAB;
    string_table_header.sh_offset = offset;
    string_table_header.sh_size = name_offset;

    offset+=name_offset;
    //----------------------------------------------------------------


    /* write section headers */
    //----------------------------------------------------------------
    /* write where section header table begins */
    header.se_shoff = offset;

    /* write section headers */
    SElf16_Off temp_size1 = sections_size*sizeof(self16_shdr);
    SElf16_Off temp_size2 = number_of_relocation_headers*sizeof(self16_shdr);
    /* sections + realloc + symtable + stringtalbe */
    size_t realloc_size = (sections_size +  2 + number_of_relocation_headers)*sizeof(self16_shdr);

    data = (__u8*)realloc(data,offset+realloc_size);
    
    /* write section headers */
    memcpy(
        data+offset,
        section_headers,
        temp_size1
    );
    offset += temp_size1;

    /* write symbol table section header */
    memcpy(
        data+offset,
        &symbol_table_header,
        sizeof(self16_shdr)
    );
    offset += sizeof(self16_shdr);

    /* write relocations header */
    memcpy(
        data+offset,
        relocation_headers,
        temp_size2
    );
    offset += temp_size2;

    /* write string name table header */
    memcpy(
        data+offset,
        &string_table_header,
        sizeof(self16_shdr)
    );
    offset += sizeof(self16_shdr);
    //----------------------------------------------------------------
    
    header.se_shentsize = realloc_size;
    header.se_shsize = offset;
    header.se_shnum = sections_size + 2 + number_of_relocation_headers;
    header.se_shstrndx =sections_size + 1 + number_of_relocation_headers + 1;

    memcpy(data,&header,sizeof(header));

    FILE* obj_file = fopen(obj_filename,"wb+");
    fwrite(data,1,offset,obj_file);
    fclose(obj_file);
}