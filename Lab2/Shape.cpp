#include "Shape.h"

Shape::Shape(COLORS C) //�����������
{
	color = C;	
}
/*
Shape::Shape(const Shape &obj) //����������� �����������
{
	x = obj.x;
	y = obj.y;
	color = obj.color;
}*/
void Shape::WhereAmI() const
{
	std::cout << "Now I am in class Shape" << std::endl;
}

Shape::~Shape() //����������
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