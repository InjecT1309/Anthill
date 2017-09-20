#include "../include/Point2D.h"

Point2D::Point2D()
{

}

Point2D::Point2D(int x, int y) : m_x(x), m_y(y), m_fill(not_set_yet)
{

}

Fill Point2D::whatIsHere()
{
    return m_fill;
}
int Point2D::getDistance(Point2D* point)
{
    return sqrt(pow(this->getX()-point->getX(),2)+pow(this->getY()-point->getY(), 2));
}
int Point2D::getX()
{
    return m_x;
}
int Point2D::getY()
{
    return m_y;
}
void Point2D::set_fill(Fill fill)
{
    m_fill=fill;
}

Point2D::~Point2D()
{
    //dtor
}
