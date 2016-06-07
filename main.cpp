#include "OS_namespaces.h"

#include "ATE_Util/options.hpp"
#include "ATE_Util/coefficients.hpp"
#include "ATE_BlockQueue/blockqueue.hpp"
#include "ATE_Threading/Workers/blockqueuefiller.hpp"
#include "ATE_Threading/Workers/BlockProcessor.hpp"

using ATE_Util::Options;
using ATE_Util::Coefficients;
using ATE_Util::CoefficientType;
using ATE_Threading::ThreadManager;
using ATE_Threading::blockQueueFiller;
using ATE_Threading::BlockProcessor;

void print_usage();

int main(int argc, char* argv[]){
    Options opt(argc, argv);
    Coefficients bass(opt.bassIntensity, CoefficientType::bass);
    Coefficients treble(opt.trebleIntensity, CoefficientType::treble);
    BlockQueue queue;
    ThreadManager thread_manager(opt.threads);

    // Verify the passed options and complain if they're wrong
    if (!opt.verify_options()) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    blockQueueFiller producer(thread_manager, queue, opt.inPath);
    vector<BlockProcessor*> consumers;

    // If after making a producer threads there are no more threads available, producer should finish its task first!
    if (!thread_manager.thread_available()) {
        producer.complete_task();
    }

    while (!queue.is_processed()) {
        if (thread_manager.thread_available()) {
            consumers.push_back(new BlockProcessor(thread_manager, queue, bass, treble));
        }

        ATE_Util::wait();
    }

    queue.writeQueueToFile(opt.outPath);

    // Clean up consumers
    for (BlockProcessor* worker : consumers) {
        delete worker;
    }

    return 0;
}

void print_usage() {
    cout << "usage: mafn_ate in_path out_path -p num_threads -b bass_intensity -t treble_intensity" << endl;
}