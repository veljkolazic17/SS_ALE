#include "../inc/Linker.hpp"
#include <string.h>
#include <algorithm>

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

bool exists_string(std::vector<std::string> v, std::string key){
    for(std::string val : v){
        if(key == val){
            return true;
        }
    }
    return false;
}


void Linker::load(std::vector<std::string> input_array){

    number_of_files = input_array.size();

    for(int i = 0;i<number_of_files;i++){


        /* read ith file */
        FILE* cur_file = fopen(input_array.at(i).c_str(),"rb");
        self16_hdr header;
        fread(&header,sizeof(self16_hdr),1,cur_file);

        /* push header of ith file */
        self_headers.push_back(header);

        /* read data from self */
        SElf16_Off self_size = header.se_shsize - sizeof(self16_hdr);
        MEMORY raw = (MEMORY)malloc(self_size);
        fread(raw,self_size,1,cur_file);


        self16_shdr* section_headers_local = (self16_shdr*)(raw + header.se_shoff - sizeof(self16_hdr));
        
        /* extract string_table */
        self16_shdr string_table_header = section_headers_local[header.se_shstrndx-1]; 
        char* string_table = (char*)(raw + string_table_header.sh_offset - sizeof(self16_hdr));
        
        /* push string table */
        string_tables.push_back(string_table);

        /* symbol table */
        slef16_sym* symbol_table;

        /* search for relocation table and symtable */
        for(int j = 0; j < header.se_shnum; j++){
            switch (section_headers_local[j].sh_type){

                case SHT_SYMTAB:{
                    symbol_table = (slef16_sym*)(raw + section_headers_local[j].sh_offset - sizeof(self16_hdr));
                    int symbol_table_size = section_headers_local[j].sh_size / sizeof(slef16_sym);
                    for(int k = 0;k<symbol_table_size;k++){
                        // Don't insert section so they duplicate + you don't know where they star
                        // There is no need to add sections that are local
                        std::string symbol_name =  extract_first_string(string_table,symbol_table[k].st_name);
                        if(symbol_table[k].st_shndx == 0 || symbol_table[k].st_type == SCTN || symbol_table[k].st_binding == LOC){
                            // Add undefined symbol so it can be checked for errors later
                            if(symbol_table[k].st_shndx == 0){
                                undefined.insert(symbol_name);
                            }
                            continue;
                        }

                        __symbol symbol;
                        symbol.name =symbol_name;
                        symbol.value = symbol_table[k].st_value;
                        std::string section_name = extract_first_string(string_table,symbol_table[symbol_table[k].st_shndx - 1].st_name);
                        symbol.section = section_name;
                        symbol.nofile = section_headers[section_name].size() - 1;

                        if(symbols.find(symbol.name) != symbols.end()){
                            printf("MULTIPLE_SYMBOL_DEFINITION_FOUND : %s\n",symbol.name.c_str());
                            exit(MULTIPLE_SYMBOL_DEFINITION_FOUND);
                        }

                        symbols[symbol.name] = symbol;
                    }
                }    
                break;

                case SHT_PROGBITS:{
                    int section_content_size = section_headers_local[j].sh_size;
                    std::string section_name = extract_first_string(string_table,section_headers_local[j].sh_name);

                    if(!exists_string(sections,section_name)){
                        sections.push_back(section_name);
                    }

                    MEMORY section_content = (MEMORY)malloc(section_content_size);
                    memcpy(section_content,(raw + section_headers_local[j].sh_offset - sizeof(self16_hdr)),section_content_size);
                    section_contets[section_name].push_back(section_content);
                    section_headers[section_name].push_back(section_headers_local[j]);
                }
                break;

                case SHT_RELA:{
                    std::string section_name = extract_first_string(string_table,section_headers_local[section_headers_local[j].sh_info-1].sh_name);
                    self16_rela* relocation_table = (self16_rela*)(raw + section_headers_local[j].sh_offset - sizeof(self16_hdr));
                    int relocation_table_size = section_headers_local[j].sh_size / sizeof(self16_rela);
                  
                    for(int k = 0;k<relocation_table_size;k++){
                        int symbol_index = relocation_table[k].r_symbol;
                        __relocation relocation;
                        relocation.offset = relocation_table[k].r_offset;
                        relocation.type = relocation_table[k].r_type;
                        relocation.addent = relocation_table[k].r_addend;
                        relocation.symbol = extract_first_string(string_table,symbol_table[symbol_index-1].st_name);
                        relocation.nofile = section_headers[section_name].size() - 1;


                        relocations[section_name].push_back(relocation);
                    }
                }
                break;
            }
        }
    }

    for(std::pair<std::string,__symbol> symbol : symbols){
        undefined.erase(symbol.first);
    }
    if(undefined.size() > 0){
        printf("NO_SYMBOL_DEFINITION_FOUND :");
        for(std::string symbol : undefined){
            printf(" %s",symbol.c_str());
        }
        printf("\n");
        exit(NO_SYMBOL_DEFINITION_FOUND);
    }
}