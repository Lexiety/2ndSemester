#include <iostream>
using namespace std;

void f(int k, int(&arr)[6][6])
	{
		for (int i=0; i<6; i++)
			{
			if (arr[k][i] > -1) { arr[k][i] = -1; f(i, arr); cout << k << " "; }
			}
	}

int main()
{
	int a[6][6];
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			a[i][j] = -1;
	}

	a[0][1] = 11;
	a[1][3] = 6;
	a[0][2] = 21;
	a[5][0] = 7;
	a[3][2] = 8;
	a[2][5] = 20;
	a[3][4] = 15;
	a[4][2] = 3;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}


	f(0,a);
	cout << endl;
	cout << "Backward route" << endl;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
			cout << a[i][j]<<"  ";
		cout << endl;
	}

	cout << "BECb GRAPH PROYDEN!" << endl;

	return 0;
}

