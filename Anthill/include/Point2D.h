#ifndef POINT2D_H
#define POINT2D_H

#include <cstdlib>

class Point2D
{
    public:
        Point2D();
        Point2D(int x, int y);
        virtual ~Point2D();

        void fill_point();
        void set_black_anthill();
        void set_red_anthill();
        int what_is_here();

    protected:

    private:
        int m_x;
        int m_y;
        enum m_Fill{Empty, Grass, Water, Branch, Food, Scent, BlackAnt, RedAnt, BlackAnthill, RedAnthill};
        m_Fill m_object;
		int m_scent_level;
};

#endif // POINT2D_H
