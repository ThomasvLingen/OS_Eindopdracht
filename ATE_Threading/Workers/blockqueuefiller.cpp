#include "blockqueuefiller.h"


namespace ATE_Threading {

  blockQueueFiller::blockQueueFiller(ThreadManager& thread_manager, BlockQueue& targetQueue, string inPath)
          : ThreadWorker(thread_manager),
            target(targetQueue)
  {
      this->inPath = inPath;

      this->run();
  }

  blockQueueFiller::~blockQueueFiller(){

  }

  void blockQueueFiller::thread_target() {
      ifstream audiofile(this->inPath, ios::in|ios::binary);

      if(audiofile.is_open()){
          this->target.build(audiofile);
      } else{
          cout << "Can't open file with the specified input path, aborting!" << endl;
          abort();
      }
  }

}
