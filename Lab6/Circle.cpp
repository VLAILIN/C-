#include "Circle.h"
 

Circle::Circle(int x1, int y1, double r, COLORS C):Shape(C) //конструктор, параметры x1, y1, C предназначены конструктору базового класса Shape
{	//вызов конструктора родительского класса Shape
	x = x1;
	y = y1;
	radius = r;
}

void Circle::WhereAmI() const
{
	std::cout << "Now I am in class Circle" << std::endl;
}

double Circle::GetSquare() const
{
	if (this == nullptr) return 0;
	return 3.14*radius*radius;
}

COLORS Circle::getColor() const
{
	if (this == nullptr) return WHITE;
	return color;
}

double Circle::getDistance() const
{
	if (this == nullptr) return 0;
	return sqrt(pow(x,2)+pow(y,2));

}

void Circle::PrintData(ostream& os) const
{
	os << *this;
}

void Circle::Inflate(int n)
{
	radius += n;
}

Shape* Circle::GetCopy() const
{
	Shape* p = new Circle(*this);
	return p;
}

bool Circle::operator == (const Shape* pS) const
{
	if (typeid(*this) != typeid(*pS)) return false;

	if (Shape::operator==(pS) == false) return false; //сравнение базовых  частей

	//if ((static_cast<const Shape*>(this) == pS)==false) return false;

	return ((this->x == static_cast<const Circle*>(pS)->x) && (this->y == static_cast<const Circle*>(pS)->y) && (this->radius == static_cast<const Circle*>(pS)->radius));
}

ostream& operator<< (ostream& os, const Circle& d)
{
	os << "c" << " "; //вывод признака
	d.Shape::PrintData(os); //вывод данных базовой части
	os << d.x << " " << d.y << " " << d.radius << "\n";
	return os;
}

Circle& Circle::operator=(const Shape* pS)
{
	//if (typeid(*this) != typeid(*pS)) return *this;
	if (this != pS)
	{
		if (pS)
		{
			*this = static_cast<const Circle&>(*pS);
		}
	}
	return *this;
}



