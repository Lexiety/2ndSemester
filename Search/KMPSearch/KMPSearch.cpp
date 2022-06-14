#include <iostream>
#include <string>

using namespace std;

int BMSearch(string str, string strl)
{
	int l, l1;
	l = str.size();
	l1 = strl.size();
	int* a = new int[l1];
	int i = 0;
	int j = -1;
	a[0] = -1;
	while (i < l1 - 1)
	{
		while ((j >= 0) && (strl[j] != strl[i]))
		{
			j = a[j];
		}
		i++;
		j++;
		if (strl[i] == strl[j])
		{
			a[i] = a[j];
		}
		else
		{
			a[i] = j;
		}
		i = 0;
		j = 0;
		for (i = 0, j = 0; (i <= l - 1) && (j <= l1 - 1); i++, j++)
		{
			while ((j >= 0) && (strl[j] != str[i]))
			{
				j = a[j];
			}
		}
		delete[] a;
		if (j == l1)
		{
			return i - j;
		}
		else return -1;
	}
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
	if (p == -1) { cout << "NOT FOUND" << endl; }
	else 
	{ 
		cout << "BOT OH:" << p << endl; 
		for (int i = p; i < p + strl.size(); i++)
		{
			str[i] = ' ';
		}
		cout << str << endl;
	}

	
	return 0;
}
