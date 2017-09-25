#ifndef ANT_H
#define ANT_H

#include <vector>
#include <stdlib.h>

#include "Fill.h"
#include "Point2D.h"
#include "Empty.h"

using std::vector;

class Ant : public Point2D
{
    public:
        Ant();
        Ant(int x, int y);
        virtual ~Ant();

        void setVisible(vector<Point2D*> whats_around);
        void setNewPosition(Point2D* new_pos);
        virtual void work();
        bool checkIfDead();

        int getVision();

    protected:
        vector<Point2D*> m_visible;
        vector<Point2D*> m_adjacent;

        int m_health_points;
        int m_agression;
        int m_vision_radious;
        bool m_is_dead;

        void m_setAdjacent();
        bool m_checkIfFillIsVisible(Fill fill);
        bool m_checkIfFillIsAdjacent(Fill fill);
        Point2D* m_findClosestFill(Fill fill);
        Point2D* m_pickNewPosition();
        Point2D* m_pickNewPosition(Point2D* destination);

        Ant* m_whichAntToAttack(Fill ant_type);
        void m_attack(Ant* enemy);
        void m_takeDamage(int how_much_dmg);

    private:

};

#endif // ANT_H
