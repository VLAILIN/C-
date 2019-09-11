#pragma once
#include "Counter.h"

class MyString
{
    Counter* m_pC;	//������-���� ������
public:

	MyString(const char* s = " "); //����������� � ����������

	MyString(const MyString &obj); // ����������� �����������
	MyString(MyString&&); //move ����������� �����������

	MyString& operator = (const MyString& obj); //�������� ������������
	MyString& operator = (MyString&& obj); //move �������� ������������
	
	const char* GetString() const; // ����� ��������� ������
	bool operator==(const char *k) const; //�������� ���������

	static void printAll(); //������ ���� �����
	static void ChangeRegister(); //��������� ��������
	static void printSort(); //������

	~MyString();//���������� ������

	friend ostream& operator<< (ostream& os, const MyString& obj);
};

//	MyString& operator = (const char* k); //�������� ������������
//void SetNewString(const char*); //����� ������ ������ �� �����