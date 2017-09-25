#ifndef FOOD_H
#define FOOD_H

#include <string>

#include "Fill.h"
#include "Point2D.h"

using std::string;

class Food : public Point2D
{
    public:
        Food(int x, int y);
        virtual ~Food();

        void lowerFood();
        int getFoodLevel();

    protected:

    private:
        int m_food_level;
};

#endif // FOOD_H
