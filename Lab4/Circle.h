#pragma once
#include "Point.h"

class Circle
{
private:
	Point centr; //координаты центра
	float radius; //радиус окружности
public:
	
	Circle():centr(0, 0) {radius=0;} //конструктор
	Circle(int x, int y, float r); //конструктор с параметрами	
	Circle(const Point& p, float r); //конструктор с параметрами
	bool operator==(const Circle& d) const; //оператор сравнения
	float GetRadius() const;

	bool CmpNodeSquare(const Circle& c2) const; //сравнение элементов по площадям

	~Circle() = default;
	Circle(const Circle& d) = default;
	Circle& operator=(const Circle& d)= default;
	Circle(Circle&& d)= default;
	Circle& operator=(Circle&& d)= default;
	
	friend class Node;

	friend ostream& operator<<(ostream& os, const Circle& d);
	
};