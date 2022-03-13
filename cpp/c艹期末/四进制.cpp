#include<iostream>
#include <cmath>
using namespace std;
int to4(int d)
{
	int re = 0, a = 0;
	for (int i = 0; d != 0; i++)
	{
		a = d % 4;
		re += a * pow(10, i);
		d /= 4;
	}
	return re;
}
int to10(int f)
{
	int re = 0, a = 0;
	for (int i = 0; f != 0; i++)
	{
		a = f % 10;
		re += a * pow(4, i);
		f /= 10;
	}
	return re;
}
class Four
{
	int f;
public:
	Four operator+( Four&);
	Four(int f1) :f(f1) {};
	void getFD() { cout << f << endl; }
};
Four Four::operator+( Four& f2)
{
	return Four(to4(to10(f) + to10(f2.f)));
	
}

int main()
{
	int t, d;
	cin >> t >> d;
	Four f(d);
	t--;
	while (t--)
	{
		cin >> d;
		Four f1(d);
		f = f + f1;
	}
	f.getFD();
}