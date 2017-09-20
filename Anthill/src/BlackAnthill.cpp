#include "BlackAnthill.h"

BlackAnthill::BlackAnthill(int x, int y) : Point2D(x, y), m_ant_spawn_timer(50)
{
    m_fill=black_anthill;
}

int BlackAnthill::getTimer()
{
    return m_ant_spawn_timer;
}
void BlackAnthill::lowerTimer()
{
    m_ant_spawn_timer--;

    if(m_ant_spawn_timer<0) m_ant_spawn_timer=50;
}

BlackAnthill::~BlackAnthill()
{
    //dtor
}
