#pragma once
#include "./SELF.h"
#include "../misc/inc/Codes.h"
#include "../misc/inc/Types.h"
#include <unordered_map>
#include <vector>
#include <string>

#define MULTIPLE_SYMBOL_DEFINITION -2


class Linker{

    public:
        void link(int, char**);
        void _hex(char*);
           
    private:
        void _map();
        void _crack();
        void _finalize();
        void load(int, char**);

        int find_offset_in_files(std::string,int);
    private:
        struct __symbol{
            std::string name;
            short value;
            std::string section;
            int nofile;
        };
        struct __relocation
        {
            short offset;
            char type;
            std::string symbol;
            short addent;
            int nofile;
        };

    private:

        int number_of_files;

        /* helper structures */
        std::unordered_map<std::string,int> section_start_addrs;
        std::vector<std::string> sections;
        std::unordered_map<std::string,std::vector<self16_shdr>> section_headers;

        std::unordered_map<std::string,__symbol> symbols;
        std::unordered_map<std::string,std::vector<__relocation>> relocations;

        /* per file structures */
        std::vector<self16_hdr> self_headers;
        std::vector<char*> string_tables;

        std::unordered_map<std::string,std::vector<MEMORY>> section_contets;
};
