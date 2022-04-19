#include <iostream>
#include <random>
using namespace std;

void hoarasort(int* a, int first, int last)
{

    int i = first;
    int j = last;
    double tmp, x = a[(first + last) / 2];

    do {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;

        if (i <= j)
        {
            if (i < j)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        hoarasort(a, i, last);
    if (first < j)
        hoarasort(a, first, j);
}

int main()
{
    int arr[100];
    for (int i=0; i<100; i++)
    {
        arr[i] = rand();
    }

    for (int i = 0; i < 100; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    hoarasort(arr, 0, 99);

    for (int i = 0; i < 100; i++)
    {
        cout << arr[i]<< " ";
    }

    return 0;

}
