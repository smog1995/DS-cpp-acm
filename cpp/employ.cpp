#include <iostream>
#include <string>
#include <cstdio> 

using namespace std;
class Employee
{
	string name, status;
	unsigned int level, year;
public:
	Employee() {};
	Employee(string n, string s, int l, int y);
	virtual double salary();
	int getLevel() { return level; };
	int getYear() { return year; };
	void display();
};
void Employee::display()
{
	cout << name << ":" << status << "," << "Salary:" << salary();
}
double Employee::salary()
{
	return 1000 + 500 * level + 50 * year;
}
Employee::Employee(string n, string s, int l, int y)
{
	int lflag = 1, yflag = 1, sflag = 1;
	if (s == "Employee") status = "Employee";
	else if (s == "Teamleader") status = "Teamleader";
	else if (s == "Manager")status = "Manager";
	else if (s != "Employee" && s != "Teamleader" && s != "Manager")
	{
		sflag = 1;
	}
	if (l < 0)
	{
		lflag = 1;
	}
	else level = l;
	if (y < 0)
	{
		yflag = 1;
	}
	else year = y;
	if ((lflag && sflag) || (yflag && sflag)) cout << "error position." << endl;
	else if (lflag || yflag) cout << "error grade or year.";
	else if (sflag) cout << "error position." << endl;
}
class Manager :public Employee
{
public:
	Manager(string n, string s, int l, int y) :Employee(n, s, l, y) {};
	double salary();
};
double Manager::salary()
{
	return 5000 + 1000 * (Employee::getLevel() + Employee::getYear());
}
class Teamleader :public Employee
{
public:
	Teamleader(string n, string s, int l, int y) :Employee(n, s, l, y) {};
	double salary();
};
double Teamleader::salary()
{
	return 3000 + 800 * Employee::getLevel() + 100 * Employee::getYear();
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string name, stat;
		int l, y;
		cin >> name >> stat >> l >> y;
		Employee *e = new Employee();
		if (stat == "Employee")
			e = new Employee(name, stat, l, y);
		else if (stat == "Teamleader")
			e = new Teamleader(name, stat, l, y);
		else if (stat == "Manager")
			e = new Manager(name, stat, l, y);
		e->display();
	}
}
