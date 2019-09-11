#include "Rect.h"

Rect::Rect(int x1, int y1, int x2, int y2, COLORS C):Shape(C)  //конструктор, параметры x1, y1, C предназначены конструктору базового класса Shape
{	//вызов конструктора родительского класса Shape
	m_left = x1;
	m_top = y1;
	m_right = x2;
	m_bottom = y2;
}
/*
Rect::Rect(const Rect &obj):Shape(obj) //конструктор копирования, указываем компилятору каким конструктором базового класса следует инициализировать базовую часть
{//вызов конструктора копирования родительского класса Shape
	m_right = obj.m_right;
	
	m_bottom = obj.m_bottom;
}
*/
void Rect::WhereAmI() const
{
	std::cout << "Now I am in class Rect" << std::endl;
}

void Rect::Inflate(int r) //функция увеличения прямоугольника
{
	m_left -= r;
	m_right += r;
	m_top += r;
	m_bottom -= r;
}

void Rect::GetAll(int &x, int &y, int &z, int &t) const //функция вытягивания значений private-переменных класса
{
	x = m_left;
	y = m_right;
	z = m_top;
	t = m_bottom;
}

Rect::~Rect() //деструктор
{
	std::cout << "Now I am in Rect's destructor!" << std::endl;
}//вызов деструктора родительского класса Shape
