#include "Map2D.h"

Map2D::Map2D(int x, int y)
{
    string **map= new string* [y];
    for(int i=0; )

    srand(time(NULL));

    string possible_outcomes[9] = {"empty", "obstacle", "food", "scent",
    "Rant", "Bantworker", "Bantsoldier", "Ranthill", "Banthill"};

    for(int row=0; row<y; row++)
    {
        for(int column=0; column<x; column++)
        {
            int outcome=rand()%100;
            if(outcome<50);
        }
    }
}

Map2D::~Map2D()
{
    //dtor
}
