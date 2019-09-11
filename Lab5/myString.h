#pragma once
#include "Counter.h"

class MyString
{
    Counter* m_pC;	//строка-член класса
public:

	MyString(const char* s = " "); //конструктор с параметром

	MyString(const MyString &obj); // конструктор копирования
	MyString(MyString&&); //move конструктор копирования

	MyString& operator = (const MyString& obj); //оператор присваивания
	MyString& operator = (MyString&& obj); //move оператор присваивания
	
	const char* GetString() const; // метод получения строки
	bool operator==(const char *k) const; //оператор сравнения

	static void printAll(); //печать всех строк
	static void ChangeRegister(); //изменение регистра
	static void printSort(); //печать

	~MyString();//деструктор класса

	friend ostream& operator<< (ostream& os, const MyString& obj);
};

//	MyString& operator = (const char* k); //оператор присваивания
//void SetNewString(const char*); //метод замены строки на новую