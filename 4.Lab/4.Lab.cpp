#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{   
	const int n = 10;
	int a[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = rand();
		//cout << a[i] << " ";
	}
	int k = 0;
	//cout << endl;

	for (int i = n-1; i < n+n; i++)
	{   
		k = i;
		while (k >= n) { k = k - n; }
		cout << a[k] << " ";
	}
	cout << endl;

	for (int i = 0; i < n - 1; i++) 
	{
		int min = a[i];
		for (int j = i; j < n; j++)
		{
			if (a[j] < min) { min = a[j]; k = a[j]; a[j] = a[i]; a[i] = k; }

		}
	}

	int j = 0;
	int b[( n + 1 ) / 2 ];
	while (2*j<n)
	{	
		b[j] = a[2 * j];
		j++;
	}

	for (int i = (n + 1) / 2-1; i < ((n + 1) / 2)*2; i++)
	{
		k = i;
		while (k >= (n + 1) / 2) { k = k - (n + 1) / 2; }
		cout << b[k] << " ";
	}
	cout << endl;

	return 0;
}
