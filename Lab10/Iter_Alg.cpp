// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include "Func.h"

#include <tchar.h>

using namespace std;	
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	set<Point> s1 = {Point(1, 1), Point(5, 5), Point(4, 4), Point(11, 11), Point(9, 9)};

	set<Point>::reverse_iterator itsb = s1.rbegin();
	set<Point>::reverse_iterator itse = s1.rend();

	vector<Point> v1(itsb, itse);
	list<Point> l1(itsb, itse);
	
	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.

	ostream_iterator<Point> out_it (cout,", ");
	copy( s1.begin(), s1.end(), out_it );
	cout << endl;
	copy( v1.begin(), v1.end(), out_it );
	cout << endl;

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter() // vector, deque и list контейнеры с push_back 
	//front_inserter()// контейнеры с push_front
	//inserter() контейнеры с insert
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.

	back_insert_iterator<vector<Point>> itv = back_inserter(v1);
	*itv = Point(2, 2);
	insert_iterator<set<Point>> its = inserter(s1, s1.begin());
	*its = Point(7, 7);
	front_insert_iterator<list<Point>> itl = front_inserter(l1);
	*itl = Point(3, 3);
	stop
		
		///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон

	vector<int> v2 = {1,3,56,78,4,7,4,7,4};
	
	for_each(v2.begin(), v2.end(), priN<int>);
	cout << endl;

	printAll(v2);
	stop

	

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката

	vector<Point> v3 = { Point(1,1), Point(2,2), Point(9,9), Point(2,2), Point(3,3), Point(2,2), Point(7,7) };
	

	for_each(v3.begin(), v3.end(), plusN(3));
	stop
	for_each(v3.begin(), v3.end(), priN<Point>);
	cout << endl;


	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
	
	list<Point>  l; //для результата 
	vector<Point>::iterator itv1 = v3.begin();

	while (itv1!=v3.end())
	{
		itv1 = find(itv1, v3.end(), Point(5, 5));
		if (itv1 == v3.end()) break;
		l.push_back(*itv1);
		++itv1;
	}
		
	printAll(l);
	stop
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	
	sort(v3.begin(), v3.end());
	printAll(v3);
	stop

	
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

	list<Point>  l2; //для результата 
	auto itv2 = v3.begin();

	while (itv2 != v3.end())
	{
		itv2 = find_if(itv2, v3.end(), Diapazon(1,6));
		if (itv2 == v3.end()) break;
		l2.push_back(*itv2);
		++itv2;
	}
	printAll(l2);
	stop


	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.

	vector<Rect> r1 = {Rect(1,10,10,1), Rect(5,45,25,10),Rect(9,100,99,28),Rect(23,67,47,14),Rect(33,76,99,28),Rect(44,66,88,22),Rect(34,66,80,29),Rect(11,100,64,13),Rect(38,91,97,64), Rect(5,25,45,5)};
	printAll(r1);
	stop

	//sort(r1.begin(), r1.end(), CmpDistance);

	sort(r1.begin(), r1.end(), [](const Rect& r1, const Rect& r2) { return r1.getDistance() < r2.getDistance();}); //вариант с лямбда

	printAll(r1);
	stop


	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

	string s5 = "C++foReVeR";
	
	changeReg(s5);

	printAll(s5);
	
	stop



	//Заполните list объектами string. С помощью алгоритма transform сформируте
	//значения "пустого" set, конвертируя строки в нижний регистр

	list<string> l5 = { "C++", "C#", "SQL", "PyTHon", "JaVa" };
	set<string> s9;

	insert_iterator<set<string>> its5 = inserter(s9, s9.end());
	
	transform(l5.begin(), l5.end(), its5, ToLowerCase);  
	//transform(l5.begin(), l5.end(), its5, [](string s) { transform(s.begin(), s.end(), s.begin(), [](char c) {return tolower(c); });  return s; }); //вариант с лямбда

	printAll(s9);

		stop
	}
	

	return 0;
}

