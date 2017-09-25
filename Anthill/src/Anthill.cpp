#include "Anthill.h"

Anthill::Anthill(int x, int y, Fill anthill_color) : Point2D(x, y), m_ant_spawn_timer(1)
{
    m_fill=anthill_color;
}

int Anthill::getTimer()
{
    return m_ant_spawn_timer;
}
void Anthill::lowerTimer()
{
    m_ant_spawn_timer--;

    if(m_ant_spawn_timer<0) m_ant_spawn_timer=10;
}

vector<Ant*> Anthill::spawn_ants(vector<Point2D*> empty_around)
{
    vector<Ant*> ant_vector;
    bool does_ant_spawn, is_a_worker;
    int x, y;

    for(int i=0; i<empty_around.size(); i++)
    {
        does_ant_spawn=rand()%2;
        if(does_ant_spawn==true)
        {
            x = empty_around[i]->getX();
            y = empty_around[i]->getY();
            if(Point2D::m_fill==black_anthill)
            {
                is_a_worker=rand()%2;

                if(is_a_worker==true)
                {
                    empty_around[i] = new BlackAntWorker(x, y, static_cast<Point2D*>(this));
                    ant_vector.push_back(static_cast<Ant*>(empty_around[i]));
                }
//                else                    empty_around[i] = new BlackAntSoldier(x, y);
            }
            else if(Point2D::m_fill==red_anthill)
            {
//                empty_around[i] = new RedAnt(x, y);
            }

//            ant_vector.push_back(static_cast<Ant*>(empty_around[i]));
        }
    }

    return ant_vector;
}

Anthill::~Anthill()
{
    //dtor
}
