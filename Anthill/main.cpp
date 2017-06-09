#include <iostream>
#include <string>

#include "include/Map2D.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;



int main()
{
    Map2D Map;

    for(int y=1; y<20; y++)
    {
        for(int x=1; x<20; x++)
        {
            cout << Map.WhatIsHere(x, y).m_Fill << " ";
        }
        cout << endl;
    }

    return 0;
}
