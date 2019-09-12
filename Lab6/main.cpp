#include <tchar.h>
#include "List.h"


#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{

	Shape* pc1 = new Circle(5, 5, 5, GREEN);
	Shape* pc2 = new Circle(15, 15, 15, BLACK);
	Shape* pc3 = new Circle(25, 25, 25, BLUE);
	stop

	Shape* pr1 = new Rect(10, 20, 20, 10, RED);
	Shape* pr2 = new Rect(20, 40, 40, 20, YELLOW);
	Shape* pr3 = new Rect(30, 40, 40, 30, WHITE);
	stop

	Shape* pc4 = pc1->GetCopy();
	Shape* pc5 = pc3->GetCopy();
	stop

	Shape* pr4 = pr1->GetCopy();
	Shape* pr5 = pr3->GetCopy();
	stop

	bool b1 = typeid(*pc1) == typeid(*pc5);
	bool b2 = typeid(*pc2) == typeid(*pc4);
	stop

	bool b3 = typeid(*pr1) == typeid(*pr5);
	bool b4 = typeid(*pr2) == typeid(*pr4);
	stop

	bool b5 = typeid(*pc4) == typeid(*pr5);
	bool b6 = typeid(*pc1) == typeid(*pr2);
	stop

	bool b7 = pc4->operator==(pc1);
	bool b8 = pc4->operator==(pc3);
	bool b9 = pc3->operator==(pr2);
	bool b10 = pr1->operator==(pr4);
	bool b11 = pr1->operator==(pr3);
	bool b12 = pr2->operator==(pc2);

	stop
		//cout << c3;
	stop

	List dl;
	dl.AddToHead(pc1);
	dl.AddToHead(pr3);
	dl.AddToHead(pr2);
	dl.AddToTail(pc3);
	dl.AddToTail(pr1);
	dl.AddToTail(pc2);
	dl.AddToTail(pc4);

	cout << dl << endl;
	stop

	dl.Remove(pr3);
	cout << dl << endl;
	stop

	dl.RemoveMany(pc1);
	//dl.MakeEmpty();
	cout << dl << endl;
	stop

	dl.WriteToFile("laba6.txt");
	dl.ReadFromFile("laba6.txt");
	stop
	cout << dl << endl;
	stop

	/*dl.AddToHead(c8);
	dl.AddToHead(c7);
	dl.AddToTail(c9);
	cout << dl << endl;*/

	dl.SortSquare(SQUARE);
	cout << dl << endl;

	dl.SortSquare(COLOR);
	cout << dl << endl;

	dl.SortSquare(DISTANCE);
	cout << dl << endl;

	delete pc1;
	delete pc2;
	delete pc3;
	delete pc4;
	delete pc5;

	delete pr1;
	delete pr2;
	delete pr3;
	delete pr4;
	delete pr5;

	stop
	return 0;
}//endmain

