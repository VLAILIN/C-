#include "myRect.h"

Rect::Rect() //конструктор по умолчанию
{
	m_left = 0;
	m_right = 0;
	m_top = 0;
	m_bottom = 0;
}

Rect::Rect(int r_left, int r_right, int r_top, int r_bottom) //конструктор с параметрами
{
	Normalize();
	m_left = r_left;
	m_right = r_right;
	m_top = r_top;
	m_bottom = r_bottom;
}

void Rect::InflateRect(int x, int y, int z, int t) //функция увеличения прямоугольника
{
	m_left -= x;
	m_right += y;
	m_top += z;
	m_bottom -= t;
}

Rect::Rect(const Rect &obj) //конструктор копирования
{
	m_left = obj.m_left;
	m_right = obj.m_right;
	m_top = obj.m_top;
	m_bottom = obj.m_bottom;
}

void Rect::InflateRect(int x, int y) //функция увеличения прямоугольника с параметрами по умолчанию
{
	m_right += x;
	m_top += y;

	/*m_left -= x;
	m_right += x;
	m_top += y;
	m_bottom -= y;*/

}

void Rect::SetAll(int x, int y, int z, int t) //установка значений координат прямоугольника
{
	Normalize();
	m_left = x;
	m_right = y;
	m_top = z;
	m_bottom = t;
}

void Rect::GetAll(int &x, int &y, int &z, int &t) const //функция вытягивания значений private-переменных класса
{
	x = m_left;
	y = m_right;
	z = m_top;
	t = m_bottom;
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

void Rect::BoundingRect(const Rect &r1, const Rect &r2)
{
	int r_left = ((r1.m_left <= r2.m_left) ? r1.m_left : r2.m_left) - 1; //вычисляем наименьшую левую координату и -1
	int r_right = ((r1.m_right >= r2.m_right) ? r1.m_right : r2.m_right) + 1; //вычисляем наибольшую правую координату и +1
	int r_top = ((r1.m_top >= r2.m_top) ? r1.m_top : r2.m_top) + 1; //вычисляем наибольшую верхнюю координату и +1
	int r_bottom = ((r1.m_bottom <= r2.m_bottom) ? r1.m_bottom : r2.m_bottom) - 1; //вычисляем наименьшую нижнюю координату и -1

	SetAll(r_left, r_right, r_top, r_bottom); //расширяем прямоугольник, в который вписаны заданные
}

Rect::~Rect() //деструктор 
{
	m_left = -1;
	m_right = -1;
	m_top = -1;
	m_bottom = -1;

	//std::cout << "destructor" << std::endl;
}

Rect BoundingRect(Rect r1, Rect r2)
{
	int r1_left = 0, r1_right = 0, r1_top = 0, r1_bottom = 0; //переменные для хранения значений private-переменных класса
	int r2_left = 0, r2_right = 0, r2_top = 0, r2_bottom = 0; //переменные для хранения значений private-переменных класса

	r1.GetAll(r1_left, r1_right, r1_top, r1_bottom); //вызов метода
	r2.GetAll(r2_left, r2_right, r2_top, r2_bottom); //вызов метода
	
	int r_left = ((r1_left<=r2_left)?r1_left : r2_left) - 1; //вычисляем наименьшую левую координату и -1
	int r_right = ((r1_right>=r2_right)?r1_right : r2_right) + 1; //вычисляем наибольшую правую координату и +1
	int r_top = ((r1_top>=r2_top)?r1_top : r2_top) + 1; //вычисляем наибольшую верхнюю координату и +1
	int r_bottom = ((r1_bottom<=r2_bottom)?r1_bottom : r2_bottom) - 1; //вычисляем наименьшую нижнюю координату и -1

	Rect r(r_left, r_right, r_top, r_bottom); //создаем прямоугольник, в который вписаны заданные
	return r; 
}

Rect BoundingRect2(const Rect &r1, const Rect &r2)
{
	int r1_left = 0, r1_right = 0, r1_top = 0, r1_bottom = 0; //переменные для хранения значений private-переменных класса
	int r2_left = 0, r2_right = 0, r2_top = 0, r2_bottom = 0; //переменные для хранения значений private-переменных класса

	r1.GetAll(r1_left, r1_right, r1_top, r1_bottom); //вызов метода
	r2.GetAll(r2_left, r2_right, r2_top, r2_bottom); //вызов метода

	int r_left = ((r1_left <= r2_left) ? r1_left : r2_left) - 1; //вычисляем наименьшую левую координату и -1
	int r_right = ((r1_right >= r2_right) ? r1_right : r2_right) + 1; //вычисляем наибольшую правую координату и +1
	int r_top = ((r1_top >= r2_top) ? r1_top : r2_top) + 1; //вычисляем наибольшую верхнюю координату и +1
	int r_bottom = ((r1_bottom <= r2_bottom) ? r1_bottom : r2_bottom) - 1; //вычисляем наименьшую нижнюю координату и -1
	
	Rect r(r_left, r_right, r_top, r_bottom); //создаем прямоугольник, в который вписаны заданные
	return r;
}