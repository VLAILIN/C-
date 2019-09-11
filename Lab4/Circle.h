#pragma once
#include "Point.h"

class Circle
{
private:
	Point centr; //���������� ������
	float radius; //������ ����������
public:
	
	Circle():centr(0, 0) {radius=0;} //�����������
	Circle(int x, int y, float r); //����������� � �����������	
	Circle(const Point& p, float r); //����������� � �����������
	bool operator==(const Circle& d) const; //�������� ���������
	float GetRadius() const;

	bool CmpNodeSquare(const Circle& c2) const; //��������� ��������� �� ��������

	~Circle() = default;
	Circle(const Circle& d) = default;
	Circle& operator=(const Circle& d)= default;
	Circle(Circle&& d)= default;
	Circle& operator=(Circle&& d)= default;
	
	friend class Node;

	friend ostream& operator<<(ostream& os, const Circle& d);
	
};