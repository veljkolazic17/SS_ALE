#include "../inc/Emulator.hpp"
#include "../misc/inc/Types.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>

void Emulator::load(std::string filename){

    std::fstream file;
    file.open(filename,std::ios::in);
    

    if(file.is_open()){
        std::string line;
        char delimiter = ' ';
        while(getline(file,line)){
            
            /* should not happen */
            size_t string_end = line.find(":");
            if(string_end > 4){
                printf("\nprogram could not be loaded\n");
            } 

            unsigned short addr = std::stoul(line.substr(0,4), nullptr, 16);

            line = line.substr(6, line.length());


            size_t start;
            size_t end = 0;
            unsigned short offset = 0;

            while ((start = line.find_first_not_of(delimiter, end)) != std::string::npos)
            {
                end = line.find(delimiter, start);
                std::string token = line.substr(start, end - start);

                BYTE data_byte;
                data_byte = std::stoul(line.substr(start,end-start), nullptr, 16);
                *(memory + addr + offset++)=data_byte;
            }

        }
    }
    this->registers[IP] = *(SYSREG*)(memory);
    file.close();
}