#include "RedAnthill.h"

RedAnthill::RedAnthill(int x, int y) : Point2D(x, y)
{
    m_fill=red_anthill;
}

int RedAnthill::getTimer()
{
    return m_ant_spawn_timer;
}
void RedAnthill::lowerTimer()
{
    m_ant_spawn_timer--;

    if(m_ant_spawn_timer<0) m_ant_spawn_timer=50;
}

RedAnthill::~RedAnthill()
{
    //dtor
}
