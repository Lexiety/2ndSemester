#include <iostream>
#include <math.h>

using namespace std;


int log (int n, int a[3][3] )
{
int i,int s=0;
int max=0;
for( i=0; i<n; i++ )
 {
    if (a[i][i]>max) {max=a[i][i];}
 }


for( i=0; i<n; i++ )
 for (int j=0, j<n, j++)
 {
      if (a[i][j]>max) { s+=1;}
 }

return s;
}

int main()
{
int a[3][3]={ 3, 5, 7, 9, 11, 13, 15, 17, 19};
int s = log( 3, a );
cout<<s;
return 0;
}
