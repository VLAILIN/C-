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

