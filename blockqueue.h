#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "block.h"
#include "OS_namespaces.h"

class BlockQueue
{
public:
    BlockQueue();
    //To be thrown on the heap using the new keyword
    streampos fileSize;
    vector<Block*> queue;

    int nextBlockToProcess;

    bool blockAvailableToProcess();
    void build(ifstream& audiofile);
    void setFileSize(ifstream& audiofile);
    void buildQueue(ifstream& audiofile);
    void writeQueueToFile(string filename);
    void writeQueueToFileBackwards(string filename);
};

#endif // BLOCKQUEUE_H
