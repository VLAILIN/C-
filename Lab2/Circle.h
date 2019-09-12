#pragma once
#include "Shape.h"
#include "Rect.h"
class Circle : public Shape 
{
private:
	double x, y;
	double radius; //радиус окружности
public:
	Circle(double x1=0, double y1=0, double r=0, COLORS C=WHITE); //конструктор с параметрами
//	Circle(const Circle &obj); // конструктор копирования
	Circle(const Rect &obj); // конструктор копирования
	virtual void WhereAmI() const; //вывод сообщения
	void Inflate(int);
	virtual ~Circle(); //деструктор класса
};
