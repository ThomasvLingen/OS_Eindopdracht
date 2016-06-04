//
// Created by mafn on 6/2/16.
//

#include "ThreadManager.hpp"


namespace ATE_Threading {

  ThreadManager::ThreadManager(int max_threads) {
      this->max_threads = max_threads;
      this->thread_count = 0;
  }

  thread* ThreadManager::track_new_thread(thread* to_track) {
      this->threadcount_mutex.lock();
      this->wait_for_available_thread();

      this->thread_count++;
      if (DEBUG) {
          cout << "[THREAD_MANAGER] Tracking thread, new thread count " << this->thread_count << endl;
      }

      this->threadcount_mutex.unlock();
      return to_track;
  }

  void ThreadManager::untrack_thread() {
      this->threadcount_mutex.lock();

      this->thread_count--;
      if (DEBUG) {
          cout << "[THREAD_MANAGER] Untracking thread, new thread count " << this->thread_count << endl;
      }

      this->threadcount_mutex.unlock();
  }

  void ThreadManager::wait_for_available_thread() {
      while (this->thread_count >= this->max_threads) {
          asm("nop");
      }
  }

}