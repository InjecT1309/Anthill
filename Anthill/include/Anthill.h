#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>
#include <cstdlib>

#include "Point2D.h"
#include "Ant.h"
#include "BlackAntWorker.h"
#include "BlackAntSoldier.h"
#include "RedAnt.h"
#include "Fill.h"

using std::vector;

class Anthill : public Point2D
{
    public:
        Anthill(int x, int y, Fill anthill_color);
        virtual ~Anthill();

        int getTimer();
        void lowerTimer();

        vector<Ant*> spawn_ants(vector<Point2D*> empty_around);

    protected:

    private:
        int m_ant_spawn_timer;
};

#endif // ANTHILL_H
