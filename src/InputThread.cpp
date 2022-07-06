#include "../inc/InputThread.hpp"

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

int getch() {
   struct termios oldtc;
   struct termios newtc;
   int ch;
   tcgetattr(STDIN_FILENO, &oldtc);
   newtc = oldtc;
   newtc.c_lflag &= ~(ICANON | ECHO);
   tcsetattr(STDIN_FILENO, TCSANOW, &newtc);
   ch=getchar();
   tcsetattr(STDIN_FILENO, TCSANOW, &oldtc);
   return ch;
}


InputThread::InputThread(Emulator* emulator){
    this->emulator = emulator;
}

void InputThread::run(){
    char c;    
    while(true){
        c = getch();
        emulator->mymutex->try_lock();
        *((short*)(emulator->memory + 0xFF02)) = c;
        emulator->mymutex->unlock();
        emulator->interupts[TERMINAL] = true;
    }
}
    