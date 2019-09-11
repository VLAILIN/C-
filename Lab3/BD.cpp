#include "BD.h"

BD::BD() //����������� �� ���������
{
	pBase = new Pair[10];
	m_cap = 10;
	m_size = 0;
}

BD::~BD() //����������
{
	delete[] pBase;
}

BD::BD(const BD& bd) //����������� �����������
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

BD::BD(BD&& bd) //move ����������� �����������
{
	pBase = bd.pBase;
	bd.pBase = nullptr;

	m_cap = bd.m_cap;
	m_size = bd.m_size;

	bd.m_cap = 0;
	bd.m_size = 0;
}

BD& BD::operator=(const BD& bd) //�������� ������������ ����������������!!!
{
	if (this != &bd)
	{
		if (m_cap < bd.m_size) //���� ������� �� �������
		{
			delete[] pBase;
			m_cap = bd.m_size; //����� ���������� �������� ����������
			pBase = new Pair[m_cap];
		}
		m_size = bd.m_size; 
				
		for (size_t i = 0; i < m_size; i++) //�������� �������
		{
			pBase[i] = bd.pBase[i]; 		
		}

	}
	return *this;
}

BD& BD::operator=(BD&& bd) //move �������� ������������
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
	//���� ���������� � ����
	for (size_t i = 0; i < m_size; i++) 
	{
		if (pBase[i].key == key) 
		return pBase[i].data; //���������� ������ �� �����
	}
	
	//���� ��������� �� ������, ��������� ������
	if(m_size >= m_cap) 
	{
		//���������������� ������
		m_cap++;
		Pair* tmp = new Pair[m_cap];

		for (size_t i = 0; i < m_size; i++)
		{
			tmp[i] = std::move(pBase[i]); // move ���������
		}
		
		delete[] pBase;
		pBase = tmp;
		tmp = nullptr;
	}
		
	//��������� ����������
	pBase[m_size].key = key;
	m_size++;

	return pBase[m_size-1].data; 
}

void BD::deletePair(const char* key) //�������� ������ �� �������
{
		size_t n = 0;
		bool flag = false;
		for (size_t i = 0; i < m_size; i++) //���� ������ ������
		{
			if (pBase[i].key == key)
			{	
				n = i;
				flag = true;
				break;
			}
		}

		if (!flag) //���� ��� ������
		{
			cout << "Pair don't exsist" << endl;
			return;
		}

		//�������� ����������� ������ �������
		//	for (size_t i = n; i < m_size-1; i++) 
		if (n!= m_size - 1)
		{
			pBase[n] = std::move(pBase[m_size - 1]); // move ���������, ��������� �������� �� ����� ����������
		}
		else pBase[m_size - 1].key = "default"; // ��� nullptr
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