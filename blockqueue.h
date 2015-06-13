#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

#include <fstream>
#include <iostream>

#include "OS_namespaces.h"

class BlockQueue
{
public:
    BlockQueue(std::ifstream& audiofile);
};

#endif // BLOCKQUEUE_H
