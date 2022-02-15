#include <iostream>
#include <math.h>
#include <stdarg.h>
using namespace std;
 float f( int A, int B, int C, int D)
{
    	return sqrt((A-C)*(A-C)+(B-D)*(B-D));
}

float square(int a,int b,int c,int d,int e,int fu)
{
	float A= f(a,b,c,d);
	float B= f(c,d,e,fu);
	float C=f(e,fu,a,b);
	float p=(A+B+C)/2;
	return sqrt (p*(p-A)*(p-B)*(p-C));
}

float squaren ( int k, ...)
{  
   int *p=&k;
   int a[100];
   int i=-1;
   for (  ;  k!=0; k--)
      {
         i++;
         a[i]=*(++p);
      }
      int b[100];
      int c[100];
      float s;
      for (int j=0; j < (i/2 -1); j++)
       {
           s+= (b[j]+b[j+1])*(c[j+1]-c[j]);
           
       }
       s+= ( b[i/2]+b[0])*(c[0]-c[i/2]);
       return (s/2);
}
int main()
{
	int a[]={0, 0, 10, 0, 0, 10};
    cout<< square (a[0], a[1], a[2], a[3], a[4], a[5])<< endl;
    cout<<squaren (0,0,10,0,10,10,10,0)<< endl;


return 0;
}
