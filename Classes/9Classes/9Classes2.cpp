#include <iostream>
#include <string>

using namespace std;
class error
{
	string str;
public:
	error(string s) { str = s; }
	void what() { cout << str << endl; }
};

const int MAX_SIZE = 20;

class Arr
{
private:
	int size;
	int* cur;
public:
	Arr()
	{
		size = 0;
	}


	Arr(int s, int k = 0)
	{
		if (s > MAX_SIZE) throw error("ArraySize>MaxSize\n");
		size = s;
		cur = new int[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = k;
		}
	}
	Arr(const Arr& tmp)
	{
		if (tmp.size > MAX_SIZE) throw error("ArraySize>MaxSize\n");
		size = tmp.size;
		cur = new int[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = tmp.cur[i];
		}
	}

	bool operator==(const Arr& tmp)
	{
		if (size != tmp.size)
		{
			return false;
		}
		bool l = true;
		for (int i = 0; i < size; i++)
		{
			if (cur[i] != tmp.cur[i]) { l = false; }
		}
		return l;

	}

	bool operator>(int tmp)
	{

		for (int i = 0; i < size; i++)
		{
			if (cur[i] == tmp) { return true; }
		}
		return true;
	}


	int& operator[](int i)
	{
		if (i < 0) throw error("Index < 0\n");
		if (i >= size) throw error("Index > ArraySize\n");
		return cur[i];
		
	}

	friend ostream& operator<<(ostream& out, const Arr& tmp);
	friend istream& operator>>(istream& in, Arr& tmp);
};




ostream& operator<<(ostream& out, const Arr& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		out << tmp.cur[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, Arr& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		in >> tmp.cur[i];
	}
	return in;
}

int main()
{
	try
	{
		Arr a(5);
		cout << a << "\n";
		cin >> a;
		cout << a << "\n";
		a[2] = 11012;
		cout << a << "\n";
		Arr b(10);
		cin >> b;
		cout << b << "\n";
		cout << (a == b) << endl;
		Arr C(30);
	}
	catch (error e)
	{
		e.what();
	}
	return 0;
}
