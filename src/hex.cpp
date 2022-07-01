#include "../inc/Linker.hpp"


void Linker::_hex(char* filename){
    FILE* hex_file = fopen(filename,"w+");

    int cnt = 0;

    for(std::string section : sections){
        int start_addr = section_start_addrs[section];
        std::vector<self16_shdr>* local_section_headers = &section_headers[section];
        int headers_count = local_section_headers->size();

        for(int i = 0;i<headers_count;i++){
            MEMORY section_raw = section_contets[section].at(i);
            int section_size = local_section_headers->at(i).sh_size;
            for(int j = 0;j<section_size;j++,cnt++){
                if(cnt%8 == 0){
                    if(cnt != 0){
                         fprintf(hex_file,"\n");
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