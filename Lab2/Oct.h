#pragma once
#include <iostream>
class Oct
{
unsigned char m_oct0 : 3;
unsigned char m_oct1 : 3;
unsigned char m_oct2 : 2;
void Show();//������� ��� ������������ �����
void/*int*/ ShowPos(int pos);//������� ����� � �������
void/*int*/ Edit(int pos, int val);//�������� ����� � �������
friend union Bytes;
};