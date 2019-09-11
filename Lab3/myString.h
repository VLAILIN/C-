#pragma once
#include <iostream>
using namespace std;
class MyString
{
    char* m_pStr;	//������-���� ������
public:
	MyString(); //����������� �� ���������
	MyString(const char*); //����������� � ����������
	MyString(const MyString &obj); // ����������� �����������
	MyString(MyString&&); //move ����������� �����������
	MyString& operator = (const MyString& obj); //�������� ������������
	MyString& operator = (const char* k); //�������� ������������
	MyString& operator = (MyString&& obj); //move �������� ������������
	MyString operator + (const MyString& obj) const; //�������� ��������
	MyString& operator += (const MyString& obj); //�������� +=
	const char* GetString() const; // ����� ��������� ������
	void SetNewString(const char*); //����� ������ ������ �� �����
	bool operator==(const char *k) const; //�������� ���������
	~MyString();//���������� ������

	friend ostream& operator<< (ostream& os, const MyString& obj);

};

MyString �oncat_str(const char *, ...);