#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <cstdarg>
using namespace std;

// Определение конструктора по умолчанию.
MyString::MyString()
{
	m_pStr = nullptr; 
}
// Определение конструктора.
MyString::MyString(const char* p)
{
	m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
	strcpy(m_pStr, p); //копируем строку
}

//конструктор копирования
MyString::MyString(const MyString &obj)
{
	if (obj.m_pStr!=nullptr)
	{
		m_pStr = new char[strlen(obj.m_pStr) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
		strcpy(m_pStr, obj.m_pStr); //копируем строку
	}
	else m_pStr = nullptr;
}

//move конструктор копирования
MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}

// метод получения строки
const char* MyString::GetString() const
{
	if (this == nullptr) return "No string here";
	if (m_pStr==nullptr) return "No string here";
	return m_pStr;
}

//метод замены строки на новую
void MyString::SetNewString(const char* p)
{
	delete[] m_pStr; //освободили память

	m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
	strcpy(m_pStr, p); //копируем строку
}

// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
	//m_pStr = nullptr;
}

MyString Сoncat_str(const char* first, ...)
{
	unsigned int count = 0; //длинна общей строки

	const char* ch = first;
	va_list p; //унивресальный указатель
	va_start(p, first); //направили универсальный указатель на первый необязательный параметр

	//цикл для нахождения длины строки
	while (ch != nullptr)
	{
		count += strlen(ch);
		ch = va_arg(p, const char*);
	}

	char* tmp = new char[count+1]; //выделяем память под новую строку
	tmp[0] = '\0';

	ch = first;
	va_start(p, first); //направили универсальный указатель на первый необязательный параметр

	//цикл для конкатенации
	while (ch != nullptr)
	{
		strcat(tmp, ch); //конкатенация строк
		ch = va_arg(p, const char*);
	}

	va_end(p); //обнуление универсального указателя

	MyString str1(tmp); //создаем объект класса
	
	delete[] tmp; //освободили память
	tmp = nullptr;

	return std::move(str1);
}