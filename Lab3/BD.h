#pragma once
#include "Pair.h"

class BD
{
	Pair* pBase; //указатель на базу
	size_t m_cap;//емкость
	size_t m_size;//размер

public:
	BD(); //конструктор
	~BD(); //деструктор
	BD(const BD& bd); //конструткор копирования
	BD& operator=(const BD& bd); //оптимизированный!!!
	BD(BD&& bd); //move конструткор копирования
	BD& operator=(BD&& bd); //move оператор присваивания
	MyData& operator[](const char* key); //оператор []
	void deletePair(const char* key); //удалени езаписи
	
	friend ostream& operator<<(ostream& os, const BD &bd);
};
