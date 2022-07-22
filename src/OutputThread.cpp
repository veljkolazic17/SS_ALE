#include "../inc/OutputThread.hpp"
#include <iostream>

OutputThread::OutputThread(Emulator* emulator){
    this->emulator = emulator;
}

void OutputThread::run(){
    char c;
    while(true){
        pthread_mutex_lock(&emulator->mutex); 
        c = *((short*)(emulator->memory + 0xFF00));
        *((short*)(emulator->memory + 0xFF00)) = 0;
        putc(c,stdout);
        if(emulator->stop){
            pthread_mutex_unlock(&emulator->mutex);
            sem_post(&emulator->continue_sem);
            break;
        }
        pthread_mutex_unlock(&emulator->mutex);
    }
}
    