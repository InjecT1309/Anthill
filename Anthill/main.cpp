#include <iostream>
#include <string>

#include "include/Map2D.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;



int main()
{
    Map2D *Map = new Map2D();

    int input, x, y;

    while(input!=0)
    {
        cout << "1 - what is on the map \n";
        cout << "0 - end \n";
        cin >> input;
        if(input==1)
        {
            cout << "x: ";
            cin >> x;
            cout << "y: ";
            cin >> y;
            cout << Map->WhatIsHere(x, y);
        }
    }

    return 0;
}
