#include "../inc/Linker.hpp"
#include <string.h>

std::string extract_first_string(char* str, int offset){
    char* start = str + offset;
    int i = 0;
    std::string res = "";
    while(start[i] != '\0'){
        res += start[i];
        i++;
    }
    return res;
}


void Linker::load(int argc, char** argv){
    for(int i = 0;i<argc;i++){


        /* read ith file */
        FILE* cur_file = fopen(argv[i],"rb");
        self16_hdr header;
        fread(&header,sizeof(self16_hdr),1,cur_file);

        /* push header of ith file */
        self_headers.push_back(header);

        /* read data from self */
        SElf16_Half self_size = header.se_shsize - HEADER_OFFSET;
        MEMORY raw = (MEMORY)malloc(self_size);
        fread(raw,self_size,1,cur_file);


        self16_shdr* section_headers_local = (self16_shdr*)(raw + header.se_shoff - HEADER_OFFSET);
        
        /* extract string_table */
        self16_shdr string_table_header = section_headers_local[header.se_shstrndx-1]; 
        char* string_table = (char*)(raw + string_table_header.sh_offset - HEADER_OFFSET);
        
        /* push string table */
        string_tables.push_back(string_table);


        /* push needed structures */
        section_headers.push_back(std::vector<self16_shdr>());
        symbol_tables.push_back(std::vector<slef16_sym>());

        /* search for relocation table and symtable */
        for(int j = 0; j < header.se_shnum; j++){
            switch (section_headers_local[j].sh_type){

                case SHT_SYMTAB:{
                    slef16_sym* symbol_table = (slef16_sym*)(raw + section_headers_local[j].sh_offset - HEADER_OFFSET);
                    int symbol_table_size = section_headers_local[j].sh_size / sizeof(slef16_sym);
                    for(int k = 0; k < symbol_table_size;k++){
                        symbol_tables.at(i).push_back(symbol_table[k]);
                    }
                }    
                break;

                case SHT_PROGBITS:{
                    int section_content_size = section_headers_local[j].sh_size;
                    std::string section_name = extract_first_string(string_table,section_headers_local[j].sh_name);
                    MEMORY section_content = (MEMORY)malloc(section_content_size);
                    memcpy(section_content,(raw + section_headers_local[j].sh_offset - HEADER_OFFSET),section_content_size);
                    section_contets[section_name].push_back(section_content);
                }
                break;

                case SHT_RELA:{
                    std::string section_name = extract_first_string(string_table,section_headers_local[section_headers_local[j].sh_info-1].sh_name);
                    self16_rela* relocation_table = (self16_rela*)(raw + section_headers_local[j].sh_offset - HEADER_OFFSET);
                    int relocation_table_size = section_headers_local[j].sh_size / sizeof(self16_rela);
                    for(int k = 0;k < relocation_table_size;k++){
                        relocation_tables[section_name].push_back(relocation_table[k]);
                    }
                }
                break;
            }
        }
    }
}

