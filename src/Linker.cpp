#include "../inc/Linker.hpp"

void Linker::_map(){
    int max_addr = 0;

    /* go trough all that have start address then iterate over those who don't*/
    for(std::pair<std::string,int> addr_pair : section_start_addrs){
        std::string section_name = addr_pair.first;
        int section_addr = addr_pair.second;


        std::vector<self16_shdr>* section_headers_local = &section_headers[section_name];
        int headers_count = section_headers_local->size();
        int cur_section_size = 0;

        for(int i = 0;i<headers_count;i++){
            self16_shdr* cur_section_header = &section_headers_local->at(i);
            
            /* set virtual address */
            cur_section_header->sh_addr = section_addr;
            /* inc section size */
            cur_section_size += cur_section_header->sh_size;
        }

        check_placement(section_addr,section_addr + cur_section_size,section_name);

        /* chek if reached new max address */
        int prob_new_max = cur_section_size + section_addr;
        if(max_addr < prob_new_max){
            max_addr = prob_new_max;
        }
    }
    /* place other section where they belong starting on max address */
    for(std::string section_name : sections){
        if(section_start_addrs.find(section_name) != section_start_addrs.end()){
            continue;
        }
        std::vector<self16_shdr>* section_headers_local = &section_headers[section_name];
        int headers_count = section_headers_local->size();
        int cur_section_size = 0;
        for(int i = 0;i<headers_count;i++){
            self16_shdr* cur_section_header = &section_headers_local->at(i);
            


            /* set virtual address */
            cur_section_header->sh_addr = max_addr;
            /* inc section size */
            cur_section_size += cur_section_header->sh_size;

            
        }
        /* set start addr for each section */
        section_start_addrs[section_name] = max_addr;
        max_addr += cur_section_size;
    }
}

void Linker::_crack(){
    /* set right symbol values */
    for(std::pair<std::string,__symbol> symbol_pair : symbols){
        __symbol* symbol = &symbols[symbol_pair.first];
        symbol->value += section_start_addrs[symbol->section] + find_offset_in_files(symbol->section,symbol->nofile);
    }
    /* insert section symbols */
    for(std::string section_name : sections){
        __symbol section_symbol;
        section_symbol.name = section_name;
        section_symbol.value = section_start_addrs[section_name];
        section_symbol.nofile = -1; // this means that there can be multiple files where section is defined
        section_symbol.section = section_name; 
        symbols[section_name] = section_symbol;
    }
}

void Linker::_finalize(){
    for(std::string section : sections){
        std::vector<__relocation> relocations_local = relocations[section];
        for(__relocation relocation : relocations_local){
            MEMORY section_raw = section_contets[section].at(relocation.nofile);
            
            short insertion_value;

            if(relocation.type == HYPO_REL16){
                insertion_value = symbols[relocation.symbol].value + relocation.addent - (relocation.offset + section_start_addrs[section] + find_offset_in_files(section,relocation.nofile));
            }else{
                insertion_value = symbols[relocation.symbol].value + relocation.addent;
            }

            if(relocation.type != HYPO_16_BIG){
                insertion_value = switch_bytes(insertion_value);
            }
            *(short*)(section_raw + relocation.offset) = insertion_value;
        }
    }
}

void Linker::link(std::vector<std::string> files){
    load(files);
    _map();
    _crack();
    _finalize();
}

int Linker::find_offset_in_files(std::string section,int file_number){
    int offset = 0;
    std::vector<self16_shdr>* grouped_section_headers = &section_headers[section];
    for(int i = 0;i<file_number;i++){
        offset += grouped_section_headers->at(i).sh_size;
    }
    return offset;
}

void Linker::check_placement(unsigned short start, unsigned short end,std::string section){
    for(std::pair<std::string,int> allocated_start : section_start_addrs){
        if(section == allocated_start.first)
            continue;
        if(allocated_start.second >= start && allocated_start.second < end){
            printf("BAD_PLACEMENT : %s X %s\n",allocated_start.first.c_str(), section.c_str());
            exit(BAD_PLACEMENT);
        }
    }
}

void Linker::_place(std::string section, int address){
    this->section_start_addrs[section] = address;
}