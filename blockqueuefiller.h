#ifndef BLOCKQUEUEFILLER_H
#define BLOCKQUEUEFILLER_H

#include "blockqueue.h"
#include "options.h"
#include "OS_namespaces.h"

#include <thread>

class blockQueueFiller
{
public:
    blockQueueFiller(BlockQueue& targetQueue, string inPath);
    std::thread* _internalThread;

    string inPath;
    BlockQueue& target;
    void test();
};

#endif // BLOCKQUEUEFILLER_H
