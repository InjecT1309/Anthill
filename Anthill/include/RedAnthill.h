#ifndef REDANTHILL_H
#define REDANTHILL_H

#include "Point2D.h"
#include "Fill.h"

class RedAnthill : public Point2D
{
    public:
        RedAnthill(int x, int y);
        virtual ~RedAnthill();

        int getTimer();
        void lowerTimer();

    protected:

    private:
        int m_ant_spawn_timer;
};

#endif // REDANTHILL_H
