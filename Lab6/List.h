#pragma once
#include "Circle.h"
#include "Rect.h"
#include <fstream>
using namespace std;
enum SORT {SQUARE, COLOR, DISTANCE};
class List
{
private:
	class Node //вспомогательный класс 
	{
	private:
		Shape* m_data; //указатель на базовый тип Shape
		Node* pPrev; //указатель на предыдущий элемент
		Node* pNext; //указатель на следующий элемент
		Node(); //конструктор 
		Node(Node*p, const Shape* pS); //конструктор добавление в список 
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
	void AddToHead(const Shape* pS); //добавление в голову
	void AddToTail(const Shape* pS); //добавление в хвост
	List(const List& other); //конструктор копирования
	List& operator=(const List& other); //оператор присваивания
	List(List&& other); //move конструктор копирования
	List& operator=(List&& other); //move оператор присваивания
	void MakeEmpty(); //очистка списка
	bool Remove(const Shape* pS); //удаление одного узла
	unsigned int RemoveMany(const Shape* pS); //удаление нескольких узлов
	void WriteToFile(const char* k); //запись в файл
	void ReadFromFile(const char* k); //чтение из файла
	void SortSquare(SORT); //сортировка по площади


	
	bool CmpNodeSquare(const Shape* pS1, const Shape* pS2) ; //сравнение элементов по площадям
	bool CmpNodeColor(const Shape* pS1, const Shape* pS2); //сравнение элементов по цвету
	bool CmpNodeDistance(const Shape* pS1, const Shape* pS2); //сравнение элементов по удаленности

	friend ostream& operator<<(ostream& os, const Node& d);
	friend ostream& operator<<(ostream& os, const List& d); //оператор <<

};	
