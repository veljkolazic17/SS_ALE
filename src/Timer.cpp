#include "../inc/Timer.hpp"
#include "../inc/Emulator.hpp"

Timer::Timer(Emulator* emulator){
    this->emulator = emulator;
}

ulong map_time(char timeval){
    switch (timeval){
        case 0:
            return 500;
        case 1:
            return 1000;
        case 2:
            return 1500;
        case 3:
            return 2000;
        case 4:
            return 5000;
        case 5:
            return 10000;
        case 6:
            return 30000;
        case 7:
            return 60000;
        default:
            // idk why
            return 100;
    }
}


void Timer::run(){
  while (true){
    short time = *((short*)(emulator->memory + 0xFF10));
    unsigned long sleepTime = map_time(time);
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
    emulator->interupts[TIMER] = true;
  }
}
    
