#include "blockqueue.h"

BlockQueue::BlockQueue(ifstream& audiofile){
    streampos size;

    size = audiofile.tellg();

    cout << size << endl;
}
