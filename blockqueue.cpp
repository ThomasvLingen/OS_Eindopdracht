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
