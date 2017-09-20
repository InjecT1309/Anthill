#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <iostream>

#include "Fill.h"
#include "Point2D.h"

using std::vector;

class Entity
{
    public:
        Entity();
        Entity(Point2D* point_ptr);
        virtual ~Entity();

        int getDistance(Point2D* point_ptr);
        void setWhatsAround(vector<Point2D*> *whats_around);

    protected:
        Point2D* m_point_ptr;
        Fill m_fill;
        vector<Point2D*> m_whats_around;

    private:
};
#endif // ENTITY_H
