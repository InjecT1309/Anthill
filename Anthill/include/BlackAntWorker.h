#ifndef BLACKANTWORKER_H
#define BLACKANTWORKER_H

#include "Ant.h"
#include "Food.h"
#include "Fill.h"

class BlackAntWorker : public Ant
{
    public:
        BlackAntWorker(int x, int y, Point2D* anthill_pos);
        virtual ~BlackAntWorker();

        virtual void work() override;
        bool getIsCarryingFood();

    protected:

    private:
        int m_energy;
        bool m_is_resting;
        bool m_is_carrying_food;
        Point2D* m_anthill_pos;

        void m_rest();
        Food* m_whichFoodToPick();
        void m_pickUpFood(Food* food);
        void m_deliverFood();
        Point2D* m_findStrongestScent();
};

#endif // BLACKANTWORKER_H
