#pragma once
#include <thread>

class Thread{

protected:
    std::thread *thread = nullptr;
    
public:
    void start();
    void join();
    void stop();

    virtual void run() = 0;
};