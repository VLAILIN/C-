#pragma once
#include <iostream>
class Hex
{
unsigned char m_hex0 : 4;
unsigned char m_hex1 : 4;

void Show(); //������� ��� ����������������� �����
void/*int*/ ShowPos(int pos);//������� ����� � �������
void/*int*/ Edit(int pos, int val);//�������� ����� � �������
friend union Bytes;
};