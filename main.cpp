#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>

#include "options.h"
#include "coefficients.h"
#include "block.h"

using namespace std;

int main(int argc, char* argv[]){

    Options opt(argc, argv);
    Coefficients bass(opt.bassIntensity, CoefficientType::bass);
    Coefficients treble(opt.trebleIntensity, CoefficientType::treble);

    ifstream audiofile(opt.inPath, ios::in|ios::binary|ios::ate);

    short appel[1024];

    streampos size;
    if (audiofile.is_open()){
        size = audiofile.tellg();
        //memblock = new char [size];
        //file.seekg (0, ios::beg);
        //file.read (memblock, size);
        audiofile.close();

        cout << size << endl;
    } else {
        cout << "Couldn't open file " << opt.inPath << endl;
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

