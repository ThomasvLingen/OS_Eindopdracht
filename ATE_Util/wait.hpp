//
// Created by mafn on 6/5/16.
//

#ifndef MAFN_ATE_WAIT_HPP
#define MAFN_ATE_WAIT_HPP

namespace ATE_Util {

  // This is so trivial, we can make it inline to prevent function call overhead
  inline void wait() {
      asm("nop");
  }

}

#endif //MAFN_ATE_WAIT_HPP
