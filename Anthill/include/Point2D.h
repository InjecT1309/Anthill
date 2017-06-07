#ifndef POINT2D_H
#define POINT2D_H


class Point2D
{
    public:
        Point2D(int x, int y);
        virtual ~Point2D();

        void set_enum();

    protected:

    private:
        int m_x;
        int m_y;
        enum object;
};

#endif // POINT2D_H
