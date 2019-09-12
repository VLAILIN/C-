#pragma once
#include <iostream>
#include <cmath>  
using namespace std;

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
	bool operator<(const Point& obj) const; //оператор <
	bool operator==(const Point& obj) const; //оператор ==
	bool operator!=(const Point& obj) const; //оператор !=
	double getDistance() const; //удаленность от начала координат

	int getX() const;
	int getY() const;

friend Point& operator-=(Point& obj1, const Point& obj2); //оператор -=
friend Point& operator-=(Point& obj1, int n); //оператор -=
friend Point operator+(int n, const Point& obj); //оператор +
friend Point operator-(const Point& obj1, const Point& obj2); //оператор -
friend Point operator-(const Point& obj1, int n); //оператор -
friend ostream& operator<<(ostream& os, const Point& d);
friend ostream& operator<<(ostream& os, const Point* p);

};


