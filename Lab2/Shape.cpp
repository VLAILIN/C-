#include "Shape.h"

Shape::Shape(COLORS C) //конструктор
{
	color = C;	
}
/*
Shape::Shape(const Shape &obj) //конструктор копирования
{
	x = obj.x;
	y = obj.y;
	color = obj.color;
}*/
void Shape::WhereAmI() const
{
	std::cout << "Now I am in class Shape" << std::endl;
}

Shape::~Shape() //деструктор
{
	std::cout << "Now I am in Shape's destructor!"<< std::endl;	
}
/*
void Shape::Inflate(int n)
{
	x+= n;
	y+=n;
}
*/
