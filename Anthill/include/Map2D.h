#ifndef MAP2D_H
#define MAP2D_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>

#include "Point2D.h"
#include "Obstacle.h"
#include "Food.h"
#include "Empty.h"
#include "Anthill.h"
#include "Ant.h"
#include "Fill.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::setw;

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

        void m_display();
        void m_displayFood();
        void m_displayScent();

        void m_randomizeMap();
        void m_place_anthills();
        void m_place_obstacles();
        void m_place_food();

        void m_spawn_ants(Anthill* anthill_ptr);
        void m_place_new_ants(vector<Ant*> new_ant);
        void m_ants_work();
        void m_pick_up_ant(Ant* ant);
        void m_place_ant(Ant* ant);

        vector<Point2D*> m_get_empty_around(Anthill* ant);
        void m_tell_ant_whats_around(Ant* ant, int radious);

        void m_clean_up();
};

#endif // MAP2D_H
