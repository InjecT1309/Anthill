#include "Food.h"

Food::Food(int x, int y) : Point2D(x, y)
{
    m_fill=food;
}

void Food::set_food_to_max()
{
    m_food_level=100;
}
void Food::lower_food()
{
    m_food_level-=2;
}
int Food::get_food_level()
{
    return m_food_level;
}


Food::~Food()
{
    //dtor
}
