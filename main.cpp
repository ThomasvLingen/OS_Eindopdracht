#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>

#include "OS_namespaces.h"

#include "options.h"
#include "coefficients.h"
#include "block.h"
#include "blockqueue.h"

int main(int argc, char* argv[]){

    Options opt(argc, argv);
    Coefficients bass(opt.bassIntensity, CoefficientType::bass);
    Coefficients treble(opt.trebleIntensity, CoefficientType::treble);

    ifstream audiofile(opt.inPath, ios::in|ios::binary|ios::ate);

    if(audiofile.is_open()){
        BlockQueue queue(audiofile);
    } else {
        cout << "Couldn't open the input file!" << endl;
    }


    cout << "Recieved options:" << endl;
    cout << "Number of threads: " << opt.threads << endl;
    cout << "Bass intensity: " << opt.bassIntensity << endl;
    cout << "Treble intensity: " << opt.trebleIntensity << endl;
    cout << "In filepath: " << opt.inPath << endl;
    cout << "Out filepath: " << opt.outPath << endl;

    cout << "a1 bass: " << bass.a1 << endl;
    cout << "a2 bass: " << bass.a2 << endl;

    cout << "a1 treble: " << treble.a1 << endl;
    cout << "a2 treble: " << treble.a2 << endl;
}

