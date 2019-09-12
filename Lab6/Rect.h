#pragma once
#include "Shape.h"
class Rect:public Shape
{
private:
	int m_left, m_top, m_right, m_bottom; //координаты четырех точек прямоугольника
public:
	Rect(int x1=0, int y1=0, int x2=0, int y2=0, COLORS C=WHITE); //конструктор с параметрами
	
	Rect(const Rect& d) = default;
	Rect& operator=(const Rect& d) = default;
	Rect(Rect&& d) = default;
	Rect& operator=(Rect&& d) = default;
	~Rect() = default;
																  															 														 
	virtual void WhereAmI() const; //вывод сообщения
	virtual double GetSquare() const;
	void GetAll(int&, int&, int&, int&) const; //функция вытягивания значений private-переменных класса
	virtual void Inflate(int);
	virtual Shape* GetCopy() const;
	virtual bool operator == (const Shape*) const;
	virtual Rect& operator=(const Shape* d);
	virtual COLORS getColor() const;
	virtual double getDistance() const;
	virtual void PrintData(ostream& os) const;

	friend ostream& operator<<(ostream& os, const Rect& d);
	
protected:
	void Normalize(); //нормализация прямоугольника
};



//virtual ~Rect(); //деструктор класса
