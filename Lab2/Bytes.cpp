#include "Bytes.h"
using namespace std;
/*
void Bytes::ShowOct()
{
	//cout.flags(ios::oct | ios::showbase);
	cout <<oct<< static_cast<int>(m_dec) << endl; 

}

void Bytes::ShowHex()
{
	//cout.flags(ios::hex | ios::showbase);
	cout <<hex<< static_cast<int>(m_dec) << endl;

}
*/
void Bytes::ShowDec()
{
	
	cout <<dec<< static_cast<int>(m_dec) << endl;

}

void Bytes::ShowChar()
{

	cout << static_cast<char>(m_dec) << endl;

}