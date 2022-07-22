#pragma once
#include "./SELF.h"
#include "../misc/inc/Codes.h"
#include "../misc/inc/Types.h"
#include <unordered_map>
#include <vector>
#include <string>
#include <set>

#define MULTIPLE_SYMBOL_DEFINITION_FOUND    -2
#define NO_SYMBOL_DEFINITION_FOUND          -3
#define BAD_PLACEMENT                       -4 


class Linker{

    public:
        void link(std::vector<std::string>);
        void _hex(char*);
        void _place(std::string, int);
           
    private:
        void _map();
        void _crack();
        void _finalize();
        void load(std::vector<std::string>);

        void check_placement(unsigned short, unsigned short, std::string);

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
        std::set<std::string> undefined;
        std::unordered_map<std::string,std::vector<__relocation>> relocations;

        /* per file structures */
        std::vector<self16_hdr> self_headers;
        std::vector<char*> string_tables;

        std::unordered_map<std::string,std::vector<MEMORY>> section_contets;
};
