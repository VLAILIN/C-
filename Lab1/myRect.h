#pragma once
#include <iostream>
class Rect
{
private:
	int m_left, m_right, m_top, m_bottom; //координаты прямоугольника
public:
	Rect(); //конструктор по умолчанию
	Rect(int, int, int, int); //конструктор с параметрами
	Rect(const Rect &obj); // конструктор копирования
	void InflateRect(int, int, int, int); //функция расширения прямоугольника
	void InflateRect(int=1, int=1); //функция расширения прямоугольника с двумя параметрами по умолчанию
	void SetAll(int, int, int, int); //установка значений координат прямоугольника
	void GetAll(int&, int&, int&, int&) const; //функция вытягивания значений private-переменных класса
	void BoundingRect(const Rect&, const Rect&);
	~Rect(); //деструктор класса
protected:
	void Normalize(); //нормализация прямоугольника
};

Rect BoundingRect(Rect, Rect);

Rect BoundingRect2(const Rect&, const Rect&);
