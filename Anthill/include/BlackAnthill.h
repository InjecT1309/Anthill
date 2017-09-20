#ifndef BLACKANTHILL_H
#define BLACKANTHILL_H

#include "Fill.h"
#include "Point2D.h"

class BlackAnthill : public Point2D
{
    public:
        BlackAnthill(int x, int y);
        virtual ~BlackAnthill();

        int getTimer();
        void lowerTimer();

    protected:

    private:
        int m_ant_spawn_timer;
};

#endif // BLACKANTHILL_H
