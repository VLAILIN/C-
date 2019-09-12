#pragma once
#include "Shape.h"
class Rect:public Shape
{
private:
	int m_left, m_top, m_right, m_bottom; //координаты двух точек прямоугольника
public:
	Rect(int x1=0, int y1=0, int x2=0, int y2=0, COLORS C=WHITE); //конструктор с параметрами
	//Rect(const Rect &obj); // конструктор копирования
	virtual void WhereAmI() const; //вывод сообщения
	void GetAll(int&, int&, int&, int&) const; //функция вытягивания значений private-переменных класса
	void Inflate(int);
	virtual ~Rect(); //деструктор класса
};
