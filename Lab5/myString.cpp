#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <cstdarg>

// Определение конструктора.
MyString::MyString(const char* p)
{
	//m_pC = Counter::find(p);
	Counter* pCur = Counter::pHead;
	while (pCur != nullptr) //бежим по списку
	{
		if (strcmp(p, pCur->m_pStr) == 0) //если нашли объект с такой же строкой
		{
			m_pC = pCur;
			m_pC->AddUser();
			break;
		}
		pCur = pCur->pNext;
	}

	if (pCur == nullptr) m_pC = new Counter(p);
}

//конструктор копирования
MyString::MyString(const MyString &obj)
{
	m_pC = obj.m_pC;
	m_pC->AddUser();
}

//move конструктор копирования
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

// метод получения строки
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

// Определение деструктора.
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
		while (pCur != nullptr) //бежим по списку
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
		while (pCur != nullptr) //бежим по списку
		{
			char* tmp = pCur->m_pStr;
			if (tmp)
			{
				while (*tmp != '\0') //пока не достигли окончания строки 
				{
					if ((*tmp >= 'A') && (*tmp <= 'Z'))  // если ch в пределе от A До Z
					{
						*tmp += 0x20;
					}
					else if((*tmp >= 'a') && (*tmp <= 'z'))
					{
						*tmp -= 0x20;
					}

					tmp++; //перемещаем указатель на следующий символ строки
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
		Counter* pFind = nullptr; //указатель для поиска минимального значения
		Counter* pMin = nullptr; //указатель на минимиальный узел
		Counter* pCurPrev = nullptr;

		while (pCur->pNext != nullptr)  // так как последний автоматически окажется на своем месте
		{
			//Поиск минимального из оставшихся значений
			pMin = pCur; //здесь будет элемент списка с минимальным значением
			pFind = pCur->pNext;

			while (pFind != nullptr) //ищем минимальное значение
			{
				if (strcmp(pFind->m_pStr, pMin->m_pStr)<0) //если меньше
				{
					pMin = pFind;
				}
				pFind = pFind->pNext;
			}

			if (pCur != pMin) //если нашли меньшее значение
			{
				//Меняем связи между элементами списка
				//Находим предыдущий элемент
				Counter* ptmp = Counter::pHead;
				while (ptmp->pNext != pMin) //Ищем элемент предыдущий нашему
				{
					ptmp = ptmp->pNext;
				}
				
				//связываем соседей pMin
				ptmp->pNext = pMin->pNext;
			
				//ставим pMin в новое место
				pMin->pNext = pCur;
				if (pCur== Counter::pHead) Counter::pHead = pMin;

				if (pCurPrev!=nullptr) pCurPrev->pNext = pMin;
				
				pCur = pMin; //переходим на исходную позицию
			}

			pCurPrev = pCur;
			pCur = pCur->pNext; //идем дальше
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
		while (pCur != nullptr) //бежим по списку
		{
			if (strcmp(k, pCur->m_pStr) == 0) //если нашли объект с такой же строкой
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



//метод замены строки на новую
//void MyString::SetNewString(const char* p)
//{
///*
//	delete[] m_pStr; //освободили память
//	if (p != nullptr)
//	{
//		m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
//		strcpy(m_pStr, p); //копируем строку
//	}
//	else m_pStr = nullptr;
//*/
//	
//	if ((m_pStr != nullptr) && (p != nullptr))
//		{
//			if (strlen(m_pStr)<strlen(p))
//			{
//			delete[] m_pStr;
//			m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
//			}
//			strcpy(m_pStr, p); //копируем строку
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
//			m_pStr = new char[strlen(p) + 1]; //+ 1  так как strlen не считает детерминирующий ноль
//			strcpy(m_pStr, p); //копируем строку
//		}
//
//}