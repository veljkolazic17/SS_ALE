#include "../inc/Linker.hpp"


void Linker::_hex(char* filename){
    FILE* hex_file = fopen(filename,"w+");
    bool should_skip = true;
    for(std::string section : sections){
        int start_addr = section_start_addrs[section];
        std::vector<self16_shdr>* local_section_headers = &section_headers[section];
        int headers_count = local_section_headers->size();

        int j = 0;
        int section_size = 0;

        for(int i = 0;i<headers_count;i++){
            MEMORY section_raw = section_contets[section].at(i);
            section_size += local_section_headers->at(i).sh_size;
            for(;j<section_size;j++){
                if(j%8 == 0){
                    if(!should_skip){
                        fprintf(hex_file,"\n");
                    }else{
                        should_skip = false;
                    }
                    fprintf(hex_file,"%04X: ",(unsigned  int)(start_addr & 0xFFFF));
                    start_addr+=8;
                }
                else{
                    fprintf(hex_file," ");
                }
                fprintf(hex_file,"%02X",(unsigned int)(section_raw[j] & 0xFF));
            }
        }
    }
    fclose(hex_file);
}