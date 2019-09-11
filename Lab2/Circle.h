#pragma once
#include "Shape.h"
#include "Rect.h"
class Circle : public Shape 
{
private:
	double x, y;
	double radius; //������ ����������
public:
	Circle(double x1=0, double y1=0, double r=0, COLORS C=WHITE); //����������� � �����������
//	Circle(const Circle &obj); // ����������� �����������
	Circle(const Rect &obj); // ����������� �����������
	virtual void WhereAmI() const; //����� ���������
	void Inflate(int);
	virtual ~Circle(); //���������� ������
};