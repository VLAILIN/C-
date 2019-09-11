#pragma once
#include "Shape.h"
class Rect:public Shape
{
private:
	int m_left, m_top, m_right, m_bottom; //���������� ���� ����� ��������������
public:
	Rect(int x1=0, int y1=0, int x2=0, int y2=0, COLORS C=WHITE); //����������� � �����������
	//Rect(const Rect &obj); // ����������� �����������
	virtual void WhereAmI() const; //����� ���������
	void GetAll(int&, int&, int&, int&) const; //������� ����������� �������� private-���������� ������
	void Inflate(int);
	virtual ~Rect(); //���������� ������
};



/*
private:
	 m_left, m_right, m_top, m_bottom; //���������� ��������������
public:
	Rect(); //����������� �� ���������
	Rect(int, int, int, int); //����������� � �����������
	Rect(const Rect &obj); // ����������� �����������
	void InflateRect(int, int, int, int); //������� ���������� ��������������
	void InflateRect(int=1, int=1); //������� ���������� �������������� � ����� ����������� �� ���������
	void SetAll(int, int, int, int); //��������� �������� ��������� ��������������
	void GetAll(int&, int&, int&, int&) const; //������� ����������� �������� private-���������� ������
	void BoundingRect(const Rect&, const Rect&);
	~Rect(); //���������� ������
protected:
	void Normalize(); //������������ ��������������
*/