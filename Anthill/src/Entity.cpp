#include "Entity.h"

Entity::Entity()
{

}
Entity::Entity(Point2D* point_ptr) : m_point_ptr(point_ptr)
{
    m_point_ptr->set_fill(not_set_yet);
}

int Entity::getDistance(Point2D* point_ptr)
{
    return m_point_ptr->getDistance(point_ptr);
}
void Entity::setWhatsAround(vector<Point2D*> *whats_around)
{
    m_whats_around=*whats_around;
}

Entity::~Entity()
{
    //dtor
}
