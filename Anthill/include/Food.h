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

        void set_food_to_max();
        void lower_food();
        int get_food_level();

    protected:

    private:
        int m_food_level;
};

#endif // FOOD_H
