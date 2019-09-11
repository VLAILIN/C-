#include "Point.h"

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

ostream& operator<< (ostream& os, const Point& d)
{
	//os << "x: " << d.m_x << "  y: " << d.m_y;//<<"\n";
	os << " " << d.m_x << " " << d.m_y;
	return os;
}