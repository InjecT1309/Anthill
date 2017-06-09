#ifndef POINT2D_H
#define POINT2D_H

#include <cstdlib>

class Point2D
{
    public:
        Point2D();
        virtual ~Point2D();

        Point2D What_is_here();
        enum Fill{Empty, Grass, Water, Branch, Food, Scent, BlackAnt, RedAnt, BlackAnthill, RedAnthill} m_Fill; //temporary

    protected:

    private:
        int m_x;
        int m_y;

        int m_scent_level;
};

#endif // POINT2D_H
