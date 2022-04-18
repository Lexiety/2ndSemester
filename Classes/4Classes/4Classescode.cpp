#include <iostream>
#include <string>

using namespace std;

class PAIR
{
protected:
	int first; 
	int second;
public:
	PAIR()
	{
		first = 0;
		second = 0;
	}
	PAIR(int r, int k)
	{
		first = r;
		second = k;
	}

	void copy(const PAIR& a)
	{
		first = a.first;
		second = a.second;
	}
	void print()
	{
		cout << first << "," << second << endl;
	}

	void subtraction(const PAIR& tmp1, const PAIR& tmp2, const PAIR& tmp3)
	{
		int a, b, c, d, e, f;
		a = tmp1.first;
		c = tmp2.first;
		b = tmp1.second;
		d = tmp2.second;
		first = a - b;
		second = c - d;
	}



	~PAIR()
	{
		cout << "Destructor did its job..." << endl;
	}
};

class rational : public PAIR
{
public:

	rational()
	{
		first = 0;
		second = 0;
	}
	rational(int f, int s)
	{
		first = f;
		second = s;
	}
	
	void subtraction2(const rational& tmp1, const rational& tmp2)
	{
		int a = tmp1.first * tmp2.second - tmp2.first * tmp1.second;
		int b = tmp1.second * tmp2.second;
		first = a;
		second = b;
		simpleR(tmp1);
	}

	void simpleR(const rational& tmp1)
	{
		int a = abs(tmp1.first);
		int b = abs(tmp1.second);
		while (a != b)
		{
			b = b - a;
			if (b < a) { swap(a, b); }
		}
		first = first / a;
		second = second / a;
	}
};


int main()
{
	PAIR a(10, 16);
	PAIR b(25, 15);
	PAIR c(20, 20);
	c.subtraction(a, b, c);
	rational d(12, 15);
	rational e(37, 74);
	rational f(14, 28);
	f.simpleR(f);
	f.print();
	d.subtraction2(d, e);
	d.print();
	c.print();
	cout << endl;
	return 0;
}
