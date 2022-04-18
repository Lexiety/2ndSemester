#include <iostream>
#include <string>

using namespace std;

class PC
{
private:
	string CPU;
	int RAM;
	int HDD;
public:
	void set(string CPU, int RAM, int HDD)
	{
		this->CPU = CPU;
		this->RAM = RAM;
		this->HDD = HDD;
	}
	void def()
	{
		CPU = "Ryzen 5 3500u";
		RAM = 8;
		HDD = 256;
	}
	void copy(const PC& a)
	{
		CPU = a.CPU;
		RAM = a.RAM;
		HDD = a.HDD;
	}
	void print()
	{
		cout << "CPU: " << CPU
			<< "\nRAM: " << RAM
			<< "\nHDD: " << HDD << endl;
	}
	~PC()
	{
		cout << "Destructor did the job..." << endl;
	}
};

int main()
{
	PC a, b, c;
	cout << "Constructor with parameters" << endl;
	a.set("Intel Core i3 - 6100", 16, 1000);
	a.print();
	cout << endl;
	cout << "Constructor without parameters" << endl;
	b.def();
	b.print();
	cout << endl;
	cout << "Coping constructor" << endl;
	c.copy(a);
	c.print();
	cout << endl;
	return 0;
}
