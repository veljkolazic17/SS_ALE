#pragma once
#include "./SELF.h"
#include "../misc/inc/Codes.h"
#include "../misc/inc/Types.h"
#include <unordered_map>
#include <vector>
#include <string>


class Linker{

    public:
        void load(int, char**);

    private:
       
        void scoop_header();
        int number_of_files;
        
        // std::unordered_map<std::string,std::vector<int>> section_map;

        std::unordered_map<std::string,int> section_addr_map;
        std::vector<self16_hdr> self_headers;
        std::vector<std::vector<self16_shdr>> section_headers;
        std::vector<std::vector<slef16_sym>> symbol_tables;
        std::unordered_map<std::string,std::vector<self16_rela>> relocation_tables;
        std::vector<char*> string_tables;

        std::unordered_map<std::string,std::vector<MEMORY>> section_contets;

        // std::vector<std::string, std::vector<self16_rela>> relocations;


        MEMORY memory;

};
