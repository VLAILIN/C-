#include "Oct.h"
using namespace std;

void Oct::Show()
{
	//cout.flags(ios::oct | ios::showbase);
	cout << oct << static_cast<int>(m_oct2) << static_cast<int>(m_oct1) << static_cast<int>(m_oct0) << endl;
}

void Oct::ShowPos(int pos)
{
	switch (pos)
	{
	case 0:
		cout << oct << static_cast<int>(m_oct0) << endl;
		break;
	case 1:
		cout << oct << static_cast<int>(m_oct1) << endl;
		break;
	case 2:
		cout << oct << static_cast<int>(m_oct2) << endl;
		break;
	default:
		cout << "Wrong position!" << endl;
	}

}

void Oct::Edit(int pos, int val)
{

	if ((val < 0) || (val > 7))
	{
		cout << "Wrong value!" << endl;
		return;
	}

	if ((pos == 2) && (val > 3))
	{
		cout << "Wrong value!" << endl;
		return;
	}

	switch (pos)
	{
	case 0:
		m_oct0 = val;
		break;
	case 1:
		m_oct1 = val;
		break;
	case 2:
		m_oct2 = val;
		break;
	default:
		cout << "Wrong position!" << endl;
	}

	Show();
}