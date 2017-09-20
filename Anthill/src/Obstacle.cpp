#include "Obstacle.h"

Obstacle::Obstacle()
{
    //ctor
}
Obstacle::Obstacle(int x, int y) : Point2D(x, y)
{
    m_fill=obstacle;
}

Obstacle::~Obstacle()
{
    //dtor
}
