//
// Created by mafn on 6/2/16.
//

#ifndef MAFN_ATE_THREADWORKER_HPP
#define MAFN_ATE_THREADWORKER_HPP

#include "OS_namespaces.h"

#include "ThreadManager.hpp"


namespace ATE_Threading {

  class ThreadWorker {
  public:
      ThreadWorker(ThreadManager& thread_manager);
      virtual ~ThreadWorker();

      thread* _objThread;

      void run();
      void complete_task();
  private:
      void run_thread();
  protected:
      //Here's the way I deal with threads in OOP:
      /*
       * In the object's constructor, the thread is started
       * In the object's destructor , the thread is joined
       * This ensure that thread lifetime is at the very least tied to object lifetime
       * So when we create an instance of this object, we also create a thread with it which ensures
       * that all behaviour of this object is exhibited paralelly
       * */
      ThreadManager& thread_manager;

      virtual void thread_target()=0;
  };

}


#endif //MAFN_ATE_THREADWORKER_HPP
