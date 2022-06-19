#include <iostream>
using namespace std;

template <typename T>
class Node
{	public:
	T data;
	Node<T>* next;
};

template <typename T>
class Queue
{
public:
	int size = 0;
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
};

template <typename T>
void push(Queue<T>& tmp, const T& data)
{
	if (tmp.head != nullptr)
	{
		Node<T>* newnode = new Node<T>;
		tmp.size++;
		newnode->data = data;
		newnode->next = nullptr;
		tmp.tail->next = newnode;
		tmp.tail = newnode;
	}
	else
	{
		Node<T>* newnode = new Node<T>;
		newnode->data = data;
		tmp.head = newnode;
		tmp.tail = newnode;
		tmp.size = 1;
	}
}

template <typename T>
void pop(Queue<T>& tmp)
{
	Node<T>* del = tmp.head;
	tmp.head = tmp.head->next;
	tmp.size--;
	delete del;
}

template <typename T>
void print(Queue<T>& tmp)
{
	Node<T>* del = tmp.head;
	while (del != nullptr)
	{
		cout << del->data<< " ";
		del = del->next;
	}
}

template <typename T>
void add(Queue<T>& tmp, Queue<T>& tmp2, int& n)
{
	int count = 1;
	while ((count <= 2*n)&&(tmp.size>0))
	{
		if (count % 2 != 0)
		{
			T a;
			cin >> a;
			push(tmp2, a);
		}
		else
		{
			push(tmp2, tmp.head->data);
			pop(tmp);
		}
		count++;
	}

while (count<=n) 
	{
		T a;
		cin >> a;
		push(tmp2, a);
		count++;
	}
 while (tmp.size > 0) 
	{
		push(tmp2, tmp.head->data);
		pop(tmp);
		cout << tmp.size<< endl;
	}

}

template <typename T>
void newQueue(Queue<T>& tmp, const int& n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		push(tmp, a);
	}
}


template <typename T>
void deleteQueue(Queue<T>& tmp)
{
	while (tmp.head != nullptr)
	{
		pop(tmp);
	}
}

int main()
{
	int n;
	int a;
	cout << "Queue size - ";
	cin >> n;
	Queue<int> queue;
	Queue<int> queue2;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		push(queue, a);
	}
	print(queue);
	cout << endl;
	add(queue, queue2, n);
	cout << endl;
	print(queue2);
	deleteQueue(queue);
	return 0;
}
