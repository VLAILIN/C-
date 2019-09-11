#pragma once
#include <iostream>
enum COLORS {BLUE, GREEN, WHITE, BLACK, RED, YELLOW, ORANGE};
class Shape
{
protected:	//эти данные должны быть доступны методам производных классов
	COLORS color;	//цвет фигуры
public:
	Shape(COLORS C=WHITE);//конструктор
	//Shape(const Shape &obj); // конструктор копирования
	virtual ~Shape();//деструктор
	virtual void WhereAmI() const; //вывод сообщения
	virtual void Inflate(int) = 0; //функция расширения
	//void Inflate(int); //функция расширения
};