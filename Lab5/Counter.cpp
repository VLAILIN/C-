#define _CRT_SECURE_NO_WARNINGS

#include "Counter.h"

Counter::Counter(const char* s):m_count(1)
{
	
	m_pStr = new char[strlen(s) + 1]; 
	strcpy(m_pStr, s); //�������� ������

	/*if (pHead == nullptr)
	{
		pHead = this;
		pNext = nullptr;
	}
	else
	{
		pNext = pHead->pNext;
		pHead->pNext = this;
	}*/

	pNext = pHead;
	pHead = this;
	
	m_curCounters++; //����������� ������� ��������
}

Counter::~Counter()
{
	delete[] m_pStr;
	
	if (pHead == this) //���� ������ ������
	{
		/*if (pNext == nullptr) pHead = nullptr;
		else
		{*/
			pHead = pNext;
		//}
	}
	else
	{
		Counter* pCur = pHead;
		while (pCur->pNext != this) //���� ������� ���������� ������
		{
			pCur = pCur->pNext;
		}
		pCur->pNext = pNext; //��������� ��� �� ��������� ���������
	}

	pNext = nullptr;
	m_curCounters--; //��������� ������� ��������
}

void Counter::AddUser()
{
	m_count++;
}

void Counter::RemoveUser()
{
	m_count--;
	if (m_count==0) delete this;
}

ostream& operator<< (ostream& os, const Counter& d)
{
	os << d.m_pStr<<" users: "<<d.m_count;
	return os;
}