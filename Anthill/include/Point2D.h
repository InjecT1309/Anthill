#ifndef POINT2D_H
#define POINT2D_H

#include <cstdlib>
#include <string>

using std::string;

class Point2D
{
    public:
        Point2D();
        virtual ~Point2D();

        void fill_point(int x, int y, int object, int scent_level);
        string What_is_here();

    protected:

    private:
        int m_x;
        int m_y;
		enum Fill{Empty, Grass, Water, Branch, Food, Scent, BlackAnt, RedAnt, BlackAnthill, RedAnthill} m_Fill;
        int m_scent_level;
};

#endif // POINT2D_H
