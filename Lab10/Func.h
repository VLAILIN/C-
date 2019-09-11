#pragma once

#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

#include "Point.h"
#include "Rect.h"
#include <string>
#include <clocale>
#include <typeinfo>

#include <iostream>
using namespace std;

struct ForPrint
{
	template <typename T> void operator ()(T n) const { cout << "value = " << n << endl; };
};

class plusN
{
	int m_x;
public:
	plusN(int x) { m_x = x; }
	template <typename T> void operator ()(T& n) { n += m_x; };
};

class Diapazon
{
	int m_x, m_y;
public:
	Diapazon(int x, int y) { m_x = x; m_y = y;}
	bool operator ()(Point& n) { return ((n.getX()>=(-m_x))&&(n.getX()<=m_y))&&((n.getY() >= (-m_x))&&(n.getY() <= m_y)); };
};



template <typename T> void priN(const T& n)
{ 
	cout << "value = " << n << endl;
};

void changeReg(string& n)
{
	
	transform(n.begin(), n.end(), n.begin(), [](char c) {return tolower(c); });
	
};

string ToLowerCase(string s) 
{
	transform(s.begin(), s.end(), s.begin(), [](char c) {return tolower(c);});
	return s;
}


template <typename T> void printAll(const T& v)
{
	if (v.size()) //если контейнер не пустой
	{
		typename T::const_iterator itb = v.cbegin();
		typename T::const_iterator ite = v.cend();

		cout << typeid(v).name() << endl;

		for_each(itb, ite, ForPrint());

		cout << endl;
	}
	else cout << "No elements here!" << endl;
}


 bool CmpDistance(const Rect& r1, const Rect& r2)
{
	return r1.getDistance() < r2.getDistance();
}

