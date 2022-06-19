
#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name;
	string postname;
	string parton;
	string birth;
	string adress;
	string rating;
};

student* line = new student[10];
student* line2 = new student[10];
student* line3 = new student[10];
student tmpWork;

void formation(int n)
{
	/*for (int i = 0; i < n; i++)
	{
		cout << "Введите Фамилию: ";
		cin >> line[i].postname;
		cout << "Введите Имя: ";
		cin >> line[i].name;
		cout << "Введите Отчество: ";
		cin >> line[i].parton;
		cout << "Введите Дату Рождения: ";
		cin >> line[i].birth;
		cout << "Введите Адрес: ";
		cin >> line[i].adress;
		cout << "Введите рейтинг: ";
		cin >> line[i].rating;
		cout << endl;
	}*/
	for (int i = 0; i < n; i++)
	{
		line[i].postname = (char)(65+rand() % 26);
		line[i].name = (char)(65 + rand() % 26);
		line[i].parton = (char)(65 + rand() % 26);
		line[i].birth = (char)(65 + rand() % 26);
		line[i].adress = (char)(65 + rand() % 26);
		line[i].rating = (char)(65 + rand() % 26);
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	string del;
	int tmp = -1;
	cout << "Количество студентов: ";
	cin >> n;
	formation(n);

	

	line[2].birth = 'G';

	for (int i = 0; i < n; i++)
	{
		cout << line[i].postname << " " << line[i].name << " " << line[i].parton << "\n";
		cout << line[i].rating << "\n";
		cout << line[i].birth << "\n";
		cout << line[i].adress << "\n";
		cout << "\n";
	}
	for (int i = 0; i < n; i++)
	{
		for (int o = i+1; o < n; o++)
		{
			if (line[o].birth == line[i].birth)
			{
				for (int j = 0; j < i; j++)
				{
					line2[j] = line[j];
				}
				for (int j = i + 1; j < o; j++)
				{
					line2[j-1] = line[j];
				}
				for (int j = o + 1; j < n; j++)
				{
					line2[j - 2] = line[j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << line2[i].postname << " " << line2[i].name << " " << line2[i].parton << "\n";
		cout << line2[i].rating << "\n";
		cout << line2[i].birth << "\n";
		cout << line2[i].adress << "\n";
		cout << "\n";
	}
	
	cout << endl;


	cout << "Фамилия, перед которой добавить: ";
	cin >> del;
	int i = 0;
	n--;
	
	for (i = 0; i < n; i++) {
		if (line2[i].postname == del)
		{
				
			for (int j = n; j > i-1; j--)
			{
				line2[j+1] = line2[j];
			}

			line2[i].postname = "TEST";
			line2[i].name = "TEST";
			line2[i].parton = "TEST";
			line2[i].birth = "TEST";
			line2[i].adress = "TEST";
			line2[i].rating = "TEST";
			del = "sdadsadasdasdasdasdas";
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << line2[i].postname << " " << line2[i].name << " " << line2[i].parton << "\n";
		cout << line2[i].rating << "\n";
		cout << line2[i].birth << "\n";
		cout << line2[i].adress << "\n";
		cout << "\n";
	}
	
	delete[]line;
	delete[]line2;
	delete[]line3;
	return 0;
}
