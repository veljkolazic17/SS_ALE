#include "../inc/OutputThread.hpp"
#include <iostream>

OutputThread::OutputThread(Emulator* emulator){
    this->emulator = emulator;
}

void OutputThread::run(){
    while(true){
        char c = 0;
        while(c == 0){
            emulator->mymutex->try_lock();
            c = *((short*)(emulator->memory + 0xFF00));
            *((short*)(emulator->memory + 0xFF00)) = 0;
            emulator->mymutex->unlock();
            putc(c,stdout);
        }
        
    }
}
    