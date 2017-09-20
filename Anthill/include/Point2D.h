#ifndef POINT2D_H
#define POINT2D_H

#include <cstdlib>
#include <string>
#include <cmath>

#include "Fill.h"

using std::string;

class Point2D
{
    public:
        Point2D();
        Point2D(int x, int y);
        virtual ~Point2D();

        Fill whatIsHere();
        int getDistance(Point2D* point);
        int getX();
        int getY();
        void set_fill(Fill fill);

    protected:
        int m_x, m_y;
        Fill m_fill;

    private:
};

#endif // POINT2D_H
