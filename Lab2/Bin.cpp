#include "Bin.h"
using namespace std;
void Bin::Show()
{
	cout<< static_cast<int>(m_bin7)<< static_cast<int>(m_bin6)<< static_cast<int>(m_bin5) << static_cast<int>(m_bin4) << static_cast<int>(m_bin3) << static_cast<int>(m_bin2) << static_cast<int>(m_bin1) << static_cast<int>(m_bin0)<<endl;
}

void Bin::ShowPos(int pos)
{
	/*switch (pos)
	{
	case 0:
		cout << static_cast<int>(m_bin0) << endl;
		break;
	case 1:
		cout << static_cast<int>(m_bin1) << endl;
		break;
	case 2:
		cout << static_cast<int>(m_bin2) << endl;
		break;
	case 3:
		cout << static_cast<int>(m_bin3) << endl;
		break;
	case 4:
		cout << static_cast<int>(m_bin4) << endl;
		break;
	case 5:
		cout << static_cast<int>(m_bin5) << endl;
		break;
	case 6:
		cout << static_cast<int>(m_bin6) << endl;
		break;
	case 7:
		cout << static_cast<int>(m_bin7)<<endl;
		break;
	default:
		cout<<"Wrong position!"<<endl;
	}*/

	unsigned char tmp[8] = {m_bin0, m_bin1, m_bin2, m_bin3, m_bin4, m_bin5, m_bin6, m_bin7};

	if ((pos >= 0) && (pos <= 7))
	{
		cout << static_cast<int>(tmp[pos]) << endl;
	}
	else cout << "Wrong value!" << endl;
}

void Bin::Edit(int pos, int val)
{
	if ((val < 0) || (val > 1))
	{
		cout << "Wrong value!" << endl;
		return;
	}

	switch (pos)
	{
	case 0:
		m_bin0 = val;
		break;
	case 1:
		m_bin1 = val;
		break;
	case 2:
		m_bin2 = val;
		break;
	case 3:
		m_bin3 = val;
		break;
	case 4:
		m_bin4 = val;
		break;
	case 5:
		m_bin5 = val;
		break;
	case 6:
		m_bin6 = val;
		break;
	case 7:
		m_bin7 = val;
		break;
	default:
		cout << "Wrong position!" << endl;
	}

	Show();
}
