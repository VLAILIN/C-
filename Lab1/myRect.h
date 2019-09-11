#pragma once
#include <iostream>
class Rect
{
private:
	int m_left, m_right, m_top, m_bottom; //���������� ��������������
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
};

Rect BoundingRect(Rect, Rect);

Rect BoundingRect2(const Rect&, const Rect&);