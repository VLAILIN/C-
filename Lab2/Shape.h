#pragma once
#include <iostream>
enum COLORS {BLUE, GREEN, WHITE, BLACK, RED, YELLOW, ORANGE};
class Shape
{
protected:	//��� ������ ������ ���� �������� ������� ����������� �������
	COLORS color;	//���� ������
public:
	Shape(COLORS C=WHITE);//�����������
	//Shape(const Shape &obj); // ����������� �����������
	virtual ~Shape();//����������
	virtual void WhereAmI() const; //����� ���������
	virtual void Inflate(int) = 0; //������� ����������
	//void Inflate(int); //������� ����������
};