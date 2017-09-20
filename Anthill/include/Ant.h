#ifndef ANT_H
#define ANT_H

#include <vector>
#include <iostream>

#include "Fill.h"
#include "Point2D.h"

using std::vector;

class Ant : public Point2D
{
    public:
        Ant();
        Ant(int x, int y);
        virtual ~Ant();

        void setWhatsAround(vector<Point2D*> *whats_around);

    protected:
        vector<Point2D*> m_whats_around;

        int m_health_points;
        int m_agression;
        int m_vision_range;
        bool m_is_dead;

        void m_takeDamage(int damage);

    private:


};

#endif // ANT_H
