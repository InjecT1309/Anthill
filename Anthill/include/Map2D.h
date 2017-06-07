#ifndef MAP2D_H
#define MAP2D_H


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

};

#endif // MAP2D_H
