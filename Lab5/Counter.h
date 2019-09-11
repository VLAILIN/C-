#pragma once
#include <iostream>
using namespace std;

class Counter
{
private:
	size_t m_count; //счетчик пользователей
	char* m_pStr; //указатель на динамически создаваемую строку 
	Counter* pNext; //указатель на следующий Counter 

	//статические данные
	static unsigned int m_curCounters; //счетчик указателей
	static Counter* pHead; //указатель на первый объект класса Counter

	Counter(const char* s); //конструктор
	~Counter(); //деструктор

	Counter(const Counter& d) = delete;
	Counter& operator=(const Counter& d) = delete;
	Counter(Counter&& d)= delete;
	Counter& operator=(Counter&& d)= delete;

	void AddUser(); //добавить пользователя
	void RemoveUser();	//убрать пользователя

	friend ostream& operator<<(ostream& os, const Counter& d);
	friend class MyString;
};


