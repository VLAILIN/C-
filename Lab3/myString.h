#pragma once
#include <iostream>
using namespace std;
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString(); //конструктор по умолчанию
	MyString(const char*); //конструктор с параметром
	MyString(const MyString &obj); // конструктор копирования
	MyString(MyString&&); //move конструктор копирования
	MyString& operator = (const MyString& obj); //оператор присваивания
	MyString& operator = (const char* k); //оператор присваивания
	MyString& operator = (MyString&& obj); //move оператор присваивания
	MyString operator + (const MyString& obj) const; //оператор сложения
	MyString& operator += (const MyString& obj); //оператор +=
	const char* GetString() const; // метод получения строки
	void SetNewString(const char*); //метод замены строки на новую
	bool operator==(const char *k) const; //оператор сравнения
	~MyString();//деструктор класса

	friend ostream& operator<< (ostream& os, const MyString& obj);

};

MyString Сoncat_str(const char *, ...);
