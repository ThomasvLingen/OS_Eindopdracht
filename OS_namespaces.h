#ifndef OS_NAMESPACES_H
#define OS_NAMESPACES_H

/*
 * I saw another student take this approach to inclusions for a project once, so I thought I'd try it just this once to
 * see if it's nice to work with. This is NOT my normal approach.
 *
 * Conclusion: This makes it really difficult to see dependencies for separate modules in the project, would not
 * recommend.
 * */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <getopt.h>
#include <string>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <iterator>

#include "config.hpp"

/*
 * Reason we choose to do this seperately for each thing we want to use from the STD namespace:
 * This way we won't pull the entire namespace with us or force someone who might include one of my headers
 * To have std as his/her standard namespace. This works well for the small scope this assignment is in.
 * */
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::ostream;
using std::ios;
using std::streampos;

using std::vector;

using std::string;

using std::thread;

using std::mutex;

#endif // OS_NAMESPACES_H
