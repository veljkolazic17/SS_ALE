#include "../inc/Emulator.hpp"

int main(int argc, char** argv){
    std::string filename(argv[1]);
    Emulator emulator;
    emulator.start(filename);
}