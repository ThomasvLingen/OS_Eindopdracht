#ifndef BLOCKQUEUEFILLER_H
#define BLOCKQUEUEFILLER_H

#include "ATE_BlockQueue/blockqueue.h"
#include "ATE_Threading/ThreadManager.hpp"
#include "ATE_Threading/ThreadWorker.hpp"
#include "options.h"
#include "OS_namespaces.h"

using ATE_BlockQueue::BlockQueue;

namespace ATE_Threading {

  class blockQueueFiller : public ThreadWorker
  {
  public:
      blockQueueFiller(ThreadManager& thread_manager, BlockQueue& targetQueue, string inPath);
      virtual ~blockQueueFiller();

      string inPath;
      BlockQueue& target;

      virtual void thread_target();
  };

}

#endif // BLOCKQUEUEFILLER_H
