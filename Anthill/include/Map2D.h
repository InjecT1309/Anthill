#ifndef MAP2D_H
#define MAP2D_H

#include <cstdlib>
#include <ctime>

#include "Point2D.h"

class Map2D
{
    public:
        Map2D();
        virtual ~Map2D();
        int WhatIsHere(int x, int y);

    protected:

    private:
        int m_height;
        int m_width;
        Point2D map[800][600];
};

#endif // MAP2D_H
