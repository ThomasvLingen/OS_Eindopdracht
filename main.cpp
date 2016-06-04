#include "OS_namespaces.h"

#include "ATE_Util/options.h"
#include "ATE_Util/coefficients.h"
#include "ATE_BlockQueue/blockqueue.h"
#include "ATE_Threading/Workers/blockqueuefiller.h"

using ATE_Util::Options;
using ATE_Util::Coefficients;
using ATE_Util::CoefficientType;
using ATE_Threading::ThreadManager;
using ATE_Threading::blockQueueFiller;

int main(int argc, char* argv[]){

    Options opt(argc, argv);
    Coefficients bass(opt.bassIntensity, CoefficientType::bass);
    Coefficients treble(opt.trebleIntensity, CoefficientType::treble);
    BlockQueue queue;
    ThreadManager thread_manager(opt.threads);

    blockQueueFiller banaan(thread_manager, queue, opt.inPath);
    banaan.complete_task();
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

