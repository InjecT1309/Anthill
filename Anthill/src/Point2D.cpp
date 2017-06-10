#include "../include/Point2D.h"

Point2D::Point2D()
{

}

void Point2D::fill_point(int x, int y, int object, int scent_level)
{
    m_x = x;
    m_y = y;

    if(object==0)   m_Fill=Empty;
    if(object==1)   m_Fill=Grass;
    if(object==2)   m_Fill=Water;
    if(object==3)   m_Fill=Branch;
    if(object==4)   m_Fill=Food;
    if(object==5)   m_Fill=Scent;
    if(object==6)   m_Fill=BlackAnt;
    if(object==7)   m_Fill=RedAnt;
    if(object==8)   m_Fill=BlackAnthill;
    if(object==9)   m_Fill=RedAnthill;

    m_scent_level = scent_level;
}

string Point2D::What_is_here()
{
    //  funkcja to_string() u mnie nie dziala

	string tmp_point = "x: ";
	tmp_point.append(std::to_string(m_x));
    tmp_point = + " y: ";
    tmp_point.append(std::to_string(m_y));
    tmp_point = + " fill: ";
    tmp_point.append(std::to_string(m_Fill));
    tmp_point = + " scent: ";
    tmp_point.append(std::to_string(m_scent_level));

    return tmp_point;
}

Point2D::~Point2D()
{
    //dtor
}
