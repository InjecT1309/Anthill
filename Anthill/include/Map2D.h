#ifndef MAP2D_H
#define MAP2D_H

#include <cstdlib>
#include <ctime>
#include <string>
#include "Point2D.h"

using std::string;
using std::srand;

class Map2D
{
    public:
        Map2D(int x, int y);
        virtual ~Map2D();
        void WhatIsHere(int x, int y);


    protected:

    private:
        int m_height;
        int m_width;
        Point2D map[800][600];
        

};

#endif // MAP2D_H
