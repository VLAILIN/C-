#include "Circle.h"
#include <math.h>

Circle::Circle(double x1, double y1, double r, COLORS C):Shape(C) //�����������, ��������� x1, y1, C ������������� ������������ �������� ������ Shape
{	//����� ������������ ������������� ������ Shape
	x = x1;
	y = y1;
	radius = r;
}
/*
Circle::Circle(const Circle &obj): Shape(obj) //����������� �����������, ��������� ����������� ����� ������������� �������� ������ ������� ���������������� ������� �����
{//����� ������������ ����������� ������������� ������ Shape
	radius = obj.radius;
}
*/
Circle::Circle(const Rect &obj) : Shape(obj) //����������� �����������, ��������� ����������� ����� ������������� �������� ������ ������� ���������������� ������� �����
{//����� ������������ ����������� ������������� ������ Shape
	int r_left=0, r_top=0, r_right=0, r_bottom=0;
	obj.GetAll(r_left, r_top, r_right, r_bottom);
	x = (static_cast<double>(r_right) - r_left)/2;
	y = (static_cast<double>(r_top) - r_bottom)/2;
	radius = sqrt(static_cast<double>(pow(r_right-r_left,2)) + pow(r_top = r_bottom,2))/2;
}

void Circle::WhereAmI() const
{
	std::cout << "Now I am in class Circle" << std::endl;
}

void Circle::Inflate(int n)
{
	radius += n;
}

Circle::~Circle() //����������
{
	std::cout << "Now I am in Circle's destructor!" << std::endl;
}//����� ����������� ������������� ������ Shape

