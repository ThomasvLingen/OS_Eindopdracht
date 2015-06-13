#include "block.h"

Block_status& operator++(Block_status& s){
    switch(s){
        case Block_status::unprocessed: return s = Block_status::b_done;
        case Block_status::b_done:      return s = Block_status::t_done;
        case Block_status::t_done:      return s = Block_status::processed;
        default: break;
    }
}

std::ostream& operator<<(std::ostream& os, Block_status s){
    switch(s){
        case Block_status::unprocessed: os << "Block_status::unprocessed"; return os;
        case Block_status::b_done: os << "Block_status::b_done"; return os;
        case Block_status::t_done: os << "Block_status::t_done"; return os;
        case Block_status::processed: os << "Block_status::processed"; return os;
    }
}

//Oh lord what have I done    V Abomination of a syntax
Block::Block(short ID, short (&samples)[1024]){
    this->ID = ID;
    this->status = Block_status::unprocessed;

    std::copy(std::begin(samples), std::end(samples), std::begin(this->samples));
}

void Block::advance(){
    ++this->status;
}
