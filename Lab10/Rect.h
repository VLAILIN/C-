#pragma once
#include <cmath>  
#include <iostream>
using namespace std;

class Rect
{
private:
	int m_left, m_top, m_right, m_bottom; //координаты четырех точек прямоугольника
public:
	Rect(int x1=0, int y1=0, int x2=0, int y2=0); //конструктор с параметрами
	
	Rect(const Rect& d) = default;
	Rect& operator=(const Rect& d) = default;
	Rect(Rect&& d) = default;
	Rect& operator=(Rect&& d) = default;
	~Rect() = default;
																  															 														 
	
	double GetSquare() const;
	void GetAll(int&, int&, int&, int&) const; //функция вытягивания значений private-переменных класса
	double getDistance() const;
	

	friend ostream& operator<<(ostream& os, const Rect& d);
	
protected:
	void Normalize(); //нормализация прямоугольника
};



