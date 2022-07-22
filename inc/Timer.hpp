#pragma once
#include "../inc/Emulator.hpp"
#include "../inc/Thread.hpp"


class Timer : public Thread{
    public:
        Timer(Emulator*);
        virtual void run();
    private:
        bool end = false;
        Emulator* emulator;
};