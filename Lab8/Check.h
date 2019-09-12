#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <typeinfo>

using namespace std;

template <typename T> void Check(const vector<T>& v)
{
	if (v.size()) //если контейнер не пустой
	{
		//заготовим итераторы
		vector<T>::template const_iterator itb = v.cbegin();
		vector<T>::template const_iterator ite = v.cend();
		cout << endl;

		cout<< "capacity = " << v.capacity() << " size = " << v.size() << " max_size = " << v.max_size() << endl;
		cout << "value: ";

		while (itb != ite)
		{
			cout << *itb << " ";
			++itb;
		}
		cout << endl;
	}
	else cout << "No elements here!" << endl;
}

template <typename T> void Del_same(vector<T>& v)
{
	vector<T>::template iterator itb = v.begin();
	vector<T>::template iterator its;

	while (itb != v.end()-1)
	{
		its = itb + 1;
		if (*its == *itb) itb = v.erase(itb);
		else ++itb;
	}
}

template <typename T> void Del_double(vector<T>& v)
{
	vector<T>::template iterator itb = v.begin();
	vector<T>::template iterator its;

	while (itb != v.end())
	{
		its = itb + 1;
		while (its != v.end())
		{
			if (*its == *itb) its = v.erase(its);
			else ++its;
		}
		 ++itb;
	}
}

template <typename T> void printAll(const T& v)
{
	if (v.size()) //если контейнер не пустой
	{
		typename T::const_iterator itb = v.cbegin();
		typename T::const_iterator ite = v.cend();

		cout << typeid(v).name() << endl;
		while (itb != ite)
		{
			cout << *itb << endl;
			++itb;
		}
		cout << endl;
	}
	else cout << "No elements here!" << endl;
}

template <typename T> ostream& operator<< (ostream& os, const vector<T>& v)
{
	if (v.size()) //если контейнер не пустой
	{		
		for (size_t i = 0; i < v.size(); i++)
		{	
			os <<" "<< v[i] << " ";
		}
		os << "\n";
	}
	else cout << "No elements here!" << endl;

	return os;
}
