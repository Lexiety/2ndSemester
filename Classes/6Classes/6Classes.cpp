#include <iostream>

using namespace std;

class Iterator
{
private:
	friend class Arr;
	int* elem;
public:
	Iterator()
	{
		elem = 0;
	}
	Iterator(const Iterator& tmp)
	{
		elem = tmp.elem;
	}
	bool operator==(const Iterator& tmp)
	{
		return elem == tmp.elem;
	}
	bool operator!=(const Iterator& tmp)
	{
		return elem != tmp.elem;
	}
	void operator++()
	{
		++elem;
	}
	void operator--()
	{
		--elem;
	}
	int& operator*()
	{
		return *elem;
	}
};

class Arr
{
private:
	int size;
	int* cur;
public:
	Arr(int s, int k = 0)
	{
		size = s;
		cur = new int[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = k;
		}
	}
	Arr(const Arr& tmp)
	{
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
		if (i < size)
		{
			return cur[i];
		}
		else
		{
			cout << "i > Array size" << endl;
		}
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
	Arr a(5);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	a[2] = 100;
	cout << a << "\n";
	Arr b(10);
	cin >> b;
	cout << b << "\n";
	cout<< (a == b);

}
