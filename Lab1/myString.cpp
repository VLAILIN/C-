#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <cstdarg>
using namespace std;

// ����������� ������������ �� ���������.
MyString::MyString()
{
	m_pStr = nullptr; 
}
// ����������� ������������.
MyString::MyString(const char* p)
{
	m_pStr = new char[strlen(p) + 1]; //+ 1  ��� ��� strlen �� ������� ��������������� ����
	strcpy(m_pStr, p); //�������� ������
}

//����������� �����������
MyString::MyString(const MyString &obj)
{
	if (obj.m_pStr!=nullptr)
	{
		m_pStr = new char[strlen(obj.m_pStr) + 1]; //+ 1  ��� ��� strlen �� ������� ��������������� ����
		strcpy(m_pStr, obj.m_pStr); //�������� ������
	}
	else m_pStr = nullptr;
}

//move ����������� �����������
MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
}

// ����� ��������� ������
const char* MyString::GetString() const
{
	if (this == nullptr) return "No string here";
	if (m_pStr==nullptr) return "No string here";
	return m_pStr;
}

//����� ������ ������ �� �����
void MyString::SetNewString(const char* p)
{
	delete[] m_pStr; //���������� ������

	m_pStr = new char[strlen(p) + 1]; //+ 1  ��� ��� strlen �� ������� ��������������� ����
	strcpy(m_pStr, p); //�������� ������
}

// ����������� �����������.
MyString::~MyString()
{
	delete[] m_pStr;
	//m_pStr = nullptr;
}

MyString �oncat_str(const char* first, ...)
{
	unsigned int count = 0; //������ ����� ������

	const char* ch = first;
	va_list p; //������������� ���������
	va_start(p, first); //��������� ������������� ��������� �� ������ �������������� ��������

	//���� ��� ���������� ����� ������
	while (ch != nullptr)
	{
		count += strlen(ch);
		ch = va_arg(p, const char*);
	}

	char* tmp = new char[count+1]; //�������� ������ ��� ����� ������
	tmp[0] = '\0';

	ch = first;
	va_start(p, first); //��������� ������������� ��������� �� ������ �������������� ��������

	//���� ��� ������������
	while (ch != nullptr)
	{
		strcat(tmp, ch); //������������ �����
		ch = va_arg(p, const char*);
	}

	va_end(p); //��������� �������������� ���������

	MyString str1(tmp); //������� ������ ������
	
	delete[] tmp; //���������� ������
	tmp = nullptr;

	return std::move(str1);
}