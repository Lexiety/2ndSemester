#include <iostream>

using namespace std;

int IntSearch(int a[], int left, int right, int key)
{
	int mid = left + (key - a[left]) * (right - left) / (a[right] - a[left]);
	bool found = false;
	while ((left <= right) && found != true)
	{
		mid = left + (key - a[left]) * (right - left) / (a[right] - a[left]);
		if (a[mid] < key) left = mid + 1;
		else if (a[mid] > key) right = mid - 1;
		else found = true;
	}
	return mid;
}

int comp(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}

int main()
{
	cout << "Input to find:" << endl;
	int L;
	cin >> L;
	cout << "Array length:" << endl;
	int n;
	cin >> n;
	int* a = new int[n+2];
	for (int i = 0; i < n; i++)
	{
		a[i] =rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	a[5] = L;
	qsort(a,n, sizeof(int),comp);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int k = IntSearch(a, 0, n, L);
	
	for (int i = n+1; i > k-1; i--)
	{
		a[i] = a[i - 2];
	}
	
	a[k] = 0;
	a[k + 1] = 0;
	
	for (int i = 0; i < n+2; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	delete a;
	return 0;
}
