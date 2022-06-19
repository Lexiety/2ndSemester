#include <iostream>
#include <string>

using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmAdd = 1;
const int cmDel = 2;
const int cmGet = 3;
const int cmShow = 4;
const int cmMake = 6;
const int cmFind = 7;
const int cmQuit = 101;


class Object
{
public:
	Object() {}
	virtual void Show() = 0;
	virtual void input() = 0;
	virtual ~Object() {}
	virtual void HandleEvent(const TEvent& e) = 0;
};

class Person : public Object
{
protected:
	string name;
	int age;
public:
	Person()
	{
		name = "NULL";
		age = 0;
	}
	virtual ~Person() {}
	void Show() override
	{
		cout << "\nName: " << name;
		cout << "\nAge: " << age << endl;
	}
	void input() override
	{
		cout << "\nName: ";
		cin >> name;
		cout << "\nAge: ";
		cin >> age;
		cout << endl;
	}
	Person(string n, int a)
	{
		name = n;
		age = a;
	}
	Person(const Person& tmp)
	{
		name = tmp.name;
		age = tmp.age;
	}
	string GetName() { return name; }
	int GetAge() { return age; }
	void SetName(string n)
	{
		name = n;
	}
	void SetAge(int a)
	{
		age = a;
	}
	Person& operator=(const Person& tmp)
	{
		if (&tmp == this)
		{
			return *this;
		}
		name = tmp.name;
		age = tmp.age;
		return *this;
	}
	void HandleEvent(const TEvent& e)
	{
		if (e.what == evMessage)
		{
			switch (e.command)
			{
			case cmGet: cout << "Name: " << GetName() << endl;
				break;
			}
		}
	}
};
struct TEvent
{
	int what;
	union
	{
		int command;
		struct
		{
			int message;
			int a;
		};
	};
};


class Abiturient : public Person
{
protected:
	int ball;
	string spec;
public:
	Abiturient() : Person()
	{
		ball = 0;
		spec = "nothing";
	}
	~Abiturient() {}
	void Show() override
	{
		cout << "\nName: " << name;
		cout << "\nAge: " << age;
		cout << "\nBalls: " << ball;
		cout << "\nSpeciality: " << spec << endl;
	}
	void input() override
	{
		cout << "\nName: ";
		cin >> name;
		cout << "\nAge: ";
		cin >> age;
		cout << "\nBalls: ";
		cin >> ball;
		cout << "\nSpeciality: ";
		cin >> spec;
		cout << endl;
	}
	Abiturient(string n, int a, int z, string j) : Person(n, a)
	{
		ball = z;
		spec = j;
	}
	Abiturient(const Abiturient& tmp)
	{
		name = tmp.name;
		age = tmp.age;
		ball = tmp.ball;
		spec = tmp.spec;
	}
	float GetBall() { return ball; }
	string GetSpec() { return spec; }
	void SetBall(int z)
	{
		ball = z;
	}
	void SetSpec(string j)
	{
		spec = j;
	}
	Abiturient& operator=(const Abiturient& tmp)
	{
		if (&tmp == this) return *this;
		name = tmp.name;
		age = tmp.age;
		ball = tmp.ball;
		spec = tmp.spec;
	}
};

/*struct Node
{
	Person data;
	Node* ptr_next = nullptr;
};

struct List
{
	Node* headnode = nullptr;
	Node* tailnode = nullptr;


void pushBack(List& list, int& data)
{
	Node* newnode = new Node;
	newnode->data = data;
	if (list.headnode == nullptr)
	{
		list.headnode = newnode;
		list.tailnode = newnode;
	}
	else
	{
		list.tailnode->ptr_next = newnode;
		list.tailnode = newnode;
	}
}

void printList(List& list)
{
	Node* currentnode = list.headnode;
	while (currentnode != nullptr)
	{
		cout << currentnode->data << " ";
		currentnode = currentnode->ptr_next;
	}
}

};
not finished
*/

class Vector
{
protected:
	Object** beg;
	int size;
	int cur;
public:
	Vector()
	{
		beg = nullptr;
		size = 0;
		cur = 0;
	}
	Vector(int n)
	{
		beg = new Object * [n];
		cur = 0;
		size = n;
	}
	~Vector()
	{
		if (beg != 0) delete[] beg;
		beg = 0;
	}
	void Add()
	{
		Object* p;
		cout << "1. Person" << endl;
		cout << "2. Abiturient" << endl;
		int y;
		cin >> y;
		if (y == 1)
		{
			Person* tmp = new Person;
			tmp->input();
			p = tmp;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else
		{
			if (y == 2)
			{
				Abiturient* tmp1 = new Abiturient;
				tmp1->input();
				p = tmp1;
				if (cur < size)
				{
					beg[cur] = p;
					cur++;
				}
			}
			else return;
		}
	}
	void Show()
	{
		if (cur == 0) cout << "Empty" << endl;
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->Show();
			p++;
		}
	}
	int operator()()
	{
		return cur;
	}
	void Del()
	{
		if (cur == 0) return;
		cur--;
	}
	void Find(int tmp)
	{
		beg[tmp];
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			if (i == tmp - 1)
			{
				(*p)->Show();
			}
			p++;
		}
	}
	void HandleEvent(const TEvent& e)
	{
		if (e.what == evMessage)
		{
			Object** p = beg;
			for (int i = 0; i < cur; i++)
			{
				(*p)->HandleEvent(e);
				p++;
			}
		}
	}
};

class Dialog : public Vector
{
protected:
	int EndState;
public:
	Dialog() : Vector()
	{
		EndState = 0;
	}
	~Dialog() {}
	void GetEvent(TEvent& event)
	{
		string getcode = "m+-szq";
		string s;
		string param;
		char code;
		cout << '>';
		cin >> s;
		code = s[0];
		if (getcode.find(code) >= 0)
		{
			event.what = evMessage;
			switch (code)
			{
			case 'm': event.command = cmMake; break;
			case '+': event.command = cmAdd; break;
			case '-': event.command = cmDel; break;
			case 's': event.command = cmShow; break;
			case 'q': event.command = cmQuit; break;
			case 'z': event.command = cmFind; break;
			}
			if (s.length() > 1)
			{
				param = s.substr(1, s.length() - 1);
				int A = atoi(param.c_str());
				event.a = A;
			}
		}
		else event.what = evNothing;
	}
	int Execute()
	{
		TEvent event;
		do {
			EndState = 0;
			GetEvent(event);
			HandleEvent(event);
		} while (!Valid());
		return EndState;
	}
	int Valid()
	{
		if (EndState == 0) return 0;
		else return 1;
	}
	void ClearEvent(TEvent& event)
	{
		event.what = evNothing;
	}
	void EndExec()
	{
		EndState = 1;
	}
	void HandleEvent(TEvent& event)
	{
		if (event.what == evMessage)
		{
			switch (event.command)
			{
			case cmMake:
				size = event.a;
				beg = new Object * [size];
				cur = 0;
				ClearEvent(event);
				break;
			case cmAdd:
				Add();
				ClearEvent(event);
				break;
			case cmDel:
				Del();
				ClearEvent(event);
				break;
			case cmShow:
				Show();
				ClearEvent(event);
				break;
			case cmQuit:
				EndExec();
				ClearEvent(event);
				break;
			case cmFind:
				int tmp = event.a;
				Find(tmp);
				ClearEvent(event);
				break;
			}
		}
	}
};

int main()
{
	cout << "+ - add element" << "\n- - delete element" << "\nm<n> - make a group of n men" << "\ns - print the group" << "\nz<n> - Print the n element" << "\nq - The end" << "" << endl;
	Dialog D;
	D.Execute();
	return 0;
}
