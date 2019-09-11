#include "Hex.h"
using namespace std;

void Hex::Show()
{
	const char* str = "0123456789abcdef";
	
	//cout <<hex<< static_cast<int>(m_hex1) << static_cast<int>(m_hex0)<< endl;

	cout << str[m_hex1] << str[m_hex0] << endl;
}

void Hex::ShowPos(int pos)
{
	switch (pos)
	{
	case 0:
		cout << hex << static_cast<int>(m_hex0) << endl;
		break;
	case 1:
		cout << hex << static_cast<int>(m_hex1) << endl;
		break;
	default:
		cout << "Wrong position!" << endl;
	}
}

void Hex::Edit(int pos, int val)
{

	if ((val < 0) || (val > 15))
	{
		cout << "Wrong value!" << endl;
		return;
	}

	switch (pos)
	{
	case 0:
		m_hex0 = val;
		break;
	case 1:
		m_hex1 = val;
		break;
	default:
		cout << "Wrong position!" << endl;
	}

	Show();
}
