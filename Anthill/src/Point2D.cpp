#include "Point2D.h"

Point2D::Point2D()
{

}

Point2D::Point2D(int x, int y)
{
    m_x=x;
    m_y=y;
}

void Point2D::fill_point()
{
    bool roll_if_empty=rand()%2;               //  a point on the map has 50% chance to be empty

    if(roll_if_empty==true)
    {
        m_object = Empty;
    }
    else
    {
        int what_object = rand()%7;

        if(what_object==0)  m_object = Grass;
        if(what_object==1)  m_object = Water;
        if(what_object==2)  m_object = Branch;
        if(what_object==3)  m_object = Food;
        if(what_object==4)  m_object = Scent;
        if(what_object==5)  m_object = BlackAnt;
        if(what_object==6)  m_object = RedAnt;
    }

    if(m_object==Scent) m_scent_level=100;
    else                m_scent_level=rand()%100;

}

void Point2D::set_black_anthill()
{
    m_object = BlackAnthill;
}

void Point2D::set_red_anthill()
{
    m_object = RedAnthill;
}

int Point2D::what_is_here()
{
    return m_object;
}

Point2D::~Point2D()
{
    //dtor
}
