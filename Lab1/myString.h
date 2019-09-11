#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
public:
	MyString(); //����������� �� ���������
	MyString(const char*); //����������� � ����������
	MyString(const MyString &obj); // ����������� �����������
	MyString(MyString&&); //move ����������� �����������
	const char* GetString() const; // ����� ��������� ������
	void SetNewString(const char*); //����� ������ ������ �� �����
	~MyString();//���������� ������
};

MyString �oncat_str(const char *, ...);