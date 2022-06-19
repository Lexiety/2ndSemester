#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void print(stack<T> st)
{
	int num = st.size();
	for (int i = 0; i < num; i++)
	{
		cout << st.top() << " ";
		st.pop();
	}
}

int main()
{
	int n;
	char k;
	cout << "Stack size - ";
	cin >> n;
	stack<char> st;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		st.push(k);
	}
	print(st);
	cout << endl;
	stack<char> st2;
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		if (count % 2 == 1)
		{
			st2.push(st.top());
		}
		st.pop();
		count++;
	}
	int num2 = st2.size();
	for (int i = 0; i < num2; i++)
	{
		
			st.push(st2.top());
			st2.pop();
	}

	for (int i = 0; i < num2; i++)
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
