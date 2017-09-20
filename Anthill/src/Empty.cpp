#include "Empty.h"

Empty::Empty()
{
    //ctor
}
Empty::Empty(int x, int y) : Point2D(x, y)
{
    Point2D::m_fill=empty;
}

void Empty::set_scent_to_max()
{
    m_scent_level=100;
}
void Empty::lower_scent()
{
    m_scent_level-=2;
}
int Empty::get_scent_level()
{
    return m_scent_level;
}

Empty::~Empty()
{
    //dtor
}
