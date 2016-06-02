#ifndef BLOCKQUEUEFILLER_H
#define BLOCKQUEUEFILLER_H

#include "blockqueue.h"
#include "options.h"
#include "ThreadManager.hpp"
#include "OS_namespaces.h"

class blockQueueFiller
{
public:
    //Here's the way I deal with threads in OOP:
    /*
     * In the object's constructor, the thread is started
     * In the object's destructor , the thread is joined
     * This ensure that thread lifetime is tied to object lifetime
     * So when we create an instance of this object, we also create a thread with it which ensures
     * that all behaviour of this object is exhibited paralelly
     * */
    thread* _objThread;
    ThreadManager& thread_manager;

    string inPath;
    BlockQueue& target;

    blockQueueFiller(ThreadManager& thread_manager, BlockQueue& targetQueue, string inPath);
    ~blockQueueFiller();
    void test();
    void run(string inPath);
};

#endif // BLOCKQUEUEFILLER_H
