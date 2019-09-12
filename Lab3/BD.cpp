#include "BD.h"

BD::BD() //конструктор по умолчанию
{
	pBase = new Pair[10];
	m_cap = 10;
	m_size = 0;
}

BD::~BD() //деструктор
{
	delete[] pBase;
}

BD::BD(const BD& bd) //конструктор копирования
{
	m_size = bd.m_size;

	if (bd.m_size!=0)
	{
		m_cap = bd.m_size;
		pBase = new Pair[bd.m_size];

		for (size_t i = 0; i < bd.m_size; i++) 
		{
			pBase[i] = bd.pBase[i]; 		
		}
	}
	else
	{
		pBase = new Pair[10];
		m_cap = 10;
	}
}

BD::BD(BD&& bd) //move конструктор копирования
{
	pBase = bd.pBase;
	bd.pBase = nullptr;

	m_cap = bd.m_cap;
	m_size = bd.m_size;

	bd.m_cap = 0;
	bd.m_size = 0;
}

BD& BD::operator=(const BD& bd) //оператор присваивания оптимизированный!!!
{
	if (this != &bd)
	{
		if (m_cap < bd.m_size) //если емкости не хватает
		{
			delete[] pBase;
			m_cap = bd.m_size; //будем копировать полезное содержимое
			pBase = new Pair[m_cap];
		}
		m_size = bd.m_size; 
				
		for (size_t i = 0; i < m_size; i++) //копируем объекты
		{
			pBase[i] = bd.pBase[i]; 		
		}

	}
	return *this;
}

BD& BD::operator=(BD&& bd) //move оператор присваивания
{
	if (this != &bd)
	{
			delete[] pBase;
			pBase = bd.pBase;
			bd.pBase = nullptr;
		
			m_cap = bd.m_cap;
			m_size = bd.m_size;

			bd.m_cap = 0;
			bd.m_size = 0;
	}
	return *this;
}

MyData& BD::operator[](const char *key) 
{
	//ищем сотрудника в базе
	for (size_t i = 0; i < m_size; i++) 
	{
		if (pBase[i].key == key) 
		return pBase[i].data; //возвращаем данные по ключу
	}
	
	//если сотрудник не найден, добавляем данные
	if(m_size >= m_cap) 
	{
		//перераспределяем память
		m_cap++;
		Pair* tmp = new Pair[m_cap];

		for (size_t i = 0; i < m_size; i++)
		{
			tmp[i] = std::move(pBase[i]); // move семантика
		}
		
		delete[] pBase;
		pBase = tmp;
		tmp = nullptr;
	}
		
	//добавляем сотрудника
	pBase[m_size].key = key;
	m_size++;

	return pBase[m_size-1].data; 
}

void BD::deletePair(const char* key) //удаление строки из массива
{
		size_t n = 0;
		bool flag = false;
		for (size_t i = 0; i < m_size; i++) //ищем нужную запись
		{
			if (pBase[i].key == key)
			{	
				n = i;
				flag = true;
				break;
			}
		}

		if (!flag) //если нет записи
		{
			cout << "Pair don't exsist" << endl;
			return;
		}

		//затираем необходимую строку массива
		//	for (size_t i = n; i < m_size-1; i++) 
		if (n!= m_size - 1)
		{
			pBase[n] = std::move(pBase[m_size - 1]); // move семантика, последний копируем на место удаляемого
		}
		else pBase[m_size - 1].key = "default"; // или nullptr
		m_size--;
}

ostream& operator<<(ostream& os, const BD &bd)
{
	for (size_t i=0; i<bd.m_size; i++)
	{
	os << bd.pBase[i]<<"\n";
	}
	return os;
}
