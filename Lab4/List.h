#pragma once
#include "Circle.h"
#include <fstream>
using namespace std;

class List
{
private:
	class Node //вспомогательный класс 
	{
	private:
		Circle m_data; //окружность
		Node* pPrev; //указатель на предыдущий элемент
		Node* pNext; //указатель на следующий элемент
		Node(); //конструктор 
		Node(Node*p, const Circle& d); //конструктор добавление в список 
		~Node(); //деструктор
		
		friend ostream& operator<<(ostream& os, const Node& d);		
		friend ostream& operator<<(ostream& os, const List& d);

		friend class List;
	};
	Node Head;  // фиктивный элемент, который является признаком начала списка
	Node Tail; // фиктивный элемент, который является признаком конца списка
	size_t m_size; //количество элементов в списке
public:
	List(); //конструктор
	~List(); //деструктор
	void AddToHead(const Circle& c); //добавление в голову
	void AddToTail(const Circle& c); //добавление в хвост
	List(const List& other); //конструктор копирования
	List& operator=(const List& other); //оператор присваивания
	List(List&& other); //move конструктор копирования
	List& operator=(List&& other); //move оператор присваивания
	void MakeEmpty(); //очистка списка
	bool Remove(const Circle& c); //удаление одного узла
	unsigned int RemoveMany(const Circle& c); //удаление нескольких узлов
	void WriteToFile(const char* k); //запись в файл
	void ReadFromFile(const char* k); //чтение из файла
	void SortSquare(); //сортировка по площади

	bool CmpNodeSquare (const Node& d1, const Node& d2) const; //сравнение элементов по площадям

	friend ostream& operator<<(ostream& os, const Node& d);
	friend ostream& operator<<(ostream& os, const List& d); //оператор <<

};	
