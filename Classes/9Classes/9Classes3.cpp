#include <iostream>
#include <string>

using namespace std;


class Error
{
public:
	virtual void what() {};
};


class IndexError : public Error
{
protected:
	string msg;
public:
	IndexError() 
	{ 
		msg = "Index Error\n"; 
	}
	virtual void what() { cout << msg; }
};



class SizeError : public Error
{
protected:
	string msg;
public:
	SizeError() 
	{ 
		msg = "SizeError\n"; 
	}
	virtual void what() { cout << msg; }
};



class MaxSizeError : public SizeError
{
protected:
	string msg_M;
public:
	MaxSizeError() 
	{
		SizeError();
		msg_M = "MaxSizeError\n";
	}
	virtual void what() { cout << msg << msg_M; }
};


class IndexError0 : public IndexError
{
protected:
	string msg_0;
public:
	IndexError0() 
	{
		IndexError();
		msg_0 = "Index<0\n";
	}
	virtual void what() { cout << msg << msg_0; }
};



class IndexErrorS : public IndexError
{
protected:
	string msg_S;
public:
	IndexErrorS() 
	{
		IndexError();
		msg_S = "Index>ArraySize\n";
	}
	virtual void what() { cout << msg << msg_S; }
};



class IndexError_S : public IndexError
{
protected:
	string msg_S;
public:
	IndexError_S() 
	{
		IndexError();
		msg_S = "Index<ArraySize\n";
	}
	virtual void what() { cout << msg << msg_S; }
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
		if (s > MAX_SIZE) throw MaxSizeError();
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
		if (i < 0) throw IndexError0();
		if (i >= size) throw IndexErrorS();
		
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
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}
