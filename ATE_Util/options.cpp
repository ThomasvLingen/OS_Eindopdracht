#include "options.h"


namespace ATE_Util {

  Options::Options(int argc, char* argv[]){
      this->processArguments(argc, argv);
  }

  void Options::processArguments(int argc, char *argv[]){
      char c;

      while((c = getopt(argc, argv, "p:b:t:")) != -1){
          switch(c){
              case 'p':
                  this->threads = atoi(optarg);
                  break;
              case 'b':
                  this->bassIntensity = atoi(optarg);
                  break;
              case 't':
                  this->trebleIntensity = atoi(optarg);
                  break;
              case '?':
                  std::cout << "There is an unknown option" << std::endl;
                  break;
              default:
                  abort();
          }
      }

      if(argv[optind]){
          this->inPath = argv[optind];
          optind++;
      } else {
          this->inPath = "NO FILE PASSED";
      }

      if(argv[optind]){
          this->outPath = argv[optind];
          optind++;
      } else {
          this->outPath = "NO FILE PASSED";
      }
  }

  void Options::printOptions() {
      cout << "Number of threads: " << this->threads << endl;
      cout << "Bass intensity: " << this->bassIntensity << endl;
      cout << "Treble intensity: " << this->trebleIntensity << endl;
      cout << "In filepath: " << this->inPath << endl;
      cout << "Out filepath: " << this->outPath << endl;
  }

}
