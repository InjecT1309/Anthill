#ifndef MAP2D_H
#define MAP2D_H

#include <cstdlib>
#include <ctime>
#include <string>

#include "Point2D.h"

using std::string;

class Map2D
{
    public:
        Map2D();
        virtual ~Map2D();
        string WhatIsHere(int x, int y);

    protected:

    private:
        int m_height;
        int m_width;
        Point2D m_map[800][600];

        void m_RandomizeMap(); // Randomize Map for testing
        void m_place_anthills();
};

#endif // MAP2D_H
