#include "block.hpp"


namespace ATE_BlockQueue {
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

  Block::Block(short ID, short* samples){
      this->ID = ID;
      this->status = Block_status::unprocessed;

      std::copy(samples, samples+1024, this->samples);

  }

  void Block::advance(){
      ++this->status;
  }
}
