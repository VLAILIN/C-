#include "Rect.h"

Rect::Rect(int x1, int y1, int x2, int y2, COLORS C):Shape(C)  //конструктор, параметры x1, y1, C предназначены конструктору базового класса Shape
{	//вызов конструктора родительского класса Shape
	m_left = x1;
	m_top = y1;
	m_right = x2;
	m_bottom = y2;
	Normalize();
}

void Rect::WhereAmI() const
{
	std::cout << "Now I am in class Rect" << std::endl;
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

double Rect::GetSquare() const
{
	if (this == nullptr) return 0;
	return (m_right - m_left)*(m_top - m_bottom);
}

COLORS Rect::getColor() const
{
	if (this == nullptr) return WHITE;
	return color;
}

void Rect::PrintData(ostream& os) const
{
	os << *this;
}

double Rect::getDistance() const
{
	//вычислим координаты центра прямоугольника
	double x = (static_cast<double>(m_right) - m_left);
	double y = (static_cast<double>(m_top) - m_bottom);
	return sqrt(pow(x, 2) + pow(y, 2));
}

Shape* Rect::GetCopy() const
{
	Shape* p = new Rect(*this);
	return p;
}

bool Rect::operator == (const Shape* pS) const
{
	if (typeid(*this) != typeid(*pS)) return false;

	if (Shape::operator==(pS) == false) return false; //сравнение базовых  частей

	//if ((static_cast<const Shape*>(this) == pS) == false) return false; 

	return ((this->m_left == static_cast<const Rect*>(pS)->m_left) && (this->m_right == static_cast<const Rect*>(pS)->m_right) && (this->m_top == static_cast<const Rect*>(pS)->m_top)&&(this->m_bottom == static_cast<const Rect*>(pS)->m_bottom));
}

ostream& operator<< (ostream& os, const Rect& d)
{
	os << "r" << " ";
	d.Shape::PrintData(os); //вывод данных базовой части
	os<< d.m_left << " " << d.m_right << " " << d.m_top << " " << d.m_bottom << "\n";
	return os;
}

Rect& Rect::operator=(const Shape* pS)
{
	//if (typeid(*this) != typeid(*pS)) return *this;
	if (this != pS)
	{
		if (pS)
		{
			*this = static_cast<const Rect&>(*pS);
		}
	}
	return *this;
}


