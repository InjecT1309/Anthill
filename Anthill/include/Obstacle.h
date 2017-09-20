#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <string>

#include "Point2D.h"
#include "Fill.h"

using std::string;

class Obstacle : public Point2D
{
    public:
        Obstacle();
        Obstacle(int x, int y);
        virtual ~Obstacle();

    protected:

    private:
};

#endif // OBSTACLE_H
