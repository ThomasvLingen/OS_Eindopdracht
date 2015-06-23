#include "blockqueue.h"

BlockQueue::BlockQueue(ifstream& audiofile){
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
        audiofile.read((char*)buff, 2048);

        if(audiofile.gcount() < 2048){
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
