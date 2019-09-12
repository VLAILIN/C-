//
#include "Func.h"

void printMultiMapKey(multimap<string, pair<string, string>>& v, const string key)
{
	if (v.size()) //если словарь не пустой
	{	
		multimap<string, pair<string, string>>::template const_iterator itb = v.lower_bound(key);
		if (itb!=v.end()) //если есть такой же key
		{
			cout << "key: " << (*itb).first << " value: ";
			multimap<string, pair<string, string>>::template const_iterator ite = v.upper_bound(key);
			while (itb != ite)
			{
				cout << (*itb).second.first <<", "<< (*itb).second.second;
				++itb;
				if ((itb == ite)) cout<<".";
				else cout << ", ";
			}
			cout << endl;			
		}
		else cout<<"Key don't found!"<<endl;
	}
	else cout<<"No elements here!"<<endl;
}

	
	

	
	
