#include "Point.h"


Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

Point Point::operator+(const Point& obj) const //оператор +
{
	return Point(m_x+obj.m_x, m_y+obj.m_y);
}

Point Point::operator+(int n) const //оператор +
{
	return Point(m_x + n, m_y + n);
}

Point& Point::operator+=(const Point& obj) //оператор +=
{
	m_x += obj.m_x;
	m_y += obj.m_x;

	return *this;
}

Point& Point::operator+=(int n) //оператор +
{
	m_x += n;
	m_y += n;

	return *this;
}

const Point& Point::operator+() const  //оператор унарный +
{
	return *this;
}

Point Point::operator-() const //оператор унарный -
{
	return Point(-m_x, -m_y);
}
bool Point::operator==(const Point& obj) const //оператор ==
{
	return (m_x==obj.m_x)&&(m_y==obj.m_y);
}
bool Point::operator!=(const Point& obj) const //оператор !=
{
	return !((m_x==obj.m_x)&&(m_y==obj.m_y));
}
bool Point::operator<(const Point& obj) const //оператор <
{
	return getDistance()<obj.getDistance();
}

bool Point::operator>(const Point& obj) const //оператор <
{
	return getDistance() > obj.getDistance();
}

double Point::getDistance() const //удаленность от начала координат
{
	return sqrt(pow(m_x,2)+pow(m_y,2));
}

int Point::getX() const
{
	return m_x;
}

int Point::getY() const
{
	return m_y;
}


Point operator+(int n, const Point& obj) //оператор +
{
	return Point(obj.m_x + n, obj.m_y + n);
}

Point operator-(const Point& obj1, const Point& obj2) //оператор -
{
	return Point(obj1.m_x - obj2.m_x, obj1.m_y - obj2.m_y);
}

Point operator-(const Point& obj1, int n) //оператор -
{
	return Point(obj1.m_x - n, obj1.m_y - n);
}

Point& operator-=(Point& obj1, const Point& obj2) //оператор -=
{
	return obj1 = obj1 -obj2;
}

Point& operator-=(Point& obj1, int n) //оператор -
{
	return obj1 = obj1 - n;
}




ostream& operator<< (ostream& os, const Point& d)
{
	os << "x = " << d.m_x << " y = " << d.m_y;
	return os;
}

ostream& operator<< (ostream& os, const Point* p)
{
	if (p) os << "x = " << p->m_x << " y = " << p->m_y;
	else os << "object is empty";
	return os;
}
