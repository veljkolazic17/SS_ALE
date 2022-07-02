#include "../inc/Linker.hpp"
#include <string>
#include <limits.h>

#define PLACE_OPTION_LEN    7
#define INVALID_ADDRESS     -1

void place(Linker* linker, std::string place){
    int _target = place.find_last_of('@');
    std::string section_name = place.substr(7, _target - PLACE_OPTION_LEN);

    std::string addr_str = place.substr(_target + 1);
    int addr;
    if(addr_str.at(1) == 'x') addr = std::stoi(addr_str,nullptr,16);
    else addr = std::stoi(addr_str);
    if(addr < 0 || addr >= USHRT_MAX){
        printf("INVALID_ADDRESS\n");
        exit(INVALID_ADDRESS);
    }
    linker->_place(section_name,addr);
}


int main(int argc, char** argv){

    std::vector<std::string> input_array;
    std::string out_filename;
    bool should_hex = false;

    Linker linker;

    for(int i = 1;i<argc;i++){
        std::string arg(argv[i]);
        if(arg[0] == '-'){
            if(arg[1] == 'p'){
                place(&linker,arg);
            }else if(arg[1] == 'o'){
                i++;
                out_filename = std::string(argv[i]);
            }else if(arg[1] == 'h'){
                should_hex = true;
            }
        }
        else{
           input_array.push_back(arg);
        }
    }

    linker.link(input_array);

    if(should_hex){
        linker._hex((char*)out_filename.c_str());
    }
    return 0;
}