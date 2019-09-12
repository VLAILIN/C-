#pragma once
#include <iostream>
#include <typeinfo>
#include <cmath>  
using namespace std;
enum COLORS {BLUE, GREEN, WHITE, BLACK, RED, YELLOW, ORANGE};
class Shape
{
protected:	//эти данные должны быть доступны методам производных классов
	COLORS color;	//цвет фигуры
public:
	Shape(COLORS C=WHITE);//конструктор
	
	Shape(const Shape& d) = default;
	Shape& operator=(const Shape& d) = default;
	Shape(Shape&& d) = default;
	Shape& operator=(Shape&& d) = default;
	~Shape() = default;

	virtual Shape& operator=(const Shape* d) = 0;
	
	virtual void WhereAmI() const; //вывод сообщения
	virtual void Inflate(int) = 0; //функция расширения
	virtual double GetSquare() const =0;
	virtual Shape* GetCopy() const =0;
	virtual bool operator == (const Shape*) const = 0;
	virtual COLORS getColor() const=0;
	virtual double getDistance() const = 0;
	virtual void PrintData(ostream& os) const = 0;

	friend ostream& operator<<(ostream& os, const Shape& d);
	
};
