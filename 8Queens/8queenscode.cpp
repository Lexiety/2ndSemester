#include <iostream>
using namespace std;
int arr[8][8];

void sQ(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		++arr[x][j];
		++arr[i][x];
		int r;
		r = j - i + x;
		if (r >= 0 && r < 8)
		{
			++arr[x][r];
		}
		r = j + i - x;
		if (r >= 0 && r < 8)
		{
			++arr[x][r];
		}
	}
	arr[i][j] = -1;
}

void rQ(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		--arr[x][j];
		--arr[i][x];
		 int r = j - i + x;
		if (r >= 0 && r < 8)
		{
			--arr[x][r];
		}
		r = j + i - x;
		if (r >= 0 && r < 8)
		{
			--arr[x][r];
		}
	}
	arr[i][j] = 0;
}

bool check(int i)
{
	bool flag = false;
	for (int j = 0; j < 8; j++)
	{
		if (arr[i][j] == 0)
		{
			sQ(i, j);
			if (i == 7)
			{
				flag = true;
			}
			else
			{
				if (!(flag = check(i + 1)))
				{
					rQ(i, j);
				}
			}
		}
		if (flag)
		{
			break;
		}
	}
	return flag;
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = 0;
		}
	}
	check(0);
	for (int i = 0; i < 8; i++)
	{
		cout << (char)(72 - i) << "";
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == -1)
			{
				cout << " i ";
			}
			else
			{
				cout << " * ";
			}
		}
		cout << endl;
	}
	cout << "  A  B  C  D  E  F  G  H " << endl;
	return 0;
}
