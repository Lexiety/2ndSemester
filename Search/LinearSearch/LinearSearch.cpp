#include <iostream>

using namespace std;

void linearSearch(char a[], int n)
{
	bool r = false;
	int u = 0;
	int y = 0;
	bool t = false;
	for (int i = 0; i < n; i++)
	{
		if ((r == false) && (a[i] == 'L')) { r = true; u = i; }
		if ((t == false) && (a[i] == 'g')) { t = true; y = i; }
		if (r * t == true) { swap(a[u], a[y]); break; }
	}

}

int main()
{
	cout << "Array length:" << endl;
	int n;
	cin >> n;
	char* a = new char[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = (char)(rand() % 200);
	}
	a[5] = 'L';
	a[8] = 'g';
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	linearSearch(a, n);
	
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	delete a;
	return 0;
}
