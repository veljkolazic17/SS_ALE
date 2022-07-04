#include "../inc/OutputThread.hpp"


OutputThread::OutputThread(Emulator* emulator){
    this->emulator = emulator;
}

void OutputThread::run(){
    char c = 0;
    while(c == 0){
        c = *((short*)(emulator->memory + 0xFF00));
    }
    *((short*)(emulator->memory + 0xFF00)) = 0;
    putc(c,stdout);
}
    