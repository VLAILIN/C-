//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

//#include <iostream>
//#include <vector>
//#include <vector>
#include "myString.h"
#include "Check.h"
#include "Point.h"


#pragma warning(disable: 4786)


//using namespace std;	

#define	  stop __asm nop


int main()
{
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	vector<int> vInt;
	size_t v_size = vInt.size();
	stop

	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	vInt.resize(1);
	vInt.front()=1;
	stop


	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	
		for (size_t i = 2; i < 11; i++)
		{
			vInt.push_back(i);
			Check(vInt);
		}
		stop

	

	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	
	vector<double> vDouble1(10);
	Check(vDouble1); //проинициализированы нулем
	stop

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 


	vector<MyString> mStr(5, "A");
	mStr[1] = "C++";
	mStr.at(0) = "C#";
	stop

	//в операторе индексирования [] нет проверок выхода индекса за пределы массива
	//mStr.at(6) = "C#"; //в методе at генерируется исключение out of range

	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	
	vector<double> dMas(10);
	for (size_t i = 0; i < dMas.size(); i++)
	{
		dMas[i] =i;
	}
	stop
	Check(dMas);
	
	vector<double>::iterator it = dMas.begin();
	stop

	vector<double> vDouble3(it, it+6);
	Check(vDouble3);
	stop
	
	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	
	vector<double>::iterator itb = vDouble3.begin(), ite = vDouble3.end();
	stop

	vector<double> vDouble4(itb+2, ite);
	Check(vDouble4);
	stop

	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	vector<Point> vPoint1(3); //будет вызван конструктор по умолчанию (0,0)
	Check(vPoint1);
	stop

	vector<Point> vPoint2(5, Point(1,1)); //будет вызван конструктор c параметрами (1,1)
	Check(vPoint2);
	stop


	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
		vector<Point*> vpPoint(5);
		Check(vpPoint);

		for (size_t i = 0; i < vpPoint.size(); i++)
		{
			vpPoint[i] = new Point(i, i + 1);
		}
		Check(vpPoint);
		stop


	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*

		for (size_t i = 0; i < vpPoint.size(); i++)
		{
			delete vpPoint[i];
			vpPoint[i] = nullptr;
		}
		Check(vpPoint);
		stop

	}//Какие дополнительные действия нужно предпринять для такого вектора?


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
		{
		size_t n = 10;
		vector<int> v(n);
		v.resize(n/2);
		if (v.capacity() == n) cout << "TRUE!" << endl;; //true? TRUE
		Check(v);
		}
		
		{
		int n=10;
		size_t m = 20;
		vector<int> v(n);
		v.reserve(m);
		if (v.capacity() == m) cout << "TRUE!" << endl; //true? TRUE если m>n и false если m<n, в меньшую сторону не будет перераспределения
		else cout << "FALSE!"<<endl;
		Check(v);		
		}
		
		{
		vector<int> v(3,5); // 5 5 5 
		v.resize(4,10); //значения? - 5 5 5 10
		v.resize(5); //значения? - 5 5 5 10 0
		Check(v);
		}
		

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов

		vector<int> ve1, ve2;
		ve1.reserve(5);
		Check(ve1);

		for (size_t i = 0; i < 5; i++)
		{
			ve1.push_back(i);
		}
		Check(ve1);

		for (size_t i = 0; i < 5; i++)
		{
			ve2.push_back(i);
		}
		Check(ve2);
	
		//capacity второго вектора больше чем у первого


	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.

		ve2.shrink_to_fit();
		Check(ve2);
		stop
	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	int ar[] = { 11,2,4,3,5 };
	
	vector<vector<int>> vv;

	for (size_t i = 0; i < sizeof(ar)/sizeof(ar[0]); i++)
	{
		//vv.push_back(vector<int>(ar[i], ar[i]));
		vv.emplace_back(ar[i], ar[i]); //менее затратный вариант, без копий
		
	}
	stop
	std::cout << vv;
	stop

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Вставка элемента последовательности insert().
	

	char tmp2[] = "qwerrrrty12222r3";

	char tmp[] = "qwerty";
	vector<char> vChar2;
	
	for (size_t i = 0; i < sizeof(tmp) / sizeof(tmp[0]); i++)
	{
		vChar2.emplace_back(tmp[i]); 
	}
	stop
	
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.

	vector<char>::const_iterator itc2 = vChar2.cbegin();
	vector<char>::const_iterator itc2e = vChar2.cend();

	bool b = true;

	while (itc2!=itc2e)
	{
		if (*itc2 == 'b')
		{
			b = false;
			break;
		}
		++itc2;
	}

	if (b) vChar2.insert(vChar2.begin(), 'b');
	stop

	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
		
	vector<char>::iterator itc = vChar2.begin();
	int size_v = vChar2.size()-1;

	for(int i=0; i<size_v; i++ )
	{		
		itc = vChar2.insert(itc, 'W');
		++itc;
		++itc;
	}
	Check(vChar2);

///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"

	vector<int> vInt7 = { 1,1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5 };
	vector<char> vChar3;

	for (size_t i = 0; i < sizeof(tmp2) / sizeof(tmp2[0]); i++)
	{
		vChar3.emplace_back(tmp2[i]);
	}
	stop

	Del_same(vInt7);
	Check(vInt7);
	stop

	Del_same(vChar3);
	Check(vChar3);

	stop
	
///////////////////////////////////////////////////////////////////

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 

	vector<int> vInt8 = {1,2,3,1,1,1,1,3,2,1,2,2,3,1,3,2,3,1,2,3,1,2,3};
	Del_double(vInt8);
	Check(vInt8);
	stop

///////////////////////////////////////////////////////////////////
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке

	vector<int> vInt9 = { 11,2,4,3,5 };
	vector<int>::reverse_iterator it5 = vInt9.rbegin();
	vector<int>::reverse_iterator it6 = vInt9.rend();

	vector<int> vInt10(it5, it6);
	Check(vInt10);
	stop
		
		///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()

	list<Point> ptList1;
	
	ptList1.push_back(Point(1,1));
	ptList1.push_back(Point(2, 2));
	ptList1.push_back(Point(3, 3));
	ptList1.push_back(Point(4, 4));
	ptList1.push_back(Point(5, 5));
	stop

	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.

	printAll(ptList1);
	stop

	//Сделайте любой из списков "реверсивным" - reverse()

	ptList1.reverse();
	printAll(ptList1);
	stop
	
	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 

	vector<Point> vPoint4 = { Point(1, 1), Point(-5, -5), Point(99, 99), Point(34, 34), Point(7, 7) };
	vector<Point>::reverse_iterator it7 = vPoint4.rbegin();
	vector<Point>::reverse_iterator it8 = vPoint4.rend();
	list<Point> ptList2(it7, it8);
	printAll(vPoint4);
	printAll(ptList2);
	stop

	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка

	ptList1.sort();
	printAll(ptList1);
	ptList2.sort();
	printAll(ptList2);
	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.

	ptList1.merge(ptList2);
	printAll(ptList1);
	
	stop

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
	
	ptList1.remove(Point(3, 3));
	printAll(ptList1);
	stop

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 

	ptList1.remove_if([](const Point& c) -> bool {return ((c.getX() < 0) || (c.getY() < 0));}); //используется лямбда функция вместо предиката глоабальной функции
	printAll(ptList1);
	stop

	//Исключение из списка подряд расположенных дублей - unique(). 
	ptList1.unique();
	printAll(ptList1);
	stop

	///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать

	deque<Point> pDeq;
	vector<Point>::iterator it9 = vPoint4.begin();
	vector<Point>::iterator it10 = vPoint4.end();
	pDeq.assign(it9, it10);
	printAll(pDeq);
	stop


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'

	deque<MyString> sDeq;
	sDeq.push_back("assembler");
	sDeq.push_back("C++");
	sDeq.push_front("C#");
	sDeq.push_front("Java");
	sDeq.insert(sDeq.begin(), "Python");
	printAll(sDeq);
	stop

	deque<MyString>::iterator itq = sDeq.begin();	
	while (itq != sDeq.end())
	{
		if ((itq[0] == 'a') || (itq[0] == 'A')) itq = sDeq.erase(itq);
		else ++itq;
	}

	printAll(sDeq);
	stop

	return 0;
}
