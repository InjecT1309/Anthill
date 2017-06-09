#include "../include/Point2D.h"

Point2D::Point2D()
{

}


string Point2D::What_is_here()
{
	string tmp_point = "x: ";
	tmp_point.append(std::to_string(m_x));
    tmp_point = + " y: ";
    tmp_point.append(std::to_string(m_y));
    tmp_point = + " fill: ";
    tmp_point.append(std::to_string(m_Fill));

    return tmp_point;
}

Point2D::~Point2D()
{
    //dtor
}
