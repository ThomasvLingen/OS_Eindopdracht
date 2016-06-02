//We put all these inclusions up here to make sure that OS_namespaces.h has visibility of the contents
//So that we can have the using statements right there
#include <iostream>
#include <thread>

#include "OS_namespaces.h"

#include "options.h"
#include "coefficients.h"
#include "block.h"
#include "blockqueue.h"
#include "blockqueuefiller.h"
#include "ThreadManager.hpp"

int main(int argc, char* argv[]){

    Options opt(argc, argv);
    Coefficients bass(opt.bassIntensity, CoefficientType::bass);
    Coefficients treble(opt.trebleIntensity, CoefficientType::treble);
    BlockQueue queue;
    ThreadManager thread_manager(opt.threads);

    blockQueueFiller banaan(thread_manager, queue, opt.inPath);
    banaan._objThread->join();
    queue.writeQueueToFile(opt.outPath);

    if (DEBUG) {
        opt.printOptions();

        cout << "a1 bass: " << bass.a1 << endl;
        cout << "a2 bass: " << bass.a2 << endl;

        cout << "a1 treble: " << treble.a1 << endl;
        cout << "a2 treble: " << treble.a2 << endl;
    }

    return 0;
}

