#include "List.h"


List::Node::Node():m_data(0, 0, 0) //�����������
{
	pPrev = pNext = nullptr;
}

List::Node::Node(Node*p, const Circle& d):m_data(d) //����������� - ������� ���� � ������
{
	pPrev = p;
	pNext = p->pNext;
	p->pNext = this;
	this->pNext->pPrev = this;
}

List::Node::~Node() //���������� - ������� �� ������
{
	if(pNext) pNext->pPrev = pPrev;
	if(pPrev) pPrev->pNext = pNext;
	pPrev = nullptr;
	pNext = nullptr;	
}

List::List():m_size(0) //����������� ������
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List() //���������� ������
{
	MakeEmpty();
}

List::List(const List& other) //����������� �����������
{
	//��������� ������ � �����
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	m_size = 0; //������ ����, ��� ���������� ����� �������������

	if (other.m_size) //���� ���������� ������ �� ������
	{
		Node* pCur = other.Head.pNext; //��������� �� 1�� ������� ������
		while (pCur!=&other.Tail) //����� �� ������
		{
			AddToTail(pCur->m_data); //��������� �������
			pCur = pCur->pNext;
			
		}	
	}
}

List::List(List&& other) //move ����������� �����������
{
	//������ ���������
	if (other.m_size)
	{
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		other.Head.pNext->pPrev = &Head;
		other.Tail.pPrev->pNext = &Tail;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;

		m_size = other.m_size; //������������ ������
		other.m_size = 0;
	}
	else
	{
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
		m_size = 0;
	}
}

List& List::operator=(const List& other) //�������� ������������
{
	if (this!=&other)
	{
		//MakeEmpty(); //������� ������
		//if (other.m_size) //���� ���������� ������ �� ������
		//{
		//	Node* pCur = other.Head.pNext; //��������� �� 1�� ������� ������
		//	while (pCur!=&other.Tail) //����� �� ������
		//	{
		//		AddToTail(pCur->m_data); //��������� ������� � �����
		//		pCur = pCur->pNext;			
		//	}	
		//}
	
		if (other.m_size)
		{
			Node* pCur = Head.pNext; //��������� �� ������ ������� ������ ������
			Node* pCurOther = other.Head.pNext; //��������� �� ������ ������� ������������ ������

			while (pCurOther != &other.Tail) //����� �� ������������ ������
			{
				if (pCur != &Tail) //���� �� ����� �� ������ ������
				{
					pCur->m_data = pCurOther->m_data; //�������� ������
					pCur = pCur->pNext;
				}
				else 
				{
					AddToTail(pCurOther->m_data); //����� ��������� � ����� ����� �������
				}
				pCurOther = pCurOther->pNext;
			}

			if (pCur != &Tail) //���� � ����� ������ �������� �������� �� ���� �������
			{
				Node* tmp = nullptr;
				while (pCur != &Tail) //���� �� �������� �� ������
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

List& List::operator=(List&& other) //move �������� ������������
{
	if (this!=&other)
	{
		MakeEmpty(); //������� ������
		
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

void List::MakeEmpty() //������� ������
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
	m_size=0;
}
void List::AddToHead(const Circle& c) //���������� � ������ ������
{
	new Node(&Head, c);
	m_size++;
}

void List::AddToTail(const Circle& c) //���������� � ������ ������
{
	new Node(Tail.pPrev, c);
	m_size++;
}

bool List::Remove(const Circle& c)
{
	Node* pCur = Head.pNext; //��������� �� 1�� ������� ������
	while (pCur != &Tail) //����� �� ������
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
//	unsigned int count=0; //�������
//	Node* tmp = nullptr; 
//
//	Node* pCur = Head.pNext; //��������� �� 1�� ������� ������
//	while (pCur!=&Tail) //����� �� ������
//	{
//		if (pCur->m_data==c) //���� ����� ���������� �����������
//		{
//			tmp = pCur->pNext; //��������� ��������� �� ��������� ������� ������
//			delete pCur; //����������� ������
//			m_size--; //��������� ������ ������
//			count++; //����������� ������� ��������� ���������
//			pCur = tmp; //��������� �� ��������� �������
//		}
//		else pCur = pCur->pNext; // ����� ��������� �� ��������� �������
//	}
//	return count;
//}
unsigned int List::RemoveMany(const Circle& c)
{
	unsigned int count = 0; //�������
	Node* tmp = nullptr;

	Node* pCur = Head.pNext; //��������� �� 1�� ������� ������
	while (pCur != &Tail) //����� �� ������
	{
		Node* n = pCur->pNext;
		if (pCur->m_data == c) //���� ����� ���������� �����������
		{			
			delete pCur; //����������� ������
			count++; //����������� ������� ��������� ���������
		}
		pCur = n; // ����� ��������� �� ��������� �������
	}
	m_size-=count; //��������� ������ ������
	return count;
}
void List::WriteToFile(const char* k) //������ � ����
{
	if (k)
	{
		ofstream fout;
		fout.open(k); // ��������� ������ � ������
		if (fout.is_open())
		{
			fout << *this;
		}
		fout.close(); // ��������� ����
	}
	else cout << "Wrong file name!" << endl;
}

void List::ReadFromFile(const char* k) //������ �� �����
{
	if (k)
	{
		ifstream fin; // �������� ���� ��� ������
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

void List::SortSquare() //���������� �� �������
{
	if (m_size == 0)
	{
		cout << "Double List is empty!" << endl;
		return;
	}

	if (m_size == 1) return;

	//if (m_size) //���� ������ �� ������
	//{
	Node* pCur = Head.pNext;
	Node* pFind = nullptr; //��������� ��� ������ ������������ ��������
	Node* pMin = nullptr; //��������� �� ������������ ����

	while (pCur != Tail.pPrev)  // Tail.pPrev, ��� ��� ��������� ������������� �������� �� ����� �����
	{
		//����� ������������ �� ���������� ��������
		pMin = pCur; //����� ����� ������� ������ � ����������� ���������
		pFind = pCur->pNext;
		
		while (pFind != &Tail) //���� ����������� ��������
		{
			//if (CmpNodeSquare(*pFind, *pMin))
			if (pFind->m_data.CmpNodeSquare(pMin->m_data)) //���� ������� ������
			{
				pMin = pFind;
			}
			pFind = pFind->pNext;
		}

		if (pCur!=pMin) //���� ����� ������� ��������
		{
			//������ ����� ����� ���������� ������


			//��������� ������� pMin

			pMin->pPrev->pNext = pMin->pNext;
			pMin->pNext->pPrev = pMin->pPrev;

			//������ pMin � ����� �����

			pMin->pNext = pCur;
			pMin->pPrev = pCur->pPrev;

			pCur->pPrev->pNext = pMin;
			pCur->pPrev = pMin;
			

			////��������� ������� pCur;
			//Node* tmpPrev = pCur->pPrev;
			//Node* tmpNext = pCur->pNext;

			////������ ����� pCur
			//pCur->pNext = pMin->pNext;

			//if (tmpNext != pMin)
			//{
			//	pCur->pPrev = pMin->pPrev;
			//}
			//else pCur->pPrev = pMin;

			//if (pMin->pPrev!=pCur) pMin->pPrev->pNext = pCur;
			//pMin->pNext->pPrev = pCur;

			////������ ����� pMin		
			//if (pMin->pPrev!= pCur)
			//{
			//	pMin->pNext = tmpNext;
			//}
			//else pMin->pNext = pCur;
			//pMin->pPrev = tmpPrev;

			//tmpPrev->pNext = pMin;
			//if (tmpNext!=pMin) tmpNext->pPrev = pMin;

			pCur = pMin; //��������� �� �������� �������
		}

		pCur = pCur->pNext; //���� ������
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

