#include "../include/Map2D.h"

Map2D::Map2D()
{
    srand(time(NULL));
}

string Map2D::WhatIsHere(int x, int y)
{
    return m_map[x][y].What_is_here();
}

void Map2D::m_RandomizeMap()
{
    //here you randomize map
}

Map2D::~Map2D()
{

}
