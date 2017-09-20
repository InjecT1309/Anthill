#include "../include/Map2D.h"

Map2D::Map2D(int width, int height) : m_width(width), m_height(height),
                                    m_how_much_obstacle(width*height/10), m_how_much_food(width*height/15)
{
    srand(time(NULL));

    m_map = new Point2D** [m_width];

    for(int x=0; x<m_width; x++)
    {
        m_map[x] = new Point2D* [m_height];
        for(int y=0; y<m_height; y++)
        {
            m_map[x][y] = new Point2D(x, y);
        }
    }

    m_randomizeMap();
}

void Map2D::mainLoopDebug()
{
    while(true)
    {
        for(int x=0; x<m_width; x++)
        {
            for(int y=0; y<m_height; y++)
            {
                cout << whatIsHereMapDebug(x, y) << " ";
            }
            cout << "|" << endl;
        }

        m_spawn_ants();

        getwchar();

        system("cls");
    }
}

Fill Map2D::whatIsHere(int x, int y)
{
    return m_map[x][y]->whatIsHere();
}
string Map2D::whatIsHereDebug(int x, int y)
{
    if(whatIsHere(x, y)==not_set_yet)       return "not_set_yet";
    if(whatIsHere(x, y)==empty)             return "empty";
    if(whatIsHere(x, y)==obstacle)          return "obstacle";
    if(whatIsHere(x, y)==food)              return "food";
    if(whatIsHere(x, y)==black_anthill)     return "black_anthill";
    if(whatIsHere(x, y)==red_anthill)       return "red_anthill";
    if(whatIsHere(x, y)==black_ant_worker)  return "black_ant_worker";
    if(whatIsHere(x, y)==black_ant_solider) return "black_ant_solider";
    if(whatIsHere(x, y)==red_ant)           return "red_ant";
}
string Map2D::whatIsHereMapDebug(int x, int y)
{
    if(whatIsHere(x, y)==not_set_yet)       return "Error";
    if(whatIsHere(x, y)==empty)             return " ";
    if(whatIsHere(x, y)==obstacle)          return "O";
    if(whatIsHere(x, y)==food)              return "F";
    if(whatIsHere(x, y)==black_anthill)     return "B";
    if(whatIsHere(x, y)==red_anthill)       return "R";
    if(whatIsHere(x, y)==black_ant_worker)  return "W";
    if(whatIsHere(x, y)==black_ant_solider) return "S";
    if(whatIsHere(x, y)==red_ant)           return "A";
}

void Map2D::m_randomizeMap()
{
    m_place_anthills();
    m_place_obstacles();
    m_place_food();

    for(int x=0; x<m_width; x++)
    {
        for(int y=0; y<m_height; y++)
        {
            if(m_map[x][y]->whatIsHere()==not_set_yet)
            {
                m_map[x][y] = new Empty(x, y);
            }
        }
    }
}
void Map2D::m_place_anthills()
{
    int x, y;

    do
    {
        x = rand()%m_width, y = rand()%m_height;
    }   while(whatIsHere(x, y)!=not_set_yet);

    m_map[x][y] = new Anthill(x, y, black_anthill);
    m_black_anthill_ptr = static_cast<Anthill*>(m_map[x][y]);

    do
    {
        x = rand()%m_width, y = rand()%m_height;
    }   while(whatIsHere(x, y)!=not_set_yet);

    m_map[x][y] = new Anthill(x, y, red_anthill);
    m_red_anthill_ptr = static_cast<Anthill*>(m_map[x][y]);
}
void Map2D::m_place_obstacles()
{
    int x, y;

    for(int i=0; i<m_how_much_obstacle; i++)
    {
        do
        {
            x = rand()%m_width, y = rand()%m_height;
        }   while(whatIsHere(x, y)!=not_set_yet);

        m_map[x][y] = new Obstacle(x, y);
    }
}
void Map2D::m_place_food()
{
    int x, y;

    for(int i=0; i<m_how_much_food; i++)
    {
        do
        {
            x = rand()%m_width, y = rand()%m_height;
        }   while(whatIsHere(x, y)!=not_set_yet);

        m_map[x][y] = new Food(x, y);
    }
}

void Map2D::m_spawn_ants()
{
    vector<Point2D*> empty_around_black_anthill = m_get_empty_around(m_black_anthill_ptr);
    vector<Point2D*> empty_around_red_anthill = m_get_empty_around(m_red_anthill_ptr);

    vector<Ant*> black_ants = m_black_anthill_ptr->spawn_ants(empty_around_black_anthill);
    vector<Ant*> red_ants = m_red_anthill_ptr->spawn_ants(empty_around_red_anthill);

    m_place_new_ants(black_ants);
    m_place_new_ants(red_ants);
}

void Map2D::m_place_new_ants(vector<Ant*> new_ant)
{
    int x, y;

    for(int i=0; i<new_ant.size(); i++)
    {
        x = new_ant[i]->getX();
        y = new_ant[i]->getY();
        m_map[x][y] = new_ant[i];
        m_ant.push_back(new_ant[i]);
    }
}

vector<Point2D*> Map2D::m_get_empty_around(Anthill* anthill_ptr)
{
    vector<Point2D*> empty_around;

    for(int x=0; x<m_width; x++)
    {
        for(int y=0; y<m_height; y++)
        {
            if((anthill_ptr->getDistance(m_map[x][y])==1)&&(m_map[x][y]->whatIsHere()==empty))
            {
                empty_around.push_back(m_map[x][y]);
            }
        }
    }

    return empty_around;
}

void Map2D::m_tell_ant_whats_around(Ant* ant, int radious)
{
    int size_of_vector=0;

    for(int x=0; x<m_width; x++)
    {
        for(int y=0; y<m_height; y++)
        {
            if(ant->getDistance(m_map[x][y])<=radious)
            {
                size_of_vector++;
            }
        }
    }

    vector<Point2D*> whats_around(size_of_vector);
    int vector_iter=0;

    for(int x=0; x<m_width; x++)
    {
        for(int y=0; y<m_height; y++)
        {
            if(ant->getDistance(m_map[x][y])<=radious)
            {
                whats_around[vector_iter]=m_map[x][y];
                vector_iter++;
            }
        }
    }

    ant->setWhatsAround(&whats_around);
}

Map2D::~Map2D()
{

}
