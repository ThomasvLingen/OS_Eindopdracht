#ifndef OPTIONS_H
#define OPTIONS_H

#include "OS_namespaces.h"


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
      bool verify_options();
  };

}

#endif // OPTIONS_H
