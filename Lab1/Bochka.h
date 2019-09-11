#pragma once
#include <iostream>

class Bochka
{
private:
	double c_spirt, c_water; 
public:
	Bochka(); //����������� �� ���������
	Bochka(double, double); //����������� � �����������
	Bochka(const Bochka &); // ����������� �����������
	void SetAll(double, double); //��������� �������� 
	double ProcentSpirt() const;
	void Print() const; //������
	void Pereliv(Bochka &, double); //������� ��������
	//~Bochka(); //���������� ������
};