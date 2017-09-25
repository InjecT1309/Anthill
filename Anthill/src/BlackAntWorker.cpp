#include "../include/BlackAntWorker.h"

BlackAntWorker::BlackAntWorker(int x, int y, Point2D* anthill_pos) : Ant(x, y)
{
    m_fill = black_ant_worker;
    m_energy = 100;
    m_is_resting = false;
    m_is_carrying_food = false;
    m_anthill_pos = anthill_pos;
}

void BlackAntWorker::work()
{
    bool is_following_scent;

    if(m_is_resting==true)
    {
        m_rest();
    }
    else if(m_energy<=0)
    {
        m_is_resting = true;
    }
    else if(m_checkIfFillIsAdjacent(red_ant)==true)
    {
        m_attack(m_whichAntToAttack(red_ant));
    }
    else if((m_is_carrying_food==true)&&(getDistance(m_anthill_pos)==1))
    {
        m_deliverFood();
    }
    else if(m_is_carrying_food==true)
    {
        m_pickNewPosition(m_anthill_pos);
    }
    else if(m_checkIfFillIsAdjacent(food)==true)
    {
        m_pickUpFood(m_whichFoodToPick());
    }
    else if(m_checkIfFillIsVisible(food)==true)
    {
        m_pickNewPosition(m_findClosestFill(food));
    }
    else
    {
        is_following_scent = rand()%2;
        if(is_following_scent==true)
        {
            m_pickNewPosition(m_findStrongestScent());
        }
        else
        {
            m_pickNewPosition();
        }
    }
}
bool BlackAntWorker::getIsCarryingFood()
{
    return m_is_carrying_food;
}

void BlackAntWorker::m_rest()
{
    m_energy+=5;
    if(m_energy>=100)   m_is_resting=false;
}
Food* BlackAntWorker::m_whichFoodToPick()
{
    Food* output = nullptr;

    for(int i=0; i<m_adjacent.size(); i++)
    {
        if(m_adjacent[i]->whatIsHere()==food)
        {
            output = static_cast<Food*>(m_adjacent[i]);
            break;
        }
    }

    return output;
}
void BlackAntWorker::m_pickUpFood(Food* food)
{
    food->lowerFood();
    m_is_carrying_food = true;
}
void BlackAntWorker::m_deliverFood()
{
    m_is_carrying_food = false;
}
Point2D* BlackAntWorker::m_findStrongestScent()
{
    Empty* strongest = static_cast<Empty*>(m_visible[0]);
    Empty* checked;

    for(int i=0; i<m_visible.size(); i++)
    {
        if(m_visible[i]->whatIsHere()==empty)
        {
            checked = static_cast<Empty*>(m_visible[i]);

            if((checked->getScentLevel())<(strongest->getScentLevel()))
            {
                strongest = checked;
            }
        }
    }

    return strongest;
}

BlackAntWorker::~BlackAntWorker()
{
    //dtor
}
