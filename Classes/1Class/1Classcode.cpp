#include <iostream>
using namespace std;

class value
{
private:
	float A;
	float B;
public:
	void set(float A, float B)
	{
		this->A = A;
		this->B = B;
	}
	float function()
	{
		float res = 0.0;
		float x=0.0;
		cout << "Enter X" << endl;
		cin >> x;
		res = A * x + B;
		return res;
	}
};

int main()
{
	value a;
	float A,B;
	cout << "Enter the coefficient A" << endl;
	cin >> A;
	cout << "Enter the coefficient B" << endl;
	cin >> B;
	a.set(A, B);
	cout << "Result: " << a.function();
	return 0;
}
