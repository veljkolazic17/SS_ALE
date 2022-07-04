#include "../inc/InputThread.hpp"


InputThread::InputThread(Emulator* emulator){
    this->emulator = emulator;
}

void InputThread::run(){
    char c;
    while(true){
        c = getchar();
        *((short*)(emulator->memory + 0xFF02)) = c;
        emulator->interupts[TERMINAL] = true;
    }
}
    