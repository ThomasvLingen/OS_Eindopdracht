#ifndef BLOCK_H
#define BLOCK_H

#include <iterator>


namespace ATE_BlockQueue {
  enum class Block_status{unprocessed, b_done, t_done, processed};

  Block_status& operator++(Block_status& s);
  std::ostream& operator<<(std::ostream& os, Block_status s);

  class Block
  {
  public:
      Block(short ID, short* samples);
      short ID;
      short samples[1024];
      Block_status status;

      void advance();
  };
}


#endif // BLOCK_H
