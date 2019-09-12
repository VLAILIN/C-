#pragma once
#include "Shape.h"
//#include "Rect.h"
class Circle : public Shape 
{
private:
	int x, y;
	double radius; //радиус окружности
public:
	Circle(int x1=0, int y1=0, double r=0, COLORS C=WHITE); //конструктор с параметрами

	Circle(const Circle& d) = default;
	Circle& operator=(const Circle& d) = default;
	Circle(Circle&& d) = default;
	Circle& operator=(Circle&& d) = default;
	~Circle() = default;

	virtual double GetSquare() const;
	virtual void WhereAmI() const; //вывод сообщения
	virtual void Inflate(int);
	virtual Shape* GetCopy() const;
	virtual bool operator == (const Shape*) const;
	virtual Circle& operator=(const Shape* d);
	virtual COLORS getColor() const;
	virtual double getDistance() const;
	virtual void PrintData(ostream& os) const;

	friend ostream& operator<<(ostream& os, const Circle& d);
};


//virtual ~Circle(); //деструктор класса
