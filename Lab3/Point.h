#pragma once

class Point
{
private:
	int m_x, m_y; //координаты точки 
public:
	Point(int x=0, int y=0); //конструктор с параметрами
	Point& operator+=(const Point& obj); //оператор +=
	Point& operator+=(int); //оператор +=
	Point operator+(const Point& obj) const; //оператор +
	Point operator+(int) const; //оператор +
	const Point& operator+() const; //оператор унарный +
	Point operator-() const; //оператор унарный -

friend Point& operator-=(Point& obj1, const Point& obj2); //оператор -=
friend Point& operator-=(Point& obj1, int n); //оператор -=
friend Point operator+(int n, const Point& obj); //оператор +
friend Point operator-(const Point& obj1, const Point& obj2); //оператор -
friend Point operator-(const Point& obj1, int n); //оператор -

};


