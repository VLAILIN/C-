#pragma once
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <typeinfo>

#include <iostream>

using namespace std;

//template <typename T1, typename T2> T2& getTop(const T1& v)

template <typename T> const typename T::value_type& getTop(const T& v)
{
	return v.top();
}

template <typename T1, typename T2> const T1& getTop(const queue<T1, T2>& v)
{
	return v.front();
}



template <typename T> void printAdapters(T v)
{
	if (v.size()) //если контейнер не пустой
	{
		cout << typeid(v).name() << endl;

		while (v.size())
		{
			cout << getTop(v) << endl;
			v.pop();
		}
		cout << endl;
	}
	else cout << "No elements here!" << endl;
}



//template <typename T1, typename T2> void printAdapters(queue<T1, T2> v)  //, typename T3
//{
//	if (v.size()) //если контейнер не пустой
//	{
//		cout << typeid(v).name() << endl;
//
//		while (v.size())
//		{
//			cout << v.front() << endl;
//			v.pop();
//		}
//		cout << endl;
//	}
//
//	else cout << "No elements here!" << endl;
//}

template <typename T> void printAll(T& v)
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

struct StringLess 
{

	bool operator()(const char* l, const char* r) const {return strcmp(l, r)<0;};

};

template <typename T1, typename T2, typename T3> void printMap(map<T1, T2, T3>& v) 
{
	
	map<T1, T2>::template const_iterator itb = v.cbegin();
	map<T1, T2>::template const_iterator ite = v.cend();

	cout << typeid(v).name() << endl;
	while (itb != ite)
	{
		cout<<"key: " << (*itb).first<<" value: " << (*itb).second << endl;
		++itb;
	}
	cout << endl;
}

template <typename T1, typename T2, typename T3> void printMultiMap(multimap<T1, pair<T2, T3>>& v) 
{
	
	multimap<T1, pair<T2, T3>>::template const_iterator itb = v.cbegin();
	multimap<T1, pair<T2, T3>>::template const_iterator ite = v.cend();

	cout << typeid(v).name() << endl;
	while (itb != ite)
	{
		cout<<"key: " << (*itb).first<<" value: " << (*itb).second.first <<", "<< (*itb).second.second<< endl;
		++itb;
	}
	cout << endl;
}

void printMultiMapKey(multimap<string, pair<string, string>>& v, const string key);
