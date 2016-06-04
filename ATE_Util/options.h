#ifndef OPTIONS_H
#define OPTIONS_H

#include <getopt.h>
#include <stdlib.h>
#include <string>
#include <iostream>


namespace ATE_Util {

  using std::cout;
  using std::endl;

  class Options{
  public:
      // OPTIONS
      std::string inPath, outPath;
      int threads, bassIntensity, trebleIntensity;

      Options(int argc, char* argv[]);
      void processArguments(int argc, char* argv[]);
      void printOptions();
  };

}

#endif // OPTIONS_H
