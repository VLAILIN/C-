#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <cstdarg>

// ����������� ������������.
MyString::MyString(const char* p)
{
	//m_pC = Counter::find(p);
	Counter* pCur = Counter::pHead;
	while (pCur != nullptr) //����� �� ������
	{
		if (strcmp(p, pCur->m_pStr) == 0) //���� ����� ������ � ����� �� �������
		{
			m_pC = pCur;
			m_pC->AddUser();
			break;
		}
		pCur = pCur->pNext;
	}

	if (pCur == nullptr) m_pC = new Counter(p);
}

//����������� �����������
MyString::MyString(const MyString &obj)
{
	m_pC = obj.m_pC;
	m_pC->AddUser();
}

//move ����������� �����������
MyString::MyString(MyString&& other)
{
	m_pC = other.m_pC;
	other.m_pC = nullptr;
}

MyString& MyString::operator= (const MyString& obj)
{
	if (m_pC!=obj.m_pC)
	{	
		if (m_pC != nullptr) m_pC->RemoveUser();
		m_pC = obj.m_pC;
		if (m_pC != nullptr) m_pC->AddUser();
	}
	return *this;
}

MyString& MyString::operator= (MyString&& obj)
{
	if (m_pC != obj.m_pC)
	{
		if (m_pC != nullptr) m_pC->RemoveUser();
		m_pC = obj.m_pC;

		obj.m_pC = nullptr;
	}
	return *this;
}

// ����� ��������� ������
const char* MyString::GetString() const
{
	if (this == nullptr) return "No string here";
	if (m_pC == nullptr) return "No string here";
	if (m_pC->m_pStr==nullptr) return "No string here";
	return m_pC->m_pStr;
}

bool MyString::operator==(const char *k) const
{
	return (strcmp(m_pC->m_pStr, k) == 0) ;
}

// ����������� �����������.
MyString::~MyString()
{
	if(m_pC!=nullptr) m_pC->RemoveUser();
}

ostream& operator<< (ostream& os, const MyString& obj)
{
	os << *obj.m_pC;
	return os;
}

void MyString::printAll()
{
	if (Counter::m_curCounters)
	{
		Counter* pCur = Counter::pHead;
		while (pCur != nullptr) //����� �� ������
		{
			//cout << pCur->m_pStr<< endl;
			cout << *pCur<< endl;
			pCur = pCur->pNext;
		}
		cout << endl;
	}
	else cout<<"List is empty!"<<endl;
}

void MyString::ChangeRegister()
{
	if (Counter::m_curCounters)
	{
		Counter* pCur = Counter::pHead;
		while (pCur != nullptr) //����� �� ������
		{
			char* tmp = pCur->m_pStr;
			if (tmp)
			{
				while (*tmp != '\0') //���� �� �������� ��������� ������ 
				{
					if ((*tmp >= 'A') && (*tmp <= 'Z'))  // ���� ch � ������� �� A �� Z
					{
						*tmp += 0x20;
					}
					else if((*tmp >= 'a') && (*tmp <= 'z'))
					{
						*tmp -= 0x20;
					}

					tmp++; //���������� ��������� �� ��������� ������ ������
				}
			}
			pCur = pCur->pNext;
		}
	}
	else cout << "List is empty!" << endl;
}

void MyString::printSort()
{
	if (Counter::m_curCounters)
	{
		Counter* pCur = Counter::pHead;
		Counter* pFind = nullptr; //��������� ��� ������ ������������ ��������
		Counter* pMin = nullptr; //��������� �� ������������ ����
		Counter* pCurPrev = nullptr;

		while (pCur->pNext != nullptr)  // ��� ��� ��������� ������������� �������� �� ����� �����
		{
			//����� ������������ �� ���������� ��������
			pMin = pCur; //����� ����� ������� ������ � ����������� ���������
			pFind = pCur->pNext;

			while (pFind != nullptr) //���� ����������� ��������
			{
				if (strcmp(pFind->m_pStr, pMin->m_pStr)<0) //���� ������
				{
					pMin = pFind;
				}
				pFind = pFind->pNext;
			}

			if (pCur != pMin) //���� ����� ������� ��������
			{
				//������ ����� ����� ���������� ������
				//������� ���������� �������
				Counter* ptmp = Counter::pHead;
				while (ptmp->pNext != pMin) //���� ������� ���������� ������
				{
					ptmp = ptmp->pNext;
				}
				
				//��������� ������� pMin
				ptmp->pNext = pMin->pNext;
			
				//������ pMin � ����� �����
				pMin->pNext = pCur;
				if (pCur== Counter::pHead) Counter::pHead = pMin;

				if (pCurPrev!=nullptr) pCurPrev->pNext = pMin;
				
				pCur = pMin; //��������� �� �������� �������
			}

			pCurPrev = pCur;
			pCur = pCur->pNext; //���� ������
		}
		printAll();
	}
	else cout << "List is empty!" << endl;
}




/*
MyString& MyString::operator = (const char* k)
{
	if (strcmp(k, m_pC->m_pStr) != 0)
	{
		m_pC->RemoveUser();

		Counter* pCur = Counter::pHead;
		while (pCur != nullptr) //����� �� ������
		{
			if (strcmp(k, pCur->m_pStr) == 0) //���� ����� ������ � ����� �� �������
			{
				m_pC = pCur;
				m_pC->AddUser();
				break;
			}
			pCur = pCur->pNext;
		}

		if (pCur == nullptr) m_pC = new Counter(k);
	}
	return *this;
}

*/



//����� ������ ������ �� �����
//void MyString::SetNewString(const char* p)
//{
///*
//	delete[] m_pStr; //���������� ������
//	if (p != nullptr)
//	{
//		m_pStr = new char[strlen(p) + 1]; //+ 1  ��� ��� strlen �� ������� ��������������� ����
//		strcpy(m_pStr, p); //�������� ������
//	}
//	else m_pStr = nullptr;
//*/
//	
//	if ((m_pStr != nullptr) && (p != nullptr))
//		{
//			if (strlen(m_pStr)<strlen(p))
//			{
//			delete[] m_pStr;
//			m_pStr = new char[strlen(p) + 1]; //+ 1  ��� ��� strlen �� ������� ��������������� ����
//			}
//			strcpy(m_pStr, p); //�������� ������
//		}
//
//		else if ((m_pStr != nullptr) && (p == nullptr))
//		{
//			delete[] m_pStr;
//			m_pStr = nullptr;
//		}
//
//		else if ((m_pStr == nullptr) && (p != nullptr))
//		{
//			m_pStr = new char[strlen(p) + 1]; //+ 1  ��� ��� strlen �� ������� ��������������� ����
//			strcpy(m_pStr, p); //�������� ������
//		}
//
//}