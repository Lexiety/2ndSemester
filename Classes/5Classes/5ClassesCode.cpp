#include <iostream>
#include <string>

using namespace std;

class abstract
{
public:
	virtual void show() = 0;
};


class triad : public abstract
{
protected:
	int first;
	int second;
	int third;
public:
	triad()
	{
		first = 0;
		second = 0;
		third = 0;
	}
	triad(int r, int k, int l)
	{
		first = r;
		second = k;
		third = l;
	}
	void show() override
	{
		cout << first << ", " << second<< ", " << third<< "  ";
	}


	~triad()
	{
		cout << "Destructor did its job" << endl;
	}


	void sort()
	{
		if (first > second) { swap(first, second); }
		if (first > third) { swap(first, third); }
		if (second > third) { swap(third, second); }
	}

	friend istream& operator>>(istream& in, triad& tmp);
	friend ostream& operator<<(ostream& out, const triad& tmp);

};

class date : public triad
{
public:

	date()
	{
		first = 0;
		second = 0;
		third = 0;

	}

	 friend void check(date& tmp1, date& tmp2);


};

void check(date& tmp1, date& tmp2)
{
	if (tmp1.third > tmp2.third)
	{
		tmp1.show();
		cout << " > ";
		tmp2.show();
	}

	else if (tmp1.third < tmp2.third)
	{
		tmp1.show();
		cout << " < ";
		tmp2.show();
	}

	else if (tmp1.third == tmp2.third)
	{
		if (tmp1.second  > tmp2.second)
		{
			tmp1.show();
			cout << " > ";
			tmp2.show();
		}
		else if (tmp1.second < tmp2.second)
		{
			tmp1.show();
			cout << " < ";
			tmp2.show();
		}
		else if (tmp1.second == tmp2.second)
		{
			if (tmp1.first > tmp2.first)
			{
				tmp1.show();
				cout << " > ";
				tmp2.show();
			}
			else if (tmp1.first < tmp2.first)
			{
				tmp1.show();
				cout << " < ";
				tmp2.show();
			}

			else if (tmp1.first == tmp2.first)
			{
				tmp1.show();
				cout << "   They are the same    ";
				tmp2.show();
			}

		}

	}


}



istream& operator>>(istream& in, triad& tmp)
{
	cout << "First: "; in >> tmp.first;
	cout << "Second: "; in >> tmp.second;
	cout << "Third: "; in >> tmp.third;
	
	bool flag = false;
	while (flag == false)
	{
		if ((tmp.first < 32) && (tmp.second < 13)) { flag = true; }
		if (flag == false)
		{
			cout << "Invalid input!" << endl;
			if (tmp.first > 31) { cout << " Please enter correct day:" << endl; cin >> tmp.first; }
			if (tmp.second > 12) { cout << " Please enter correct month:" << endl; cin >> tmp.second; }
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const triad& tmp)
{
	return (out <<  tmp.first << ", " << tmp.second << ", " << tmp.third );
}

int main()
{
	date m,n;
	cin>>n;
	cin >> m;
	check(m, n);



	return 0;
}
