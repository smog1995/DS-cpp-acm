#include <iostream>
#include <iomanip>
using namespace std;
class RMB
{
	int y, j, f;
	double r;
public:
	RMB(int y1, int j1, int f1) :y(y1), j(j1), f(f1) { r = y + j * 0.1 + f * 0.01; };
	double getR() { return r; };
};
class US
{
	int my, mf;
	double r;
public:
	US(int my1, int mf1) :my(my1), mf(mf1) { r = my * 6.67 + mf * 0.01*6.67; };
	double getR() { return r; };
};
class Eu
{
	int oy, of;
	double r;
public:
	Eu(int oy1, int of1) :oy(oy1), of(of1) 
	{
		r = (oy / 0.846)*6.67 + (of*0.01 / 0.846)*6.67;
	};
	double getR() { return r; };
};
class BID
{
	static double dijia;
	static int validbid;
	static double moneysum;
	static double average;
	static int topid;
	static double topmoney;
	char type;
	int id;
	RMB *r;
	US *u;
	Eu *e;
public:
	BID(char t, int id1) :type(t), id(id1),r(NULL),u(NULL),e(NULL)
	{
		if (type == 'U')
		{
			int my, mf;
			cin >> my >> mf;
			u = new US(my, mf);
			if (u->getR() >= BID::dijia)
			{
				BID::validbid++;//有效竞价数++
				BID::moneysum += u->getR();//有效竞价总值
				compare(u->getR(),id);
			}
		}
		else if (type == 'E')
		{
			int oy, of;
			cin >> oy >> of;
			e = new Eu(oy, of);
			if (e->getR() >= BID::dijia)
			{
				BID::validbid++;//有效竞价数++
				BID::moneysum += e->getR();//有效竞价总值
				compare(e->getR(),id);
			}
		}
		else if (type == 'C')
		{
			int y, j, f;
			cin >> y >> j >> f;
			r = new RMB(y, j, f);
			if (r->getR() >= BID::dijia)
			{	
				BID::validbid++;//有效竞价数++
				BID::moneysum += r->getR();//有效竞价总值
				compare(r->getR(),id);
			}	
		}
	}
	static void setDijia(double n)
	{
		BID::dijia = n;
	}
	static void Count()
	{
		BID::average = BID::moneysum / BID::validbid;
	}
	static int getValidbid() { return BID::validbid; };
	static double getAverage() { return BID::average; };
	static int getTopid() { return BID::topid; };
	static double getTopmoney() { return BID::topmoney; };
	static void compare(double n,int id)
	{
		if (n > BID::topmoney)
		{
			BID::topmoney = n;
			BID::topid = id;
		}
	}
};
double BID::dijia = 0;
int BID::validbid = 0;
double BID::average = 0;
double BID::moneysum = 0;
double BID::topmoney = 0;
int BID::topid = 0;
int main()
{
	double dj;
	cin >> dj;
	BID::setDijia(dj);
	int t;
	cin >> t;
	while (t--)
	{
		char type;
		int id;
		cin >> type>>id;
		BID b(type,id);
		
	}
	BID::Count();
	cout << "有效竞价数=" << BID::getValidbid() << endl;
	cout << "平均竞价=" <<setprecision(4)<< BID::getAverage() << endl;
	cout << "最高竞价编号=" << BID::getTopid() << endl;
	cout << "最高竞价=" << BID::getTopmoney() << endl;
}
