#pragma once
#include <iostream>
class Oct
{
unsigned char m_oct0 : 3;
unsigned char m_oct1 : 3;
unsigned char m_oct2 : 2;
void Show();//выводим все восьмеричные цифры
void/*int*/ ShowPos(int pos);//выводим цифру в позиции
void/*int*/ Edit(int pos, int val);//изменяем цифру в позиции
friend union Bytes;
};