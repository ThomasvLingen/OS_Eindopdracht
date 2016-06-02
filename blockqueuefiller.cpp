#include "blockqueuefiller.h"

blockQueueFiller::blockQueueFiller(ThreadManager& thread_manager, BlockQueue& targetQueue, string inPath)
    :target(targetQueue),
    thread_manager(thread_manager)
{
    //Start internal thread
    this->_objThread = this->thread_manager.track_new_thread(new thread(&blockQueueFiller::run, this, inPath));
}

blockQueueFiller::~blockQueueFiller(){
    //Make really fucking sure that all our current behaviour has ended
    if (this->_objThread->joinable()) {
        this->_objThread->join();
    }

    delete this->_objThread;
}

void blockQueueFiller::run(string inPath){
    ifstream audiofile(inPath, ios::in|ios::binary);

    if(audiofile.is_open()){
        this->target.build(audiofile);
    } else{
        cout << "Can't open file with the specified input path, aborting!" << endl;
        abort();
    }

    this->thread_manager.untrack_thread();
}

void blockQueueFiller::test(){

}
