 //Variant 24
#include <iostream>

using namespace std;

long f(long x, int j)
{
	if ((j % 2)-1==0) {return 0;}
	else {return x;}
}
 int f( int x, int j)
{
    	
   	if ((j % 2)-1==0) {return 0;} 
   	else {return x;}
}

int main()
{
	int a[]={10, 20, 30, 40, 50, 60};
	for (int i=0; i<6; i++)
	{a[i]=f(a[i], i);
	cout << a[i] << " ";}
return 0;
}
