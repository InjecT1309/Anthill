#include <iostream>
#include <string>

#include "include/Map2D.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    Map2D *Map = new Map2D(25, 25);

    Map->mainLoopDebug();

    return 0;
}
