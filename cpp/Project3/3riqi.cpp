#include <iostream>

using namespace std;
bool isLeap(int y)
{
	return (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
}

class Date {
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();

};
Date::Date(int y, int m, int d):year(y),month(m),day(d)
{
	
}
Date::Date() {}
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
void Date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;

}
void Date::addOneDay()
{
	int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap(year)) mon[2] = 29;
	day += 1;
	if (day > mon[month])
	{
		day = 1;
		month++;
		if (month > 12) year++;
	}
}
void Date::print()
{
	cout << "Today is " << year << "/";
	if (month < 10)cout << "0";
	cout << month << "/";
	if (day < 10)cout << "0";
	cout << day << endl;
	addOneDay();
	cout << "Tomorrow is " << year << "/";
	if (month < 10)cout << "0";
	cout << month << "/";
	if (day < 10)cout << "0";
	cout << day << endl;
}
int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int y, m, d;
		cin >> y >> m >> d;
		Date *D;
		if (i % 2 == 0)
			D = new Date(y, m, d);
		else {
			D = new Date();
			D->setDate(y, m, d);
		}
		D->print();
		
	}
}