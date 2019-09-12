/*
Задание: требуется реализовать класс MyString таким образом, чтобы все строки хранились в единственном экземпляре. 
Это можно сделать посредством односвязного списка.
Вспомогательный класс Counter является "оберткой" для строки и содержит вспомогательные данные, 
которые в частности позволят избежать дублирования данных.
Для того, чтобы обеспечить хранение строки в единственном экземпляре, в классе Counter должен храниться в единственном экземпляре 
перечень всех вспомогательных оберток, 
(таким образом, в любой момент выполнения программы можно получить перечень всех используемых строк). 
Введем статические данные:
static Counter* Head;
А также счетчик указателей:
static unsigned int m_curCounters;
Следует предусмотреть определение и инициализацию статических данных.
Основной класс MyString содержит единственное данное – указатель на "свой" Counter – Counter* m_pMyCounter.
Введите необходимые на Ваш взгляд методы («джентльменский набор» для сложного класса). 
*/

#include <tchar.h>
#include "myString.h"
#define	  stop __asm nop

size_t Counter::m_curCounters;
Counter* Counter::pHead = nullptr;

int _tmain(int argc, _TCHAR* argv[])
{
	{
		MyString s1("ABC");
		MyString s2("ABC");
		MyString s3 = s2;
		MyString s4(s1);

		MyString s5("ZzYyXx");
		MyString s6("C++");
		MyString s7("ClaSs");
		MyString s8("QwertY");
		stop

		MyString::printAll(); //печать всех строк
		stop
		MyString::ChangeRegister();
		MyString::printAll();
		stop
		MyString::printSort();
		stop
	}
	return 0;
}//endmain

