//
// Created by mafn on 6/5/16.
//

#ifndef MAFN_ATE_BLOCKPROCESSOR_HPP
#define MAFN_ATE_BLOCKPROCESSOR_HPP

#include "ATE_Threading/ThreadWorker.hpp"
#include "ATE_BlockQueue/blockqueue.h"
#include "ATE_BlockQueue/block.h"

namespace ATE_Threading {
  using ATE_BlockQueue::BlockQueue;
  using ATE_BlockQueue::Block;

  class BlockProcessor : public ThreadWorker {
  public:
      BlockProcessor(ThreadManager& thread_manager, BlockQueue& target);
      virtual ~BlockProcessor();

      virtual void thread_target();
      void process_block(Block* to_process);
  private:

      BlockQueue& target;
  };

}


#endif //MAFN_ATE_BLOCKPROCESSOR_HPP
