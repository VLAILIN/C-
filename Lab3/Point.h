#pragma once

class Point
{
private:
	int m_x, m_y; //���������� ����� 
public:
	Point(int x=0, int y=0); //����������� � �����������
	Point& operator+=(const Point& obj); //�������� +=
	Point& operator+=(int); //�������� +=
	Point operator+(const Point& obj) const; //�������� +
	Point operator+(int) const; //�������� +
	const Point& operator+() const; //�������� ������� +
	Point operator-() const; //�������� ������� -

friend Point& operator-=(Point& obj1, const Point& obj2); //�������� -=
friend Point& operator-=(Point& obj1, int n); //�������� -=
friend Point operator+(int n, const Point& obj); //�������� +
friend Point operator-(const Point& obj1, const Point& obj2); //�������� -
friend Point operator-(const Point& obj1, int n); //�������� -

};


