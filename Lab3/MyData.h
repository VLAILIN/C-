#pragma once
#include <iostream>
#include "myString.h"
using namespace std;
enum Sex { UNDEF, MALE, FEMALE };
class MyData {
private:
	Sex sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public: //Подумайте, все ли перечисленные ниже методы надо реализовывать
	//MyData();
	MyData(Sex s = UNDEF, size_t age = 30, const char* job = "undef" , float sal = 30000);

	~MyData() = default;
	MyData(const MyData& d) = default;
	MyData & operator=(const MyData& d)= default;
	MyData(MyData&& d)= default;
	MyData& operator=(MyData&& d)= default;

	friend ostream& operator<<(ostream& os, const MyData& d);
	
	friend class Pair;
};