#include "List.h"


List::Node::Node():m_data(0, 0, 0) //конструктор
{
	pPrev = pNext = nullptr;
}

List::Node::Node(Node*p, const Circle& d):m_data(d) //конструктор - вставка узла в список
{
	pPrev = p;
	pNext = p->pNext;
	p->pNext = this;
	this->pNext->pPrev = this;
}

List::Node::~Node() //деструктор - изъятие из списка
{
	if(pNext) pNext->pPrev = pPrev;
	if(pPrev) pPrev->pNext = pNext;
	pPrev = nullptr;
	pNext = nullptr;	
}

List::List():m_size(0) //конструктор списка
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List() //деструктор списка
{
	MakeEmpty();
}

List::List(const List& other) //конструктор копирования
{
	//связываем голову и хвост
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	m_size = 0; //размер ноль, при добавлении будет увеличиваться

	if (other.m_size) //если полученный список не пустой
	{
		Node* pCur = other.Head.pNext; //указываем на 1ый элемент списка
		while (pCur!=&other.Tail) //бежим по списку
		{
			AddToTail(pCur->m_data); //добавляем элемент
			pCur = pCur->pNext;
			
		}	
	}
}

List::List(List&& other) //move конструктор копирования
{
	//меняем указатели
	if (other.m_size)
	{
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		other.Head.pNext->pPrev = &Head;
		other.Tail.pPrev->pNext = &Tail;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;

		m_size = other.m_size; //перетягиваем размер
		other.m_size = 0;
	}
	else
	{
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
		m_size = 0;
	}
}

List& List::operator=(const List& other) //оператор присваивания
{
	if (this!=&other)
	{
		//MakeEmpty(); //очищаем список
		//if (other.m_size) //если полученный список не пустой
		//{
		//	Node* pCur = other.Head.pNext; //указываем на 1ый элемент списка
		//	while (pCur!=&other.Tail) //бежим по списку
		//	{
		//		AddToTail(pCur->m_data); //добавляем элемент в хвост
		//		pCur = pCur->pNext;			
		//	}	
		//}
	
		if (other.m_size)
		{
			Node* pCur = Head.pNext; //указатель на первый элемент нашего списка
			Node* pCurOther = other.Head.pNext; //указатель на первый элемент принимаемого списка

			while (pCurOther != &other.Tail) //бежим по принимаемому списку
			{
				if (pCur != &Tail) //если не дошли жо нашего хвоста
				{
					pCur->m_data = pCurOther->m_data; //копируем данные
					pCur = pCur->pNext;
				}
				else 
				{
					AddToTail(pCurOther->m_data); //иначе добавляем в хвост новый элемент
				}
				pCurOther = pCurOther->pNext;
			}

			if (pCur != &Tail) //если в нашем списке остались элементы их надо удалить
			{
				Node* tmp = nullptr;
				while (pCur != &Tail) //идем от элемента до хвоста
				{
					tmp = pCur->pNext;
					delete pCur;
					pCur = tmp;
				}
			}
		}
		else MakeEmpty();
		m_size = other.m_size;
	}
	return *this;
}

List& List::operator=(List&& other) //move оператор присваивания
{
	if (this!=&other)
	{
		MakeEmpty(); //очищаем список
		
		if (other.m_size)
		{
			Head.pNext = other.Head.pNext;
			Tail.pPrev = other.Tail.pPrev;
			other.Head.pNext->pPrev = &Head;
			other.Tail.pPrev->pNext = &Tail;

			other.Head.pNext = &other.Tail;
			other.Tail.pPrev = &other.Head;

			m_size = other.m_size;
			other.m_size = 0;
		}
	}
	return *this;
}

void List::MakeEmpty() //очистка списка
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
	m_size=0;
}
void List::AddToHead(const Circle& c) //добавление в голову списка
{
	new Node(&Head, c);
	m_size++;
}

void List::AddToTail(const Circle& c) //добавление в голову списка
{
	new Node(Tail.pPrev, c);
	m_size++;
}

bool List::Remove(const Circle& c)
{
	Node* pCur = Head.pNext; //указываем на 1ый элемент списка
	while (pCur != &Tail) //бежим по списку
	{
		if (pCur->m_data == c)
		{
			delete pCur;
			m_size--;
			return true;
		}
		pCur = pCur->pNext;
	}
	return false;
}
	
//unsigned int List::RemoveMany(const Circle& c)
//{
//	unsigned int count=0; //счетчик
//	Node* tmp = nullptr; 
//
//	Node* pCur = Head.pNext; //указываем на 1ый элемент списка
//	while (pCur!=&Tail) //бежим по списку
//	{
//		if (pCur->m_data==c) //если нашли совпадение окружностей
//		{
//			tmp = pCur->pNext; //сохраняем указатель на следующий элемент списка
//			delete pCur; //освобождаем память
//			m_size--; //уменьшаем размер списка
//			count++; //увеличиваем счетчик удаленных элементов
//			pCur = tmp; //переходим на следующий элемент
//		}
//		else pCur = pCur->pNext; // иначе переходим на следующий элемент
//	}
//	return count;
//}
unsigned int List::RemoveMany(const Circle& c)
{
	unsigned int count = 0; //счетчик
	Node* tmp = nullptr;

	Node* pCur = Head.pNext; //указываем на 1ый элемент списка
	while (pCur != &Tail) //бежим по списку
	{
		Node* n = pCur->pNext;
		if (pCur->m_data == c) //если нашли совпадение окружностей
		{			
			delete pCur; //освобождаем память
			count++; //увеличиваем счетчик удаленных элементов
		}
		pCur = n; // иначе переходим на следующий элемент
	}
	m_size-=count; //уменьшаем размер списка
	return count;
}
void List::WriteToFile(const char* k) //запись в файл
{
	if (k)
	{
		ofstream fout;
		fout.open(k); // связываем объект с файлом
		if (fout.is_open())
		{
			fout << *this;
		}
		fout.close(); // закрываем файл
	}
	else cout << "Wrong file name!" << endl;
}

void List::ReadFromFile(const char* k) //чтение из файла
{
	if (k)
	{
		ifstream fin; // окрываем файл для чтения
		fin.open(k);
		if (fin.is_open())
		{
			int buf_x = 10, buf_y = 10;
			float buf_radius = 0;

			//fin.ignore(100,'=');
			while (fin  >> buf_x  >> buf_y >> buf_radius)
		//	while (!fin.eof())
			{
				//fin >> buf_x >> buf_y >> buf_radius;
				Circle c1(buf_x, buf_y, buf_radius);
				AddToTail(c1);
			}
		}
		fin.close();
	}
	else cout << "Wrong file name!" << endl;
}

void List::SortSquare() //сортировка по площади
{
	if (m_size == 0)
	{
		cout << "Double List is empty!" << endl;
		return;
	}

	if (m_size == 1) return;

	//if (m_size) //если список не пустой
	//{
	Node* pCur = Head.pNext;
	Node* pFind = nullptr; //указатель для поиска минимального значения
	Node* pMin = nullptr; //указатель на минимиальный узел

	while (pCur != Tail.pPrev)  // Tail.pPrev, так как последний автоматически окажется на своем месте
	{
		//Поиск минимального из оставшихся значений
		pMin = pCur; //здесь будет элемент списка с минимальным значением
		pFind = pCur->pNext;
		
		while (pFind != &Tail) //ищем минимальное значение
		{
			//if (CmpNodeSquare(*pFind, *pMin))
			if (pFind->m_data.CmpNodeSquare(pMin->m_data)) //если площадь меньше
			{
				pMin = pFind;
			}
			pFind = pFind->pNext;
		}

		if (pCur!=pMin) //если нашли меньшее значение
		{
			//Меняем связи между элементами списка


			//связываем соседей pMin

			pMin->pPrev->pNext = pMin->pNext;
			pMin->pNext->pPrev = pMin->pPrev;

			//ставим pMin в новое место

			pMin->pNext = pCur;
			pMin->pPrev = pCur->pPrev;

			pCur->pPrev->pNext = pMin;
			pCur->pPrev = pMin;
			

			////сохраняем соседей pCur;
			//Node* tmpPrev = pCur->pPrev;
			//Node* tmpNext = pCur->pNext;

			////меняем связи pCur
			//pCur->pNext = pMin->pNext;

			//if (tmpNext != pMin)
			//{
			//	pCur->pPrev = pMin->pPrev;
			//}
			//else pCur->pPrev = pMin;

			//if (pMin->pPrev!=pCur) pMin->pPrev->pNext = pCur;
			//pMin->pNext->pPrev = pCur;

			////меняем связи pMin		
			//if (pMin->pPrev!= pCur)
			//{
			//	pMin->pNext = tmpNext;
			//}
			//else pMin->pNext = pCur;
			//pMin->pPrev = tmpPrev;

			//tmpPrev->pNext = pMin;
			//if (tmpNext!=pMin) tmpNext->pPrev = pMin;

			pCur = pMin; //переходим на исходную позицию
		}

		pCur = pCur->pNext; //идем дальше
	}
	//}
	//else cout<< "Double List is empty!" << "\n";
}

bool List::CmpNodeSquare(const Node& d1, const Node& d2) const
{
	double sq1 = 3.14*d1.m_data.GetRadius()*d1.m_data.GetRadius();
	double sq2 = 3.14*d2.m_data.GetRadius()*d2.m_data.GetRadius();
 
	if(sq1<sq2) return true;
	else return false;
}

ostream& operator<< (ostream& os, const List::Node& d)
{
	//os << "radius: "<<d.m_data.radius<< "  square: "<<3,14*d.m_data.radius*d.m_data.radius<<"\n";
	os << d.m_data; // << "\n";
	return os;
}

ostream& operator<<(ostream& os, const List& d)
{
	if (d.m_size)
	{
		List::Node* pCur = d.Head.pNext;
		while (pCur != &d.Tail)
		{
			os << *pCur; // << "\n";
			pCur = pCur->pNext;
		}
		return os;
	}
	else os << "Double List is empty!" << "\n";
}

