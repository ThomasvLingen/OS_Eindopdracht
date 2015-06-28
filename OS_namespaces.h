#ifndef OS_NAMESPACES_H
#define OS_NAMESPACES_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <thread>

//Reason we choose to do this seperately for each thing we want to use from the STD namespace:
//This way we won't pull the entire namespace with us or force someone who might include one of my headers
//To have std as his/her standard namespace. This works well for the small scope this assignment is in.
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::ios;
using std::streampos;

using std::vector;

using std::string;

using std::thread;

#endif // OS_NAMESPACES_H
