#include <iostream>
#include <string>

using namespace std;

class money
{
private:
	long ruble;
	int kopeyka;
public:
	money()
	{
		ruble = 0;
		kopeyka = 0;
	}
	money(int r, int k)
	{
		ruble = r;
		kopeyka = k;
	}

	void copy(const money& a)
	{
		ruble = a.ruble;
		kopeyka = a.kopeyka;
	}
	void print()
	{
		cout << "value: " << ruble<< "," << kopeyka << endl;
	}

	void divide(const money& tmp, float div)
	{
		int a = 0;
		a = tmp.ruble * 100 + tmp.kopeyka;
		a = a / div;
		ruble = (a / 100);
		kopeyka = (a % 100);

	}
	
	void multiply(const money& tmp, float mltpl)
	{
		int a = 0;
		a = ruble * 100 + kopeyka;
		a = a * mltpl;
		ruble = (a/ 100);
		kopeyka = (a % 100);
	}



	~money()
	{
		cout << "Destructor did its job..." << endl;
	}
};

int main()
{
	money a(10, 16);
	a.print();
	a.divide(a, 6.0);
	a.print();
	money b(25, 15);
	b.multiply(b, 6.0);
	b.print();
	cout << endl;
	cout << endl;
	return 0;
}
