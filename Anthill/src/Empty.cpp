#include "Empty.h"

Empty::Empty(int x, int y) : Point2D(x, y)
{
    Point2D::m_fill=empty;
    m_scent_level=0;
}
Empty::Empty(int x, int y, int scent_level) : Point2D(x, y)
{
    Point2D::m_fill=empty;
    m_scent_level = scent_level;
}

void Empty::setScentToMax()
{
    m_scent_level=100;
}
void Empty::lowerScent()
{
    m_scent_level-=2;
}
int Empty::getScentLevel()
{
    return m_scent_level;
}

Empty::~Empty()
{
    //dtor
}
