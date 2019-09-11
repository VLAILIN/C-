#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int m_x, m_y; //координаты точки 
public:
	Point(int x=0, int y=0); //конструктор с параметрами
	
	~Point() = default;
	Point(const Point& d) = default;
	Point& operator=(const Point& d) = default;
	Point(Point&& d)= default;
	Point& operator=(Point&& d)= default;

	friend ostream& operator<<(ostream& os, const Point& d);
	friend class Circle;
};
