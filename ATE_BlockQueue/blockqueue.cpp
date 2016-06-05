#include "blockqueue.h"


namespace ATE_BlockQueue {
  BlockQueue::BlockQueue(){
      this->nextBlockToProcess = 0;
      this->is_filled = false;
  }

  BlockQueue::~BlockQueue() {
      for (Block* block : this->queue) {
          delete block;
      }
  }

  void BlockQueue::build(ifstream &audiofile){
      this->setFileSize(audiofile);

      this->buildQueue(audiofile);

      this->mark_as_filled();
  }

  void BlockQueue::setFileSize(ifstream &audiofile){
      audiofile.seekg(0, ios::end);
      this->fileSize = audiofile.tellg();
      audiofile.seekg (0, ios::beg);
  }

  void BlockQueue::add_to_queue(Block* to_add) {
      this->block_mutex.lock();

      this->queue.push_back(to_add);

      if (DEBUG) {
          cout << "[QUEUE] ADDING " << to_add->ID << endl;
      }

      this->block_mutex.unlock();
  }

  Block* BlockQueue::get_next_block_to_process() {
      Block* next_block_to_process;

      this->block_mutex.lock();

      if (this->blockAvailableToProcess()) {
          next_block_to_process = this->queue[this->nextBlockToProcess];

          if (DEBUG) {
              cout << "[QUEUE] GIVING OUT " << next_block_to_process->ID << endl;
          }

          this->nextBlockToProcess++;
      } else {
          next_block_to_process = nullptr;
      }

      this->block_mutex.unlock();

      return next_block_to_process;
  }

  void BlockQueue::buildQueue(ifstream &audiofile){
      short currentBlockID = 0;

      short* buff = new short[1024];

      while (audiofile.tellg() != -1){
          audiofile.read((char*)buff, sizeof(short[1024]));

          if(audiofile.gcount() < sizeof(short[1024])){
              //This indicates we had our last read
              break;
          }

          this->add_to_queue(new Block(currentBlockID, buff));
          currentBlockID++;
      }

      delete[] buff;
  }

  void BlockQueue::writeQueueToFile(string filename){
      ofstream outputFile(filename , ofstream::binary);

      for(Block* block : this->queue){
          outputFile.write((char*)&block->samples, sizeof(block->samples));
      }
  }

  void BlockQueue::writeQueueToFileBackwards(string filename){
      ofstream outputFile(filename , ofstream::binary);

      for(int i = this->queue.size()-1; i >= 0; i--){
          outputFile.write((char*)&this->queue[i]->samples, 2048);
      }
  }

  void BlockQueue::mark_as_filled() {
      this->is_filled = true;
  }

  bool BlockQueue::is_processed() {
      return this->is_filled && this->all_blocks_processed();
  }

  bool BlockQueue::all_blocks_processed() {
      for (Block* block : this->queue) {
          if (block->status != Block_status::processed) {
              return false;
          }
      }

      return true;
  }

  bool BlockQueue::blockAvailableToProcess(){
      bool not_empty = this->queue.size() > 0;
      bool block_left = this->nextBlockToProcess <= this->queue.size()-1;

      return not_empty && block_left;
  }

}
