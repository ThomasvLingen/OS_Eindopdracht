//
// Created by mafn on 6/2/16.
//

#include "ThreadWorker.hpp"

ThreadWorker::ThreadWorker(ThreadManager& thread_manager)
    : thread_manager(thread_manager)
{
}

ThreadWorker::~ThreadWorker() {
    // Make really damn sure that all our current behaviour has ended
    if (this->_objThread->joinable()) {
        this->_objThread->join();
    }

    delete this->_objThread;
}

void ThreadWorker::run_thread() {
    this->thread_target();

    this->thread_manager.untrack_thread();
}

void ThreadWorker::run() {
    // Start internal thread for run_thread
    // This runs run_thread, which invoked the pure virtual thread_target method
    this->_objThread = this->thread_manager.track_new_thread(new thread(&ThreadWorker::run_thread, this));
}

void ThreadWorker::complete_task() {
    if (this->_objThread->joinable()) {
        this->_objThread->join();
    }
}