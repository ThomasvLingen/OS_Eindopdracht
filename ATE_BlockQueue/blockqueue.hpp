#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <mutex>

#include "block.hpp"
#include "OS_namespaces.h"

namespace ATE_BlockQueue {
  class BlockQueue
  {
  public:
      BlockQueue();
      virtual ~BlockQueue();

      //To be thrown on the heap using the new keyword
      streampos fileSize;
      vector<Block*> queue;

      int nextBlockToProcess;
      bool is_filled;

      bool blockAvailableToProcess();
      void add_to_queue(Block* to_add);
      Block* get_next_block_to_process();

      bool is_processed();
      bool all_blocks_processed();
      void mark_as_filled();

      void build(ifstream& audiofile);
      void setFileSize(ifstream& audiofile);
      void buildQueue(ifstream& audiofile);

      void writeQueueToFile(string filename);
      void writeQueueToFileBackwards(string filename);
  private:
      // This mutex is for operations on the block_queue (get and add)
      std::mutex block_mutex;
  };
}

#endif // BLOCKQUEUE_H
