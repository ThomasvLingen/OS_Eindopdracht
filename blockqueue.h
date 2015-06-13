#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

#include <fstream>
#include <iostream>
#include <vector>

#include "block.h"
#include "OS_namespaces.h"

class BlockQueue
{
public:
    BlockQueue(ifstream& audiofile);
    //To be thrown on the heap using the new keyword
    streampos fileSize;
    vector<Block*> queue;
    void setFileSize(ifstream& audiofile);
    void buildQueue(ifstream& audiofile);
};

#endif // BLOCKQUEUE_H
