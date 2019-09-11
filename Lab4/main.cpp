#include <tchar.h>
#include "List.h"
#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{

	Circle c1(0, 0, 5);
	Circle c2(1, 1, 10);
	Circle c3(2, 2, 15);
	Circle c4(3, 3, 20);
	Circle c5(4, 4, 15);
	Circle c6(5, 5, 30);
	Circle c7(6, 6, 50);
	Circle c8(7, 7, 90);
	Circle c9(8, 8, 1);

	//cout << c3;
	stop

	List dl;
	dl.AddToHead(c3);
	dl.AddToHead(c2);
	dl.AddToHead(c1);
	dl.AddToTail(c4);
	dl.AddToTail(c5);
	dl.AddToTail(c6);

	cout << dl << endl;
	stop

	dl.Remove(c1);
	cout << dl << endl;
	stop

	dl.RemoveMany(c5);
	//dl.MakeEmpty();
	cout << dl << endl;
	stop

	dl.WriteToFile("laba4.txt");
	dl.ReadFromFile("laba4.txt");
	cout << dl << endl;

	dl.AddToHead(c8);
	dl.AddToHead(c7);
	dl.AddToTail(c9);
	cout << dl << endl;

	dl.SortSquare();
	cout << dl << endl;

	stop
	return 0;
}//endmain

