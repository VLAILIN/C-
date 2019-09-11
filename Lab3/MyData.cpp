#include "MyData.h"

MyData::MyData(Sex s, size_t age, const char* job, float sal):m_job(job)
{
	sex = s;
	m_age = age;
	m_salary = sal;
}

const char* tmps[] = {"Undef", "Male", "Female"};

ostream& operator<< (ostream& os, const MyData& d)
{
	os << "sex: "<<tmps[d.sex]<< "  age: "<<d.m_age<<"  job: "<<d.m_job<<"  salary: "<<d.m_salary <<"\n";;
	return os;
}
