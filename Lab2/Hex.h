#pragma once
#include <iostream>
class Hex
{
unsigned char m_hex0 : 4;
unsigned char m_hex1 : 4;

void Show(); //выводим все шестнадцатеричные цифры
void/*int*/ ShowPos(int pos);//выводим цифру в позиции
void/*int*/ Edit(int pos, int val);//изменяем цифру в позиции
friend union Bytes;
};