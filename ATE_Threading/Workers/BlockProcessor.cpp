//
// Created by mafn on 6/5/16.
//

#include "BlockProcessor.hpp"


namespace ATE_Threading {

  BlockProcessor::BlockProcessor(ThreadManager& thread_manager, BlockQueue &target)
          : ThreadWorker(thread_manager),
            target(target)
  {
      this->run();
  }

  BlockProcessor::~BlockProcessor() {

  }

  void BlockProcessor::thread_target() {
      while (!target.is_processed()) {
          Block* to_process = target.get_next_block_to_process();

          if (to_process) {
              this->process_block(to_process);
          }
      }
  }

  void BlockProcessor::process_block(Block *to_process) {
      if (DEBUG) {
          cout << "[WORKER] Processing " << to_process->ID << endl;
      }

      to_process->status = ATE_BlockQueue::Block_status::processed;
  }

}