#include "blockqueue.h"


namespace ATE_BlockQueue {
  BlockQueue::BlockQueue(){
      this->nextBlockToProcess = 0;
  }

  void BlockQueue::build(ifstream &audiofile){
      this->setFileSize(audiofile);

      this->buildQueue(audiofile);
  }

  void BlockQueue::setFileSize(ifstream &audiofile){
      audiofile.seekg(0, ios::end);
      this->fileSize = audiofile.tellg();
      audiofile.seekg (0, ios::beg);
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

          this->queue.push_back(new Block(currentBlockID, buff));
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

  // Consumer has to increment nextBlockToProcess once it starts working on a block!
  // Mutex needed?
  bool BlockQueue::blockAvailableToProcess(){
      return this->queue.size() > 0 && this->nextBlockToProcess <= this->queue.size()-1;
  }

}
