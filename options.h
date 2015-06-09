#ifndef OPTIONS_H
#define OPTIONS_H

#include <getopt.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class Options{
public:
    std::string inPath, outPath;
    int threads, bassIntensity, trebleIntensity;
    Options(int argc, char* argv[]);
    void processArguments(int argc, char* argv[]);
};

#endif // OPTIONS_H
