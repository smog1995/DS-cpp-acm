#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Employee
{
	string name, status;
	int level, year;
public:
	Employee() {};
	Employee(string n, string s, int l, int y);
	double salary();
	int getLevel() { return level; };
	int getYear() { return year; };
	void display();
};
void Employee::display()
{

	cout << name << ":" << status << "," << "Salary:"<<salary()<<endl;
}
double Employee::salary()
{
	if (status == "Employee")
	return 1000 + 500 * level + 50 * year;
	else if(status == "Teamleader")
		return 3000 + 800 * Employee::getLevel() + 100 * Employee::getYear();
	return 5000 + 1000 * (Employee::getLevel() + Employee::getYear());
}
Employee::Employee(string n, string s, int l, int y)
{
	if(s != "Employee" && s != "Teamleader" && s != "Manager") cout<< "error position." << endl;
	else if (y < 0 || l < 0) cout << "error grade or year." << endl;
	else
	{
		status = s;
		name = n;
		level = l;
		year = y;
		display();
	}

}
class Manager :public Employee
{
public:
	Manager(string n, string s, int l, int y) :Employee(n, s, l, y) {};
};
class Teamleader :public Employee
{
public:
	Teamleader(string n, string s, int l, int y) :Employee(n, s, l, y) {};
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int l, y;
		string name, stat;
			cin >> name >> stat >> l >> y;
			Employee *e;
		if (stat == "Teamleader")
			e = new Teamleader(name, stat, l, y);
		else if (stat == "Manager")
			e = new Manager(name, stat, l, y);
		else
			e = new Employee(name, stat, l, y);
	}

}
