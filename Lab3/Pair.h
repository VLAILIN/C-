#pragma once
#include "MyData.h"

class Pair {
	MyString key; //���� - �������
	MyData data; // MyData* pData; //������ � ����������
	//���������, ��� �� ������������� ���� ������ ���� �������������
	Pair():key("default"), data(UNDEF, 30, "undef", 30000) {}
	Pair(const char* k, Sex s, size_t age, const char* job, float sal);
	Pair(const char* k, const MyData& other);
	~Pair() = default;
	Pair(const Pair& other) = default;
	Pair& operator=(const Pair& other) = default;
	Pair(Pair&& other) = default;
	Pair& operator=(Pair&& other) = default;
	bool operator==(const char *k) const;
	
	friend ostream& operator<<(ostream& os, const Pair& pair);
	
	friend class BD;
};