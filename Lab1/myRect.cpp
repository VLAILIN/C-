#include "myRect.h"

Rect::Rect() //����������� �� ���������
{
	m_left = 0;
	m_right = 0;
	m_top = 0;
	m_bottom = 0;
}

Rect::Rect(int r_left, int r_right, int r_top, int r_bottom) //����������� � �����������
{
	Normalize();
	m_left = r_left;
	m_right = r_right;
	m_top = r_top;
	m_bottom = r_bottom;
}

void Rect::InflateRect(int x, int y, int z, int t) //������� ���������� ��������������
{
	m_left -= x;
	m_right += y;
	m_top += z;
	m_bottom -= t;
}

Rect::Rect(const Rect &obj) //����������� �����������
{
	m_left = obj.m_left;
	m_right = obj.m_right;
	m_top = obj.m_top;
	m_bottom = obj.m_bottom;
}

void Rect::InflateRect(int x, int y) //������� ���������� �������������� � ����������� �� ���������
{
	m_right += x;
	m_top += y;

	/*m_left -= x;
	m_right += x;
	m_top += y;
	m_bottom -= y;*/

}

void Rect::SetAll(int x, int y, int z, int t) //��������� �������� ��������� ��������������
{
	Normalize();
	m_left = x;
	m_right = y;
	m_top = z;
	m_bottom = t;
}

void Rect::GetAll(int &x, int &y, int &z, int &t) const //������� ����������� �������� private-���������� ������
{
	x = m_left;
	y = m_right;
	z = m_top;
	t = m_bottom;
}

void Rect::Normalize() //������������ ��������������
{
	if (m_left > m_right)
	{
		int tmp = m_left;
		m_left = m_right;
		m_right = tmp;
	}

	if (m_bottom > m_top)
	{
		int tmp = m_bottom;
		m_bottom = m_top;
		m_top = tmp;
	}
}

void Rect::BoundingRect(const Rect &r1, const Rect &r2)
{
	int r_left = ((r1.m_left <= r2.m_left) ? r1.m_left : r2.m_left) - 1; //��������� ���������� ����� ���������� � -1
	int r_right = ((r1.m_right >= r2.m_right) ? r1.m_right : r2.m_right) + 1; //��������� ���������� ������ ���������� � +1
	int r_top = ((r1.m_top >= r2.m_top) ? r1.m_top : r2.m_top) + 1; //��������� ���������� ������� ���������� � +1
	int r_bottom = ((r1.m_bottom <= r2.m_bottom) ? r1.m_bottom : r2.m_bottom) - 1; //��������� ���������� ������ ���������� � -1

	SetAll(r_left, r_right, r_top, r_bottom); //��������� �������������, � ������� ������� ��������
}

Rect::~Rect() //���������� 
{
	m_left = -1;
	m_right = -1;
	m_top = -1;
	m_bottom = -1;

	//std::cout << "destructor" << std::endl;
}

Rect BoundingRect(Rect r1, Rect r2)
{
	int r1_left = 0, r1_right = 0, r1_top = 0, r1_bottom = 0; //���������� ��� �������� �������� private-���������� ������
	int r2_left = 0, r2_right = 0, r2_top = 0, r2_bottom = 0; //���������� ��� �������� �������� private-���������� ������

	r1.GetAll(r1_left, r1_right, r1_top, r1_bottom); //����� ������
	r2.GetAll(r2_left, r2_right, r2_top, r2_bottom); //����� ������
	
	int r_left = ((r1_left<=r2_left)?r1_left : r2_left) - 1; //��������� ���������� ����� ���������� � -1
	int r_right = ((r1_right>=r2_right)?r1_right : r2_right) + 1; //��������� ���������� ������ ���������� � +1
	int r_top = ((r1_top>=r2_top)?r1_top : r2_top) + 1; //��������� ���������� ������� ���������� � +1
	int r_bottom = ((r1_bottom<=r2_bottom)?r1_bottom : r2_bottom) - 1; //��������� ���������� ������ ���������� � -1

	Rect r(r_left, r_right, r_top, r_bottom); //������� �������������, � ������� ������� ��������
	return r; 
}

Rect BoundingRect2(const Rect &r1, const Rect &r2)
{
	int r1_left = 0, r1_right = 0, r1_top = 0, r1_bottom = 0; //���������� ��� �������� �������� private-���������� ������
	int r2_left = 0, r2_right = 0, r2_top = 0, r2_bottom = 0; //���������� ��� �������� �������� private-���������� ������

	r1.GetAll(r1_left, r1_right, r1_top, r1_bottom); //����� ������
	r2.GetAll(r2_left, r2_right, r2_top, r2_bottom); //����� ������

	int r_left = ((r1_left <= r2_left) ? r1_left : r2_left) - 1; //��������� ���������� ����� ���������� � -1
	int r_right = ((r1_right >= r2_right) ? r1_right : r2_right) + 1; //��������� ���������� ������ ���������� � +1
	int r_top = ((r1_top >= r2_top) ? r1_top : r2_top) + 1; //��������� ���������� ������� ���������� � +1
	int r_bottom = ((r1_bottom <= r2_bottom) ? r1_bottom : r2_bottom) - 1; //��������� ���������� ������ ���������� � -1
	
	Rect r(r_left, r_right, r_top, r_bottom); //������� �������������, � ������� ������� ��������
	return r;
}