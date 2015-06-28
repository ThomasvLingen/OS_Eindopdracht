#include "blockqueuefiller.h"

blockQueueFiller::blockQueueFiller(BlockQueue& targetQueue, string inPath)
    :target(targetQueue){

    //Start internal thread
    this->_objThread = new thread(&blockQueueFiller::run, this, inPath);
}

blockQueueFiller::~blockQueueFiller(){
    //Make really fucking sure that all our current behaviour has ended
    this->_objThread->join();
}

void blockQueueFiller::run(string inPath){
    ifstream audiofile(inPath, ios::in|ios::binary);

    if(audiofile.is_open()){
        this->target.build(audiofile);
    } else{
        cout << "Can't open file with the specified input path, aborting!" << endl;
        abort();
    }
}

void blockQueueFiller::test(){

}
