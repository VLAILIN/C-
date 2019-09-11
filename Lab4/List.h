#pragma once
#include "Circle.h"
#include <fstream>
using namespace std;

class List
{
private:
	class Node //��������������� ����� 
	{
	private:
		Circle m_data; //����������
		Node* pPrev; //��������� �� ���������� �������
		Node* pNext; //��������� �� ��������� �������
		Node(); //����������� 
		Node(Node*p, const Circle& d); //����������� ���������� � ������ 
		~Node(); //����������
		
		friend ostream& operator<<(ostream& os, const Node& d);		
		friend ostream& operator<<(ostream& os, const List& d);

		friend class List;
	};
	Node Head;  // ��������� �������, ������� �������� ��������� ������ ������
	Node Tail; // ��������� �������, ������� �������� ��������� ����� ������
	size_t m_size; //���������� ��������� � ������
public:
	List(); //�����������
	~List(); //����������
	void AddToHead(const Circle& c); //���������� � ������
	void AddToTail(const Circle& c); //���������� � �����
	List(const List& other); //����������� �����������
	List& operator=(const List& other); //�������� ������������
	List(List&& other); //move ����������� �����������
	List& operator=(List&& other); //move �������� ������������
	void MakeEmpty(); //������� ������
	bool Remove(const Circle& c); //�������� ������ ����
	unsigned int RemoveMany(const Circle& c); //�������� ���������� �����
	void WriteToFile(const char* k); //������ � ����
	void ReadFromFile(const char* k); //������ �� �����
	void SortSquare(); //���������� �� �������

	bool CmpNodeSquare (const Node& d1, const Node& d2) const; //��������� ��������� �� ��������

	friend ostream& operator<<(ostream& os, const Node& d);
	friend ostream& operator<<(ostream& os, const List& d); //�������� <<

};	
