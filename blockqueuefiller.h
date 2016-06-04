#ifndef BLOCKQUEUEFILLER_H
#define BLOCKQUEUEFILLER_H

#include "ATE_BlockQueue/blockqueue.h"
#include "options.h"
#include "ThreadManager.hpp"
#include "ThreadWorker.hpp"
#include "OS_namespaces.h"

using ATE_BlockQueue::BlockQueue;

class blockQueueFiller : public ThreadWorker
{
public:
    blockQueueFiller(ThreadManager& thread_manager, BlockQueue& targetQueue, string inPath);
    virtual ~blockQueueFiller();

    string inPath;
    BlockQueue& target;

    virtual void thread_target();
};

#endif // BLOCKQUEUEFILLER_H
