#include "Rect.h"

Rect::Rect(int x1, int y1, int x2, int y2, COLORS C):Shape(C)  //�����������, ��������� x1, y1, C ������������� ������������ �������� ������ Shape
{	//����� ������������ ������������� ������ Shape
	m_left = x1;
	m_top = y1;
	m_right = x2;
	m_bottom = y2;
}
/*
Rect::Rect(const Rect &obj):Shape(obj) //����������� �����������, ��������� ����������� ����� ������������� �������� ������ ������� ���������������� ������� �����
{//����� ������������ ����������� ������������� ������ Shape
	m_right = obj.m_right;
	
	m_bottom = obj.m_bottom;
}
*/
void Rect::WhereAmI() const
{
	std::cout << "Now I am in class Rect" << std::endl;
}

void Rect::Inflate(int r) //������� ���������� ��������������
{
	m_left -= r;
	m_right += r;
	m_top += r;
	m_bottom -= r;
}

void Rect::GetAll(int &x, int &y, int &z, int &t) const //������� ����������� �������� private-���������� ������
{
	x = m_left;
	y = m_right;
	z = m_top;
	t = m_bottom;
}

Rect::~Rect() //����������
{
	std::cout << "Now I am in Rect's destructor!" << std::endl;
}//����� ����������� ������������� ������ Shape
