#include <iostream>
#include <math.h>
#include <string.h>
#include <ctype.h>

using namespace std;

int main()

{
	
	char spr[] = "forklift is a cool position to hold site "; // Line input
	char a[40][12];
	unsigned long long b[40];
	int j = -1;
	int i = 0;

			for (int i = 0; i < 40; i++)           
			{
				for (int j = 0; j < 12; j++)
				{
					a[i][j] = ' ';
					b[i] = 1;
				}

			}

			 j = -1;
			 i = 0;
	
			for  (int k=0; k<strlen(spr); k++)  
			{
				j++;
				
				a[i][j] = spr[k];
				if (spr[k] == ' ') { i++; j = -1; }
			}

			int n = 0;
			for (int k = 0; k < 40; k++)
			{
				if (a[k][0] == ' ') { break; }
				n++;
			}


			for (i = 0; i < n; i++)
			{
				for (j = 0; j < 12; j++)
				{
					b[i] = b[i]*26 + (unsigned long long)a[i][j] - 96;
					
				}
				cout << b[i] << "  ";
			}
			unsigned long long min = 0;
			unsigned long long L = 0;

			for (i = 0; i < n-1; i++)
			{
				min = b[i];
				for (j = i; j < n; j++)
				{
					if (b[j] < min) { 
									 for (int p=0; p<12; p++)
									 {
										 swap(a[i][p], a[j][p]);
									 }
									min = b[j]; 
									L = b[j]; 
									b[j] = b[i]; 
									b[i] = L; 
									

									}

				}
			}



			for (i = 0; i < 40; i++)
			{
				if (a[i][0] == ' ') { break; }
				for (j = 0; j < 12; j++)
				{
					cout << a[i][j];

				}
				cout << endl;
			}
	return 0;
}
