#include "../include/Map2D.h"

Map2D::Map2D()
{
    srand(time(NULL));
    this->m_RandomizeMap();
}

string Map2D::WhatIsHere(int x, int y)
{
    return m_map[x][y].What_is_here();
}
void Map2D::m_RandomizeMap()
{
    enum Fill{Empty, Grass, Water, Branch, Food, Scent, BlackAnt, RedAnt, BlackAnthill, RedAnthill} object;

    for(int x=0; x<800; x++)
    {
        for(int y=0; y<600; y++)
        {
            bool is_it_empty=rand()%2;

            if(is_it_empty==true)
            {
                object = Empty;
                m_map[x][y].fill_point(x, y, object, rand()%100);
            }
            else
            {
                int what_object = rand()%6;
                int scent_level = rand()%100;

                if(what_object==0)
                {
                    object = Grass;
                    scent_level = 0;
                }
                if(what_object==1)
                {
                    object = Water;
                    scent_level = 0;
                }
                if(what_object==2)
                {
                    object = Branch;
                    scent_level = 0;
                }
                if(what_object==3)
                {
                    object = Scent;
                    scent_level = 100;
                }
                if(what_object==4)  object = BlackAnt;
                if(what_object==5)  object = RedAnt;

                m_map[x][y].fill_point(x, y, object, scent_level);
            }
        }
    }

    this->m_place_anthills();
}
void Map2D::m_place_anthills()
{
    enum Fill{Empty, Grass, Water, Branch, Food, Scent, BlackAnt, RedAnt, BlackAnthill, RedAnthill} object;

    int black_x, black_y;
    int red_x, red_y;

    object = BlackAnthill;
    black_x = rand()%800;
    black_y = rand()%600;
    m_map[black_x][black_y].fill_point(black_x, black_y, object, 0);

    object = RedAnthill;
    while((red_x==black_x)&&(red_y==black_y))
    {
        red_x = rand()%800;
        red_y = rand()%600;
    }
    m_map[red_x][red_y].fill_point(red_x, red_y, object, 0);
}

Map2D::~Map2D()
{

}
