#include "List.h"

List::Node::Node() //конструктор
{
	pPrev = pNext = nullptr;
	m_data = nullptr;
}

List::Node::Node(Node*p, const Shape* pS) //конструктор - вставка узла в список
{
	//ставим указатели
	pPrev = p;
	pNext = p->pNext;
	p->pNext = this;
	this->pNext->pPrev = this;

	//инициализация m_data
	if (pS)
	{
		//через виртуальный метод класса
		m_data = pS->GetCopy();
	}
	else m_data = nullptr;
}

List::Node::~Node() //деструктор - изъятие из списка
{
	if(pNext) pNext->pPrev = pPrev;
	if(pPrev) pPrev->pNext = pNext;
	pPrev = nullptr;
	pNext = nullptr;	
	
	delete m_data;
	m_data = nullptr;
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

List& List::operator=(const List& other) //оператор присваивания оптимизированный
{
	if (this!=&other)
	{
	
		if (other.m_size)
		{
			Node* pCur = Head.pNext; //указатель на первый элемент нашего списка
			Node* pCurOther = other.Head.pNext; //указатель на первый элемент принимаемого списка

			while (pCurOther != &other.Tail) //бежим по принимаемому списку
			{
				if (pCur != &Tail) //если не дошли жо нашего хвоста
				{
					//pCur->m_data = pCurOther->m_data; //копируем данные
					if (typeid(*pCur->m_data) == typeid(*pCurOther->m_data))
					{
						*pCur->m_data = *pCurOther->m_data;
					}
					else
					{
						delete pCur->m_data;
						pCur->m_data = nullptr;
						if (pCurOther->m_data) pCur->m_data = pCurOther->m_data->GetCopy();
					}
					pCur = pCur->pNext;
				}
				else 
				{
					AddToTail(pCurOther->m_data); //иначе добавляем в хвост новый элемент
				}
				pCurOther = pCurOther->pNext;
			}

			//можно реализовать через for и удаление нода перед хвостом
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
void List::AddToHead(const Shape* pS) //добавление в голову списка
{
	new Node(&Head, pS);
	m_size++;
}

void List::AddToTail(const Shape* pS) //добавление в голову списка
{
	new Node(Tail.pPrev, pS);
	m_size++;
}

bool List::Remove(const Shape* pS)
{
	Node* pCur = Head.pNext; //указываем на 1ый элемент списка
	while (pCur != &Tail) //бежим по списку
	{
		if (pCur->m_data->operator==(pS))
		{
			delete pCur;
			m_size--;
			return true;
		}
		pCur = pCur->pNext;
	}
	return false;
}
	

unsigned int List::RemoveMany(const Shape* pS)
{
	unsigned int count = 0; //счетчик
	Node* tmp = nullptr;

	Node* pCur = Head.pNext; //указываем на 1ый элемент списка
	while (pCur != &Tail) //бежим по списку
	{
		Node* n = pCur->pNext;
		if (pCur->m_data->operator==(pS)) //если нашли совпадение 
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
			int buf_x = 10, buf_y = 10, buf_x1 = 10, buf_y1 = 10;
			char buf_c = 0;
			int buf_col = 0;
			float buf_radius = 0;

			//fin.ignore(100,'=');
	
			while (fin >> buf_c) //анализируем признак , Rect или Circle
		//	while (!fin.eof())
			{
				if (buf_c == 'c') //если Circle
				{
					fin >> buf_col>> buf_x >> buf_y >> buf_radius;
					Circle c1(buf_x, buf_y, buf_radius, static_cast<COLORS>(buf_col));
					AddToTail(c1.GetCopy());
				}
				else if (buf_c == 'r') //если Rect
				{
					fin >> buf_col >> buf_x >> buf_y >> buf_x1 >> buf_y1;
					Rect r1(buf_x, buf_y, buf_x1, buf_y1, static_cast<COLORS>(buf_col));
					AddToTail(r1.GetCopy());
				}

			}
		}
		fin.close();
	}
	else cout << "Wrong file name!" << endl;
}

void List::SortSquare(SORT priznak) //сортировка по площади
{
	if (m_size == 0)
	{
		cout << "Double List is empty!" << endl;
		return;
	}

	if (m_size == 1) return;

	//выбираем функцию сравнения сортировки
	bool (List::*pf) (const Shape*, const Shape*) = nullptr;
	switch (priznak)
	{
	case COLOR:
		pf = &List::CmpNodeColor;
		break;
	case DISTANCE:
		pf = &List::CmpNodeDistance;
		break;
	case SQUARE:
	default:
		pf = &List::CmpNodeSquare;
	}

	//сортировка
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
			//if (pFind->m_data->GetSquare()<pMin->m_data->GetSquare()) //если площадь меньше
			if ((this->*pf)(pFind->m_data, pMin->m_data))
			{
				pMin = pFind;
			}
			pFind = pFind->pNext;
		}

		if (pCur!=pMin) //если нашли меньшее значение
		{
			//Меняем указатели на data
			Shape* tmp = pCur->m_data;

			pCur->m_data = pMin->m_data;
			pMin->m_data = tmp;

			tmp = nullptr;
		}
		pCur = pCur->pNext; //идем дальше
	}
}

ostream& operator<< (ostream& os, const List::Node& d)
{
	if (d.m_data)
	{
		d.m_data->PrintData(os);
	}
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

bool List::CmpNodeSquare(const Shape* pS1, const Shape* pS2)
{
	return pS1->GetSquare() < pS2->GetSquare();
}

bool List::CmpNodeColor(const Shape* pS1, const Shape* pS2)
{
	return pS1->getColor() < pS2->getColor();
}

bool List::CmpNodeDistance(const Shape* pS1, const Shape* pS2)
{
	return pS1->getDistance() < pS2->getDistance();
}
