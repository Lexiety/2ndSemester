#include <queue>
#include <iostream>
using namespace std;
template <typename T>

void print(queue<T> st)
{
	int num = st.size();
	for (int i = 0; i < num; i++)
	{
		cout << st.front() << " ";
		st.pop();
	}
}

int main()
{
	int n;
	int a;
	cout << "Queue size - ";
	cin >> n;
	queue<int> queue1;
	queue<int> queue2;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		queue1.push(a);
	}
	print(queue1);
	cout << endl;

	int count = 1;
	while ((count <= 2 * n) && (queue1.size() > 0))
	{
		if (count % 2 != 0)
		{
			cin >> a;
			queue2.push(a);
		}
		else
		{
			queue2.push(queue1.front());
			queue1.pop();
		}
		count++;
	}

	while (count <= n)
	{
		cin >> a;
		queue2.push( a);
		count++;
	}
	while (queue1.size() > 0)
	{
		queue2.push(queue1.front());
		queue1.pop();
	}

	print(queue2);

	return 0;
}
