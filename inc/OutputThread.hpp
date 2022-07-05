#pragma once
#include "./Thread.hpp"
#include "./Emulator.hpp"
#include <stdio.h>
#include <mutex>


class OutputThread : public Thread{
    public:
        OutputThread(Emulator*);
        virtual void run();
    private:
        bool end = false;
        Emulator* emulator;
};