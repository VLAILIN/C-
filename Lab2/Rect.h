#pragma once
#include "Shape.h"
class Rect:public Shape
{
private:
	int m_left, m_top, m_right, m_bottom; //координаты двух точек пр€моугольника
public:
	Rect(int x1=0, int y1=0, int x2=0, int y2=0, COLORS C=WHITE); //конструктор с параметрами
	//Rect(const Rect &obj); // конструктор копировани€
	virtual void WhereAmI() const; //вывод сообщени€
	void GetAll(int&, int&, int&, int&) const; //функци€ выт€гивани€ значений private-переменных класса
	void Inflate(int);
	virtual ~Rect(); //деструктор класса
};



/*
private:
	 m_left, m_right, m_top, m_bottom; //координаты пр€моугольника
public:
	Rect(); //конструктор по умолчанию
	Rect(int, int, int, int); //конструктор с параметрами
	Rect(const Rect &obj); // конструктор копировани€
	void InflateRect(int, int, int, int); //функци€ расширени€ пр€моугольника
	void InflateRect(int=1, int=1); //функци€ расширени€ пр€моугольника с двум€ параметрами по умолчанию
	void SetAll(int, int, int, int); //установка значений координат пр€моугольника
	void GetAll(int&, int&, int&, int&) const; //функци€ выт€гивани€ значений private-переменных класса
	void BoundingRect(const Rect&, const Rect&);
	~Rect(); //деструктор класса
protected:
	void Normalize(); //нормализаци€ пр€моугольника
*/