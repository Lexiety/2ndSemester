#include <iostream>
#include <string>

using namespace std;

int BMSearch(string str, string strl)
{
	int a[26];
	for (int i = 65; i < 91; i++)
	{
		a[i - 65] = strl.size();

		if (strl.rfind(i) != -1) { a[i - 65] =  strl.rfind(i) + 1 ; }
		cout << a[i - 65];
	}
	int k = 0;
	int u = 0;
	bool boo = false;
	cout << endl;
	while (boo == false)
	{
		for (int i = 0; i < strl.size(); i++)
		{
			if (str[i + k] == strl[i]) {  }
			else { break; }

			if (i == strl.size() - 1) { boo = true; return k; break; }
		}

		k = a[str[strl.size()]+k-65] + k ;
		cout << k << endl;;
	}
	return u;

}

int main()
{
	cout << "Substring to find:" << endl;
	string strl;
	cin >> strl;
	cout << "String:" << endl;
	string str;
	cin >> str;
	
	int p = BMSearch(str, strl);

	cout << endl;

	cout <<"BOT OH:"<< p;

	for (int i = p; i < p + strl.size(); i++)
	{
		str[i] = str[i + strl.size()];
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i]<< "  ";
	}


	return 0;
}
