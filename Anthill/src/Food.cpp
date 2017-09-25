#include "Food.h"

Food::Food(int x, int y) : Point2D(x, y)
{
    m_fill=food;
    m_food_level=100;
}

void Food::lowerFood()
{
    m_food_level-=5;
}
int Food::getFoodLevel()
{
    return m_food_level;
}

Food::~Food()
{
    //dtor
}
