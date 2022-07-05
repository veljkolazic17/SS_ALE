#pragma once
#include "./Thread.hpp"
#include "./Emulator.hpp"
#include <stdio.h>
#include <mutex>


class InputThread : public Thread{
    public:
        InputThread(Emulator*);
        virtual void run();
    private:
        bool end = false;
        Emulator* emulator;
};