#include "Map2D.h"

Map2D::Map2D()
{
    srand(time(NULL));

    //  filling the points

    for(int y=0; y<800; y++)
    {
        for(int x=0; x<600; x++)
        {
            map[y][x] = Point2D(x, y);                  //  set x and y of a point

            map[y][x].fill_point();
        }
    }

    //  setting anthills

    int black_anthill_x, black_anthill_y;
    int red_anthill_x, red_anthill_y;

    black_anthill_x = rand()%600;                                 //
    black_anthill_y = rand()%800;                                 //  set position of the black ant hill
    map[black_anthill_y][black_anthill_x].set_black_anthill();    //

    while((red_anthill_x==black_anthill_x)&&(red_anthill_y==black_anthill_y))   //
    {                                                                           //
        red_anthill_x = rand()%600;                                             //  set red anthill on a diffrent position
        red_anthill_y = rand()%800;                                             //  than black anthill
    }                                                                           //
    map[red_anthill_y][red_anthill_x].set_red_anthill();                        //
}

int Map2D::WhatIsHere(int x, int y)
{
    return map[y][x].what_is_here();
}

Map2D::~Map2D()
{

}
