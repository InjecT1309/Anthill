#include "../include/Ant.h"

Ant::Ant()
{
    //ctor
}
Ant::Ant(int x, int y) : Point2D(x, y), m_health_points(100), m_agression(1), m_vision_radious(4), m_is_dead(false)
{
   Point2D::m_fill=red_ant;
}

void Ant::setVisible(vector<Point2D*> whats_around)
{
    m_visible=whats_around;

    m_setAdjacent();
}
void Ant::setNewPosition(Point2D* new_pos)
{
    m_x = new_pos->getX();
    m_y = new_pos->getY();
}

void Ant::work()
{
    m_pickNewPosition();
}
bool Ant::checkIfDead()
{
    return m_is_dead;
}
int Ant::getVision()
{
    return m_vision_radious;
}

void Ant::m_setAdjacent()
{
    m_adjacent.clear();

    for(int i=0; i<m_visible.size(); i++)
    {
        if(this->getDistance(m_visible[i])==1) m_adjacent.push_back(m_visible[i]);
    }
}
bool Ant::m_checkIfFillIsVisible(Fill fill)
{
    for(int i=0; i<m_visible.size(); i++)
    {
        if(m_visible[i]->whatIsHere()==fill)   return true;
    }

    return false;
}
bool Ant::m_checkIfFillIsAdjacent(Fill fill)
{
    for(int i=0; i<m_adjacent.size(); i++)
    {
        if(m_adjacent[i]->whatIsHere()==fill)   return true;
    }

    return false;
}
Point2D* Ant::m_findClosestFill(Fill fill)
{
    Point2D* closest = m_visible[0];

    for(int i=0; i<m_visible.size(); i++)
    {
        if((m_visible[i]->whatIsHere()==fill)&&
           (getDistance(m_visible[i])<getDistance(closest)))
           {
                closest = m_visible[i];
           }
    }

    return closest;
}
Point2D* Ant::m_pickNewPosition()
{
    int which_direction;

    do
    {
        which_direction = rand()%m_adjacent.size();
    }   while(m_adjacent[which_direction]->whatIsHere()!=empty);

    m_x = m_adjacent[which_direction]->getX();
    m_y = m_adjacent[which_direction]->getY();

    return m_adjacent[which_direction];
}
Point2D* Ant::m_pickNewPosition(Point2D* destination)
{
    Point2D* point_to_move = static_cast<Point2D*>(this);

    for(int i=0; i<m_adjacent.size(); i++)
    {
        if((m_adjacent[i]->whatIsHere()==empty)&&
           (m_adjacent[i]->getDistance(destination)<=point_to_move->getDistance(destination)))
            point_to_move = m_adjacent[i];
    }

    m_x = point_to_move->getX();
    m_y = point_to_move->getY();

    return point_to_move;
}
Ant* Ant::m_whichAntToAttack(Fill ant_type)
{
    Ant* output = nullptr;

    for(int i=0; i<m_adjacent.size(); i++)
    {
        if(m_adjacent[i]->whatIsHere()==ant_type)
        {
            output = static_cast<Ant*>(m_adjacent[i]);
            break;
        }
    }

    return output;
}
void Ant::m_attack(Ant* enemy)
{
    enemy->m_takeDamage(m_agression);
}
void Ant::m_takeDamage(int how_much_dmg)
{
    m_health_points-=how_much_dmg;
    if(m_health_points<=0)  m_is_dead=true;
}


Ant::~Ant()
{
    //dtor
}
