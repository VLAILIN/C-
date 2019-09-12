#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <string>
#include "myString.h"
#include <cstdarg>


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

MyString& MyString::operator= (const MyString& obj)
{
	if (this!=&obj)
	{
		SetNewString(obj.m_pStr);
	}
	return *this;
}

MyString& MyString::operator= (MyString&& obj)
{
	if (this != &obj)
	{
		delete[] m_pStr;
		m_pStr = obj.m_pStr;
		obj.m_pStr = nullptr;
	}
	return *this;
}

MyString& MyString::operator = (const char* k)
{
	SetNewString(k);
	
	return *this;

}

MyString MyString::operator+ (const MyString& obj) const
{
	MyString tmp;
	 	
	if ((m_pStr!=nullptr)&&(obj.m_pStr != nullptr))
	{
		char* NewString = new char[strlen(obj.m_pStr) + strlen(m_pStr)+ 1];
		strcpy(NewString, m_pStr); //копируем строку
		strcat(NewString, obj.m_pStr); //конкатенация строк
		tmp.SetNewString(NewString);
		delete[] NewString;
	}
	else if ((m_pStr != nullptr) && (obj.m_pStr == nullptr))
	{
		tmp.SetNewString(m_pStr);
	}
	
	else if ((m_pStr == nullptr) && (obj.m_pStr != nullptr))
	{
		tmp.SetNewString(obj.m_pStr);
	}

	return tmp;
}

MyString& MyString::operator += (const MyString& obj)
{

	return *this = *this + obj;

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
/*
	delete[] m_pStr; //освободили память
	if (p != nullptr)
	{
		m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
		strcpy(m_pStr, p); //копируем строку
	}
	else m_pStr = nullptr;
*/
	
	if ((m_pStr != nullptr) && (p != nullptr))
		{
			if (strlen(m_pStr)<strlen(p))
			{
			delete[] m_pStr;
			m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
			}
			strcpy(m_pStr, p); //копируем строку
		}

		else if ((m_pStr != nullptr) && (p == nullptr))
		{
			delete[] m_pStr;
			m_pStr = nullptr;
		}

		else if ((m_pStr == nullptr) && (p != nullptr))
		{
			m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
			strcpy(m_pStr, p); //копируем строку
		}

}


bool MyString::operator==(const char *k) const
{
	if (strcmp(m_pStr, k) == 0) return true;
	else return false;
}

// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
	
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

ostream& operator<< (ostream& os, const MyString& obj)
{
	os << "contents:  \"" << obj.m_pStr<< "\"";
		return os;
}



/*
MyString& MyString::operator= (const MyString& obj)
{
	if (this!=&obj)
	{
		if (obj.m_pStr==nullptr) 
		{
			if (m_pStr!=nullptr)
			{
				delete[] m_pStr;
				m_pStr = nullptr;
			}
		}
		else
		{
			//if (strlen(m_pStr)<strlen(obj.m_pStr))
			//{
			delete[] m_pStr;
			m_pStr = new char[strlen(obj.m_pStr) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
			//}
			strcpy(m_pStr, obj.m_pStr); //копируем строку
		}

		if ((m_pStr != nullptr) && (obj.m_pStr != nullptr))
		{
			if (strlen(m_pStr)<strlen(obj.m_pStr))
			{
			delete[] m_pStr;
			m_pStr = new char[strlen(obj.m_pStr) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
			}
			strcpy(m_pStr, obj.m_pStr); //копируем строку
		}
		
		else if ((m_pStr != nullptr) && (obj.m_pStr == nullptr))
		{
			delete[] m_pStr;
			m_pStr = nullptr;
		}

		else if ((m_pStr == nullptr) && (obj.m_pStr != nullptr))
		{
			m_pStr = new char[strlen(obj.m_pStr) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
			strcpy(m_pStr, obj.m_pStr); //копируем строку
		}

	}
	return *this;
}
*/


