#include "blockqueuefiller.h"

blockQueueFiller::blockQueueFiller(BlockQueue& targetQueue, string inPath) :
    target(targetQueue){

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
