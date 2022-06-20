#include <iostream>
#include <string>
#include <list>

using namespace std;

class money
{
public:
	long ruble;
	int kopeyka;
	int total;

public:
	money()
	{
		ruble = 0;
		kopeyka = 0;
		total = 0;
	}
	money(int r, int k)
	{
		ruble = r;
		kopeyka = k;
		total = 100 * r + k;
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

	bool equal(const money& tmp)
	{
		if (total == tmp.total) { return true; }
		return false;
	}

	void minus(long a)
	{
		total = total - a;
		ruble = total / 100;
		kopeyka = total % 100;
	}


	~money()
	{
		//cout << "Destructor did its job..." << endl;
	}
};

int main()
{
	/*money a(10, 16);
	a.print();
	a.divide(a, 6.0);
	a.print();
	money b(25, 15);
	b.multiply(b, 6.0);
	b.print();
	cout << endl;
	*/
	
	list<money> c1;
	list<money> c2;
	list<money> c3;
	list <money>::iterator c1_Iter, c2_Iter;
	money a(10, 16);
	c1.push_back(a);
	money b(1, 50);
	money c(200, 60);
	money d(20, 86);
	c1.push_back(b);
	c1.push_back(c);
	c1.push_back(d);


	for (c1_Iter = c1.begin(); c1_Iter != c1.end(); c1_Iter++)
	{
		if (not (*c1_Iter).equal(c)) { c2.push_back((*c1_Iter)); }
	}
	int j = 0;

	//c1.insert(c1.begin()++,c); // na mesto s index==1

	
	for (c1_Iter = c1.begin(); c1_Iter != c1.end(); c1_Iter++)
	{(*c1_Iter).print();}
	cout << endl;

	for (c1_Iter = c2.begin(); c1_Iter != c2.end(); c1_Iter++)
	{
		(*c1_Iter).print();
	}
	cout << endl;
	for (c1_Iter = c2.begin(); c1_Iter != c2.end(); c1_Iter++)
	{
		if (j==1){ c3.push_back(c); }
		c3.push_back((*c1_Iter));
		j++;
	}

	for (c1_Iter = c3.begin(); c1_Iter != c3.end(); c1_Iter++)
	{
		(*c1_Iter).print();
	}
	cout << endl;
	long max=0;
	long min = 999999999;
	for (c1_Iter = c3.begin(); c1_Iter != c3.end(); c1_Iter++)
	{
		if ((*c1_Iter).total > max) { max = (*c1_Iter).total; }
		if ((*c1_Iter).total < min) { min = (*c1_Iter).total; }
	}

	for (c1_Iter = c3.begin(); c1_Iter != c3.end(); c1_Iter++)
	{
		(*c1_Iter).minus(max - min);
	}


	cout << endl;

	for (c1_Iter = c3.begin(); c1_Iter != c3.end(); c1_Iter++)
	{
		(*c1_Iter).print();
	}
	cout << endl;
	return 0;
}
