#pragma once
#include <iostream>
class Bin
{
 unsigned char m_bin0 : 1;//��� bool
 unsigned char m_bin1 : 1;
 unsigned char m_bin2 : 1;
 unsigned char m_bin3 : 1;
 unsigned char m_bin4 : 1;
 unsigned char m_bin5 : 1;
 unsigned char m_bin6 : 1;
 unsigned char m_bin7 : 1;
 void Show();//������� ��� �������� �����
 void/*int*/ ShowPos(int pos);//������� ����� � �������
 void/*int*/ Edit(int pos, int val); //�������� ����� � �������
 friend union Bytes;
//��� ���������� ������� ��������� ������������ ���������� ����������
//����������� ��������� ����� (std::cout)
};