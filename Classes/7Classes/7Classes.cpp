#include <iostream>

using namespace std;


template <class T>
class Arr
{
private:
	int size;
	T* cur;
public:
	Arr()
	{
		size = 0;
	}
	
	
	Arr(int s, T k = 0)
	{
		size = s;
		cur = new T[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = k;
		}
	}
	Arr(const Arr<T>& tmp)
	{
		size = tmp.size;
		cur = new T[size];
		for (int i = 0; i < size; i++)
		{
			cur[i] = tmp.cur[i];
		}
	}

	bool operator==(const Arr<T>& tmp)
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

	bool operator>(T tmp)
	{
		
		for (int i = 0; i < size; i++)
		{
			if (cur[i] == tmp) { return true; }
		}
		return true;
	}


	T& operator[](int i)
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

class Money
{
public:
	long rub;
	int kop;


	Money()
	{
		
		rub=0;
		kop=0;
	}


	void Print()
	{
		cout << rub << "," << kop;
	}

	void Paste()
	{
			rub = rand() % 100100;
			kop = rand() % 100;
	}

};
template <class T>
ostream& operator<<(ostream& out, const Arr<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		out << tmp.cur[i] << " ";
	}
	return out;
}
template <class T>
istream& operator>>(istream& in, Arr<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		in >> tmp.cur[i];
	}
	return in;
}

int main()
{/*
	Arr<int> a(5);
	cout << a << "\n";
	cin >> a;
	cout << a << "\n";
	a[2] = 100;
	cout << a << "\n";
	Arr<int> b(10);
	cin >> b;
	cout << b << "\n";
	cout<< (a == b);
	*/
	const int n = 10;
	Money d[10];
	
	for (int i = 0; i < n; i++)
	{
		d[i].Paste();
		d[i].Print();
		cout << endl;
	}

}
