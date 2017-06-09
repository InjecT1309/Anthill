#include <iostream>
#include <string>

#include "Map2D.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

string displayObject(int object)
{
    string possibilities[10] = {"   ", "-G-", "-W-", "-B-", "-F-", "   ", "R-A", "B-A", "RAH", "BAH"};

    return possibilities[object];
}

int main()
{
    Map2D Map;

    for(int y=0; y<800; y++)
    {
        for(int x=0; x<600; x++)
        {
            cout << displayObject(Map.WhatIsHere(x, y)) << " ";
        }
        cout << endl;
    }

    return 0;
}
