#include "../inc/Linker.hpp"


void Linker::_hex(char* filename){
    FILE* hex_file = fopen(filename,"w+");

    bool first = true;
    int cnt = 0;
    int global_addr = -1;

    for(std::string section : sections){
        int start_addr = section_start_addrs[section];
        std::vector<self16_shdr>* local_section_headers = &section_headers[section];
        int headers_count = local_section_headers->size();

        if(start_addr != global_addr){
            global_addr = start_addr;
            cnt = 0;
        }

        for(int i = 0;i<headers_count;i++){
            MEMORY section_raw = section_contets[section].at(i);
            int section_size = local_section_headers->at(i).sh_size;
            for(int j = 0;j<section_size;j++,cnt++){
                if(cnt%8 == 0){
                    if(!first){
                         fprintf(hex_file,"\n");
                    }else{
                        first = false;
                    }         
                    fprintf(hex_file,"%04X: ",(unsigned  int)(global_addr & 0xFFFF));
                }
                else{
                    fprintf(hex_file," ");
                }
                fprintf(hex_file,"%02X",(unsigned int)(section_raw[j] & 0xFF));
                global_addr++;
            }
        }
    }
    fclose(hex_file);
}