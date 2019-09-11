#pragma once
#include <iostream>

class Bochka
{
private:
	double c_spirt, c_water; 
public:
	Bochka(); //конструктор по умолчанию
	Bochka(double, double); //конструктор с параметрами
	Bochka(const Bochka &); // конструктор копирования
	void SetAll(double, double); //установка значений 
	double ProcentSpirt() const;
	void Print() const; //печать
	void Pereliv(Bochka &, double); //функция перелива
	//~Bochka(); //деструктор класса
};