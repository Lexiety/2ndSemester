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

	void equal()
	{
		if (first == second) { cout << "They're equal" << endl; }
	}
	
	void mltpl()
	{
		cout << first*second << endl; 
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

	void multiply2(const rational& tmp1, const rational& tmp2)
	{
		int a = tmp1.first * tmp2.first;
		int b = tmp1.second * tmp2.second;
		first = a;
		second = b;
		simpleR(tmp1);
	}

	
	void summarize3(const rational& tmp1, const rational& tmp2)
	{
		int a = 0;
		int b = 0;
		 a = tmp1.first * tmp2.second + tmp1.second * tmp2.first;
		 b = tmp1.second * tmp2.second;
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
		if (a != 0) { first = first / a; }
		if (a != 0) { second = second / a; }
		cout << first << "/" << second<< endl;
	}
};


int main()
{
	PAIR a(10, 16);
	PAIR b(25, 15);
	PAIR c(20, 28);
	a.equal();
	a.mltpl();
	c.subtraction(a, b, c);

	rational e(37, 74);
	rational f(14, 28);
	rational x(156, 248);
	rational y(18, 189);
	f.simpleR(f);
	e.multiply2(e, f);
	rational u(7, 8);
	u.simpleR(u);
	x.subtraction2(x, y);
	cout << endl;
	return 0;
}
