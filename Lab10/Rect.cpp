#include "Rect.h"

Rect::Rect(int x1, int y1, int x2, int y2) //конструктор, параметры x1, y1, C предназначены конструктору базового класса Shape
{	//вызов конструктора родительского класса Shape
	m_left = x1;
	m_top = y1;
	m_right = x2;
	m_bottom = y2;
	Normalize();
}

void Rect::Normalize() //нормализация прямоугольника
{
	if (m_left > m_right)
	{
		int tmp = m_left;
		m_left = m_right;
		m_right = tmp;
	}

	if (m_bottom > m_top)
	{
		int tmp = m_bottom;
		m_bottom = m_top;
		m_top = tmp;
	}
}

void Rect::GetAll(int &x, int &y, int &z, int &t) const //функция вытягивания значений private-переменных класса
{
	x = m_left;
	y = m_right;
	z = m_top;
	t = m_bottom;
}

double Rect::GetSquare() const
{
	if (this == nullptr) return 0;
	return (m_right - m_left)*(m_top - m_bottom);
}

double Rect::getDistance() const
{
	//вычислим координаты центра прямоугольника
	double x = (static_cast<double>(m_right) - m_left);
	double y = (static_cast<double>(m_top) - m_bottom);
	return sqrt(pow(x, 2) + pow(y, 2));
}


ostream& operator<< (ostream& os, const Rect& d)
{
	os<<"left: "<< d.m_left << " right: " << d.m_right << " top: " << d.m_top << " bottom: " << d.m_bottom  << " distance: " << d.getDistance() << "\n";
	return os;
}


