#include <iostream>
using namespace std;
class CLOCK1 {
	int h, m, s;
public:
	CLOCK1(int h1, int m1, int s1) :h(h1), m(m1), s(s1) {};
	friend CLOCK1 operator++(CLOCK1& c);
	friend CLOCK1 operator--(CLOCK1& c);
	void show();
};
void CLOCK1::show()
{
	cout << h << ":" << m << ":" << s << endl;
}
CLOCK1 operator++(CLOCK1& c)
{
	c.s++;
	if (c.s / 60)
	{
		c.m++;
		c.s = 0;
	}
	if (c.m / 60)
	{
		c.h++;
		c.m = 0;
	}
	if (c.h / 12) c.h = 0;
	return c;
}
CLOCK1 operator--(CLOCK1& c)
{
	c.s--;
	if (c.s < 0)
	{
		c.m--;
		c.s = 59;
	}
	if (c.m < 0)
	{
		c.h--;
		c.m = 59;
	}
	if (c.h < 0) c.h = 11;
	return c;
}
int main()
{
	int h, m, s;
	cin >> h >> m >> s;
	int t;
	cin >> t;
	CLOCK1 c(h, m, s);
	while (t--)
	{
		int x;
		cin >> x;
		if (x > 0)
		{
			for (int i = 0; i < x; i++)
				++c;
		}
		else
		{
			for(int i = 0; i < -x; i++)
				--c;
		}
		c.show();
	}
}