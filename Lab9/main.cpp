// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <tchar.h>
#include "Func.h"
#include "Point.h"

#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений
	

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

	vector<int> v = {1, 2, 3, 4, 5};

	vector<int>::reverse_iterator itrb = v.rbegin();
	vector<int>::reverse_iterator itre = v.rend();
		
	stop
	stack<int, vector<int>> s1(v); //а

	printAdapters(s1);
	stop
	
	//v.assign( v.rbegin(), v.rend() );
	
	stack<int, vector<int>> s2; //б

	while (itrb != itre)
	{
		s2.push(*itrb);
		++itrb;
	}

	printAdapters(s2);
	stop

	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?


	queue<Point*, list<Point*>> q1;
	q1.push(new Point(1,1));
	q1.push(new Point(3,3));
	q1.push(new Point(5,5));

	printAdapters(q1);
	stop

	delete q1.front();
	q1.front() = new Point(7, 7);
	
	delete q1.back();
	q1.back() = new Point(9, 9);

	while (q1.size())
	{
		delete q1.front();
		q1.pop();
	}

	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?

	const char* ar[] = {"C++", "C#", "SQL", "Python", "Java"}; 

	priority_queue<const char*> pq1(ar, ar + (sizeof(ar) / sizeof(ar[0]))); //а,б  

	printAdapters(pq1);				
	stop

	//сравниваются указатели, поэтому последний элемент массива является наибольшим элементом
	
	//создадим очередь с компаратором для сравнения строк

	priority_queue<const char*, vector<const char*>, StringLess> pq2(ar, ar + (sizeof(ar) / sizeof(ar[0])));
	printAdapters(pq2);
	stop
		
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

	set<Point> st1; //а
	st1.insert(Point(1, 1));
	st1.insert(Point(9, 9));
	st1.insert(Point(4, 4));
	st1.insert(Point(6, 6));
	st1.insert(Point(3, 3));
	st1.insert(Point(8, 8));

	printAll(st1); //б
	stop

	//в - компилятор выдаст ошибку - потому что при изменениии значения пришлось бы менять всё дерево, значения хранятся как константные

	set<int> st2 = {3,78,5,9,6,8,12,4,16}; //г -данные хранятся всегда в упорядоченном виде
	printAll(st2);

	set<int> st3 = {9,12,3,8,5,78,16,4,6};
	printAll(st3);

	int ar_int[] = {3,4,5,2,4,5,2,4,7,8,9,3,6,5}; //д - дубли игнорируются
	set<int> st4(ar_int, ar_int+(sizeof(ar_int)/sizeof(ar_int[0])));
	printAll(st4);
	stop



	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	stop
	
	map<const char*, int, StringLess> m1; //а

	m1["Petrov"] = 20000;
	m1["Ivanova"] = 10000; //б
	m1["Sidorov"] = 15000;	
	
	m1.insert(pair<const char*, int>("Veselov", 40000));
	m1.insert(pair<const char*, int>("Alekseev", 35000));

	printMap(m1); //в
	stop

	pair<const char*, int> p1 = *(m1.find("Ivanova")); //г //находим нужную пару
	p1.first = "Petrova"; //присваиваем новый ключ
	m1.erase("Ivanova"); //удаляем старую запись
	m1.insert(p1); //вставляем новую
	printMap(m1);
	stop
	
	
	//д) Сформируйте любым способом вектор с элементами типа string.
	//Создайте (и распечатайте для проверки) map<string, int>, который будет
	//содержать упорядоченные по алфавиту строки и
	//количество повторений каждой строки в векторе
	
	vector<string> v2 = {"Java", "C++", "C#", "SQL", "C#", "C#","C++", "C#","Python", "Java"};
	
	//заготовим итераторы
	vector<string>::const_iterator itc1 = v2.cbegin();
	vector<string>::const_iterator itce = v2.cend();

	map<string, int> m2;

	while (itc1!=itce)
	{
		
		m2[*itc1]++;
		++itc1;
	}
	
	printMap(m2);
	stop
	
	

	//е) 
	//задан массив:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//создайте map, в котором каждой букве будет соответствовать совокупность 
	//лексиграфически упорядоченных слов, начинающихся с этой буквы.
	//Подсказка: не стоит хранить дубли одной и той же строки
	
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	//...

	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty", "Alfa", "Abba", "C++" , "C#", "C++", "Digit", "Data", "Count" };

	char ch = 'A'; //ключ 

	map<char, set<const char*, StringLess>> m3; //создаем пустой mapб который будем набивать значениями
	
	while (ch!='[')
	{
		//set<const char*, StringLess> tmp;  //set значений
		for (size_t i = 0; i < (sizeof(words) / sizeof(words[0])); i++) //бежим по массиву
		{
			if (words[i][0] == ch) //если нашли подходящую строку
			{
				m3[ch].insert(words[i]);
			}
		}
		ch++;
	}
	stop
	
	stop

	//ж)
	//создайте структуру данных, которая будет хранить информацию о студенческих группах.
	//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
	//фамилии могут дублироваться
	//Сами группы тоже должны быть упорядочены по номеру
	//
	//номера 


	map<size_t, multiset<string>> m4;

	multiset<string> mlt1 = { "Ivanov", "Petrov", "Sidorov", "Petrov"}; //список фамилий группы
	m4[3552] = mlt1; //номер группы 3552
	m4[3551] = mlt1; //номер группы 3551

	//и т.д.
	stop

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	multimap<string, pair<string,string>> mmp1; //а		pair<string, pair<string,string>>
	mmp1.insert(pair<string, pair<string, string>>("strange", pair<string,string>("чужой", "странный"))); //б
   	mmp1.insert(pair<string, pair<string, string>>("statement", pair<string,string>("высказывание", "утверждение")));
	mmp1.insert(pair<string, pair<string, string>>("operator", pair<string,string>("оператор", "рабочий")));
	mmp1.insert(pair<string, pair<string, string>>("switch", pair<string,string>("включать", "переключать")));
	mmp1.insert(pair<string, pair<string, string>>("compile", pair<string,string>("составлять", "компилировать")));
	mmp1.insert(pair<string, pair<string, string>>("strange", pair<string,string>("незнакомый", "чудной")));
	stop
	printMultiMap(mmp1); //в
	stop
	printMultiMapKey(mmp1, "strange"); //г

  stop

	return 0;
}

