#include "../inc/Thread.hpp"

void Thread::start(){
    if(thread){
        delete thread;
    }   
    thread = new std::thread([this](){run();});
}

void Thread::join(){
    thread->join();
}

void Thread::stop(){
    pthread_cancel(thread->native_handle());
}