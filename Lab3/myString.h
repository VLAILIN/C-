#pragma once
#include <iostream>
using namespace std;
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString(); //конструктор по умолчанию
	MyString(const char*); //конструктор с параметром
	MyString(const MyString &obj); // конструктор копировани€
	MyString(MyString&&); //move конструктор копировани€
	MyString& operator = (const MyString& obj); //оператор присваивани€
	MyString& operator = (const char* k); //оператор присваивани€
	MyString& operator = (MyString&& obj); //move оператор присваивани€
	MyString operator + (const MyString& obj) const; //оператор сложени€
	MyString& operator += (const MyString& obj); //оператор +=
	const char* GetString() const; // метод получени€ строки
	void SetNewString(const char*); //метод замены строки на новую
	bool operator==(const char *k) const; //оператор сравнени€
	~MyString();//деструктор класса

	friend ostream& operator<< (ostream& os, const MyString& obj);

};

MyString —oncat_str(const char *, ...);