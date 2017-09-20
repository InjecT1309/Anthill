#ifndef MAP2D_H
#define MAP2D_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "Fill.h"

#include "Point2D.h"
#include "Obstacle.h"
#include "Food.h"
#include "Empty.h"
#include "Anthill.h"

#include "Ant.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Map2D
{
    public:

        Map2D(int width, int height);
        virtual ~Map2D();

        void mainLoopDebug();
        Fill whatIsHere(int x, int y);
        string whatIsHereDebug(int x, int y);
        string whatIsHereMapDebug(int x, int y);

    protected:

    private:
        int m_height;
        int m_width;
        const int m_how_much_obstacle;
        const int m_how_much_food;

        Point2D ***m_map;

        vector<Ant*> m_ant;

        Anthill *m_black_anthill_ptr;
        Anthill *m_red_anthill_ptr;

        void m_randomizeMap();
        void m_place_anthills();
        void m_place_obstacles();
        void m_place_food();

        void m_spawn_ants();
        void m_place_new_ants(vector<Ant*> new_ant);

        vector<Point2D*> m_get_empty_around(Anthill* ant);
        void m_tell_ant_whats_around(Ant* ant, int radious=1);
};

#endif // MAP2D_H
