#ifndef POINT2D_H
#define POINT2D_H


class Point2D
{
    public:
        Point2D(int x, int y);
        virtual ~Point2D();


    protected:

    private:
        int m_x;
        int m_y;
        enum m_Fill{Empty, Grass, Water, Branch, Food, Scent, BlackAnthill, RedAnthill, RedAnt, BlackAnt};
		int m_scent_level;
};

#endif // POINT2D_H
