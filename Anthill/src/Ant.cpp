#include "../include/Ant.h"

Ant::Ant()
{
    //ctor
}
Ant::Ant(int x, int y) : Point2D(x, y)
{
   Point2D::m_fill=red_ant;
}

void Ant::setWhatsAround(vector<Point2D*> *whats_around)
{
    m_whats_around=*whats_around;
}

void Ant::m_takeDamage(int damage)
{
    m_health_points-=damage;
}

Ant::~Ant()
{
    //dtor
}
