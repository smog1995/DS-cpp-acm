#include <iostream>
using namespace std;
class jiadian
{
protected:
	int number, P;
public:
	jiadian() {};
	jiadian(int n, int p) :number(n), P(p) {};
	void print()
	{
		cout << "���" << number << "--����" << P << "W" << endl;
	}

};
class Elefan:virtual public jiadian
{
protected:
	int direct, powlevel;
public:
	Elefan(int n, int p, int d, int pl) :jiadian(n, p), direct(d), powlevel(pl) {};
	void directctrl(int n)
	{
		direct = n;
	}
	void powlevelctrl(int n)
	{
		powlevel = n;
	}
	void print()
	{
		if (direct == 1) cout << "��ת����";
		else if (direct == 0) cout << "���򴵷�";
		cout << "--����" << powlevel << "��";
		cout << endl;
	}
};
class Elejiashiqi:virtual public jiadian
{
protected:
	double realV, maxV;
public:
	Elejiashiqi() {};
	void setRealV(double rv) { realV = rv; };
	void setMaxV(double mv) { maxV = mv; };
	Elejiashiqi(int n, int p, double rv, double mv) :jiadian(n, p), realV(rv), maxV(mv) {};
	int Warn()
	{
		if (realV >= maxV * 0.5) return 1;
		else if (realV >= maxV * 0.1&&realV < maxV*0.5) return 2;
		else return 3;
	}
	void print()
	{
		cout << "ʵ��ˮ����" << realV << "��--ˮ��";
		if (Warn() == 1)cout << "����";
		else if (Warn() == 2)cout << "ƫ��";
		else cout << "����";
		cout << endl;
	}
};
class Jiashifan:public Elefan, public Elejiashiqi
{
	int level;
public:
	Jiashifan(int n, int p, int dir, int pl, double rv, double mv) :Elefan(n, p, dir, pl),Elejiashiqi(n,p,rv,mv) {};
	void setLevel(int n)
	{
		level = n;
		if (level == 0);
		else if (level == 1)
		{
			directctrl(0);
			powlevelctrl(1);
		}
		else if (level == 2)
		{
			directctrl(1);
			powlevelctrl(2);
		}
		else if (level == 3)
		{
			directctrl(1);
			powlevelctrl(3);
		}
		
	};
	void print()
	{
		cout << "��ʪ����--��λ" << level << endl;
		jiadian::print();
		Elefan::print();
		Elejiashiqi::print();

	};
};
int main()
{
	int n, p, direct, powl, rv, mv;
	int level;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> p >> direct >> powl >> rv >> mv;
		cin >> level;
		Jiashifan j(n, p, direct, powl, rv, mv);
		j.setLevel(level);
		cin >> level;
		j.setLevel(level);
		j.print();
	}
}
