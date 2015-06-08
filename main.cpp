#include <iostream>
#include <getopt.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main(int argc, char* argv[]){

    int threads;
    int bass;
    int treble;
    char c;
    string in;
    string out;

    while((c = getopt(argc, argv, "p:b:t:")) != -1){
        switch(c){
            case 'p':
                threads = atoi(optarg);
            break;
            case 'b':
                bass = atoi(optarg);
            break;
            case 't':
                treble = atoi(optarg);
            break;
            case '?':
                cout << "lolwut" << endl;
            break;
            default:
                abort();
            break;
        }
    }

    in = argv[optind];
    out = argv[optind+1];

    cout << "Recieved options:" << endl;
    cout << "Number of threads: " << threads << endl;
    cout << "Bass intensity: " << bass << endl;
    cout << "Treble intensity: " << treble << endl;
    cout << "In filepath: " << in << endl;
    cout << "Out filepath: " << out << endl;
}

