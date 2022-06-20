#include <iostream>
#include <cmath>
using namespace std;

int mx = 0;
int count;
int cff = 1;

class Tree
{
private:
	char data;
	Tree* left;
	Tree* right;
	Tree* parent;
public:
	Tree(char d)
	{
		data = d;
		left = right = parent = nullptr;
	}
	Tree()
	{
		data = ' ';
		left = right = parent = nullptr;
	}
	int get_data()
	{
		return data;
	}
	Tree* get_left()
	{
		return left;
	}
	Tree* get_right()
	{
		return right;
	}
	Tree* get_parent()
	{
		return parent;
	}
	void add_left(Tree* tmp)
	{
		left = tmp;
	}
	void add_right(Tree* tmp)
	{
		right = tmp;
	}
	Tree* fill(int count)
	{
		if (count <= 0)
		{
			return nullptr;
		}
		char d;
		cout << "Enter a char: ";
		cin >> d;
		Tree* tmp = new Tree(d);
		tmp->add_left(fill(count / 2));
		tmp->add_right(fill(count - count / 2 - 1));
		return tmp;
	}
	void insert_right(char d)
	{
		Tree* temp = new Tree(d);
		if (right != nullptr)
		{
			right->parent = temp;
			temp->right = right;
		}
		right = temp;
		temp->parent = this;
	}
	void insert_left( char d)
	{
		Tree* temp = new Tree(d);
		if (left != nullptr)
		{
			left->parent = temp;
			temp->left = left;
		}
		left = temp;
		temp->parent = this;
	}
	void insert(char d)
	{
		Tree* cur = this;
		while (cur != nullptr)
		{
			if (cur->data!=' ')
			{
				if (cur->right != nullptr)
				{
					cur = cur->right;
				}
				else
				{
					cur->insert_right(d);
					return;
				}
			}
			else if (d < cur->data)
			{
				if (cur->left != nullptr)
				{
					cur = cur->left;
				}
				else
				{
					cur->insert_left(d);
					return;
				}
			}
			else return;
		}
	}
	void way(Tree* cur)
	{
		if ((cur->left==nullptr)&&(cur->right == nullptr))
		{
			mx++;
		}
		else
		{
			if (cur->left != nullptr) { way(cur->get_left());  }
			if (cur->right != nullptr) {way(cur->get_right()); }
		}
	}
	void searchTree(int count)
	{
		Tree* search_tree = new Tree();
		for (int i = 0; i < count; i++)
		{
			search_tree->insert(count);
		}
	}
	void print(Tree* root, int space = 0) {
		if (!root)
			return;
		enum { COUNT = 2 };
		space += COUNT;
		print(root->right, space);
		for (int i = COUNT; i < space; ++i)
			std::cout << "  ";
		std::cout << root->data << std::endl;
		print(root->left, space);
	}
	void prohod(Tree* cur)
	{
		if (cur->left != nullptr)
		{
			cff++;
			prohod(cur->get_left());
		}
	}
	
	Tree* fill2(int count, int ga, int level)
	{
		if (count <= 0)
		{
			return nullptr;
		}
		Tree* tmp = new Tree(48+ga);
		tmp->add_left(fill2((count / 2), ga-pow(2,level), level-1 ));
		tmp->add_right(fill2((count - count / 2 - 1), ga + pow(2, level), level-1));
		return tmp;
	}

};

int main()
{
	Tree* t = new Tree();
	Tree* t1 = new Tree();
	cout << "Tree Size - ";
	int count;
	cin >> count;
	cout << endl;
	Tree* balT = t->fill(count);
	balT->way(balT);
	balT->prohod(balT);
	cout << "Leaves - " << mx << endl;
	cout << "Tree height - " << cff << endl;
	int ga = pow(2,cff)-1;
	balT->print(balT);
	Tree* SearchTre = t1->fill2(count, (ga+1)/2,cff-2);
	SearchTre->print(SearchTre);
	return 0;
}
