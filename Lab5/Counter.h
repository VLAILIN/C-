#pragma once
#include <iostream>
using namespace std;

class Counter
{
private:
	size_t m_count; //������� �������������
	char* m_pStr; //��������� �� ����������� ����������� ������ 
	Counter* pNext; //��������� �� ��������� Counter 

	//����������� ������
	static unsigned int m_curCounters; //������� ����������
	static Counter* pHead; //��������� �� ������ ������ ������ Counter

	Counter(const char* s); //�����������
	~Counter(); //����������

	Counter(const Counter& d) = delete;
	Counter& operator=(const Counter& d) = delete;
	Counter(Counter&& d)= delete;
	Counter& operator=(Counter&& d)= delete;

	void AddUser(); //�������� ������������
	void RemoveUser();	//������ ������������

	friend ostream& operator<<(ostream& os, const Counter& d);
	friend class MyString;
};


