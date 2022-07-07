#include "../inc/Emulator.hpp"

int main(int argc, char** argv){
    std::string filename(argv[1]);
    Emulator emulator;
    emulator.start(filename);
    exit(0);
    return 0;
}

//valgrind --tool=memcheck  --show-reachable=yes --input-fd=0 ./emulator ./tests/equ_test.hex