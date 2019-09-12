#include "Circle.h"

Circle::Circle(const Point& p, float r):centr(p) //конструктор с параметрами
{	
	radius = r;
}

Circle::Circle(int x, int y, float r):centr(x,y) //конструктор с параметрами
{
	radius = r;
}
bool Circle::operator==(const Circle& d) const
{
	return radius==d.radius; 
}

float Circle::GetRadius() const
{
	return radius;
}

bool Circle::CmpNodeSquare(const Circle& c2) const
{
	double sq1 = 3.14*radius*radius;
	double sq2 = 3.14*c2.radius*c2.radius;

	if (sq1 < sq2) return true;
	else return false;
}


ostream& operator<< (ostream& os, const Circle& d)
{
	//os <<d.centr<< "  radius: "<<d.radius<<"\n";
	os << d.centr << " " << d.radius << "\n";
	return os;
}
