#include <iostream>
#include <math.h>
#include <stdarg.h>
using namespace std;
double f(int A, int B, int C, int D)
{
    return sqrt((A - C) * (A - C) + (B - D) * (B - D)); // Finding the distance between two points, Alfa(A,B) and Beta(C,D)
}

double square(int a, int b, int c, int d, int e, int fu) // Finding the area of an triangle with given points Alfa(a,b), Beta(c,d), Gamma(e,fu)
{
        double A = f(a, b, c, d);
        double B = f(c, d, e, fu);
        double C = f(e, fu, a, b);
        double p = (A + B + C) / 2;
    return sqrt(p * (p - A) * (p - B) * (p - C));
}

double squaren(int k, ...) // Finding the area of a convex polygon with k/2 points
                           // k means the amount of points' coordinates (x,y)
                           // Coordinates must be entered in strict order, FE pentagon, where k=10:
                           // 10, x1, y1, x2, y2, x3, y3 ,x4, y4, x5, y5
{
    va_list p;
    va_start(p, k);
        int a[100];
        int i = -1;            // counter
        for (  ; k != 0; k--)
            {
                i++;
                a[i] = va_arg(p, int); //Array "a" filled with both x and y coordinates
            }
        ++i;
    
        int b[100];
        int c[100];
    
        for (int j = 0; j < i; j++) // Splitting x and y coordiantes on 2 different arrays "b" and "c"
            {
                if (j % 2 == 0) { b[j / 2] = a[j]; }
                if (j % 2 != 0) { c[j / 2] = a[j]; }
            }

        double s=0.0; 

        for (int j = 0; j < (i/2-1); j++)   // Using shoelace formula to find area of the convex polygon
            {
                s = s+((b[j] + b[j + 1]) * (c[j + 1] - c[j]));
            }
    
        s += (b[i / 2-1] + b[0]) * (c[0] - c[i / 2-1]);

    va_end(p);
    return (s / 2);
}
int main()
{
        int a[] = { 0, 0, 10, 0, 0, 10 };                               //Example of entering the triangular's coordianates
        cout << square(a[0], a[1], a[2], a[3], a[4], a[5]) << endl;
        cout << abs(squaren(8 ,0, 0, 0, 10, 10, 10, 10, 0)) << endl;    //Example of entering the convex polygon's coordianates

    return 0;
}
