#include "Shape.h"

Shape::Shape(COLORS C) //конструктор
{
	color = C;	
}

void Shape::WhereAmI() const
{
	std::cout << "Now I am in class Shape" << std::endl;
}

bool Shape::operator == (const Shape* pS) const
{
	return color == pS->color;
}

void Shape::PrintData(ostream& os) const
{
	os << *this;
}

ostream& operator<< (ostream& os, const Shape& d)
{
	os << d.color << " ";
	return os;
}
