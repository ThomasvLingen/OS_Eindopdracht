#include "OS_namespaces.h"

#include "ATE_Util/options.h"
#include "ATE_Util/coefficients.h"
#include "ATE_BlockQueue/blockqueue.h"
#include "ATE_Threading/Workers/blockqueuefiller.h"
#include "ATE_Threading/Workers/BlockProcessor.hpp"
#include "ATE_Util/wait.hpp"

using ATE_Util::Options;
using ATE_Util::Coefficients;
using ATE_Util::CoefficientType;
using ATE_Threading::ThreadManager;
using ATE_Threading::blockQueueFiller;
using ATE_Threading::BlockProcessor;

int main(int argc, char* argv[]){

    Options opt(argc, argv);
    Coefficients bass(opt.bassIntensity, CoefficientType::bass);
    Coefficients treble(opt.trebleIntensity, CoefficientType::treble);
    BlockQueue queue;
    ThreadManager thread_manager(opt.threads);

    if (opt.threads < 1) {
        cout << "[ERROR] This application needs at least 1 thread to work";
        exit(EXIT_FAILURE);
    }

    if (DEBUG) {
        cout << "Spawning new producer thread" << endl;
    }
    blockQueueFiller producer(thread_manager, queue, opt.inPath);
    vector<BlockProcessor*> consumers;

    // If after making a producer threads there are no more threads available, producer should finish its task first!
    if (!thread_manager.thread_available()) {
        producer.complete_task();
    }

    while (!queue.is_processed()) {
        if (thread_manager.thread_available()) {
            if (DEBUG) {
                cout << "Spawning new consumer thread" << endl;
            }

            consumers.push_back(new BlockProcessor(thread_manager, queue));
        }

        ATE_Util::wait();
    }

    queue.writeQueueToFile(opt.outPath);

    return 0;
}

