//
// Created by mafn on 6/2/16.
//

#ifndef MAFN_ATE_THREADMANAGER_HPP
#define MAFN_ATE_THREADMANAGER_HPP

#include "OS_namespaces.h"
#include "ATE_Util/wait.hpp"

namespace ATE_Threading {

  class ThreadManager {
  private:
      int thread_count;
      int max_threads;

      // This mutex is for modification of the thread_count variable
      mutex threadcount_mutex;
  public:
      ThreadManager(int max_threads);

      bool thread_available();
      void wait_for_available_thread();

      thread* track_new_thread(thread* to_track);
      void untrack_thread();
  };

}


#endif //MAFN_ATE_THREADMANAGER_HPP
