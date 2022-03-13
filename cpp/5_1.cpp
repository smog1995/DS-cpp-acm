#include <iostream>
#include <string>
#include<string.h>
using namespace std;
bool isLeapYear(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return true;
	return false;
}
int Yallday(int y)
{
	if (isLeapYear(y)) return 366;
	return 365;
}

class Student
{
	int y, m, d;
public:
	string name;
	Student() {	};
	Student(string n, int y1, int m1, int d1) :y(y1), m(m1), d(d1), name(n) {}
	int operator-(Student&);
};
int accountday(int y1, int m1, int d1)
{//从该日期到1970-1-1
	int day1=0;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int year = 1970; year < y1; year++)
		day1 += Yallday(year);
	for (int i = 1; i < m1; i++)
	{
		if (i == 2) if (isLeapYear(y1)) day1 += 29;
		else day1 += a[i];
	}
	day1 += d1;
	return day1;
}
int Student::operator-(Student& s)
{
	int y1, y2, m1, m2, d1, d2;
		y1 = s.y; m1 = s.m; d1 = s.d;
		y2 = y; m2 = m; d2 = d;
	int day1=accountday(y1, m1, d1),day2=accountday(y2,m2,d2);
	return abs(day1 - day2);
}

int main()
{
	int t, i = 0;
	cin >> t;
	int t1 = t;
	int **a, maxd = 0;
	a = new int*[t];
	for (int i = 0; i < t; i++)
		a[i] = new int[t];
	for (int i = 0; i < t; i++)
		for (int i1 = 0; i1 < t; i1++)
			a[i][i1] = 0;
	Student *s;
	s = new Student[t];

	while (t1--)
	{
		int y, m, d;
		string n;
		cin >> n >> y >> m >> d;
		s[i++] = Student(n, y, m, d);
	}

	for (int i = 0; i < t; i++)
	{
		for (int i1 = i + 1; i1 < t; i1++)
		{
			a[i][i1] = s[i] - s[i1];
			if (maxd < a[i][i1]) maxd = a[i][i1];
		}
	}
	for (int i = 0; i < t; i++)
		for (int i1 = i + 1; i1 < t; i1++)
		{
			if (maxd == a[i][i1])

			{
				cout << s[i].name << "和" << s[i1].name << "年龄相差最大，为" << maxd << "天。" << endl;
				break;
			}
		}

}