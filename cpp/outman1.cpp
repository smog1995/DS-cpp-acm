#include <iostream>
#include <vector>
using namespace std;
class Angel {
	double  rank, damage, money, exp;
public:
	void upgrade() { rank++; damage = rank / 2; money = rank / 2; };
	Angel(double r, double d, double m, double e) :rank(r), damage(d), exp(e), money(m) {};
};
class Monster {
	double damage, hp, money, exp, rank;
	char type;
public:
	Monster(double r, double d, double h, double m, double e) :rank(r), damage(d), hp(h), money(m), exp(e), type('N') {};
	void setType(char c) { type = c; };
	char getType() { return type; };
	double getRank() { return (double)rank; };//知道等级就知道了攻击型守护神的攻击力
	void attacked(int da) { hp -= da; };
	double getDamage() { return (double)damage; };
	double getHp() { return (double)hp; };
	void display() { cout << "rank=" << (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money << endl; }
};


class NMonster :public Monster {

public:
	NMonster(double rank) :Monster(rank, rank * 2, rank * 10, rank * 10, rank * 10) { Monster::setType('N'); };
};


class AMonster :public Monster {
	Angel *AA;
public:
	AMonster(double rank) :Monster(rank, rank * 4, rank * 5, rank * 10, rank * 10) { Monster::setType('A'); AA = new Angel(rank, rank / 2, rank * 5, rank * 5); };
	~AMonster() { delete AA; };
};


class DMonster :public Monster {
	Angel *DA;
public:
	DMonster(double rank) :Monster(rank, rank, rank * 20, rank * 10, rank * 10) { Monster::setType('D'); DA = new Angel(rank, rank / 2, rank * 5, rank * 5); };
	~DMonster() { delete DA; };
};


class SMonster :public Monster {
public:
	SMonster(double rank) :Monster(rank, rank, rank * 10, rank * 20, rank * 20) { Monster::setType('S'); };
};


class Outman {
	double damage, hp, money, exp, rank;
	Angel *OA;
public:
	Outman(double r) :rank(r), hp(r * 10), damage(r * 3), money(r * 10), exp(0) { OA = new Angel(r, r / 2, 0, 0); };
	double getDamage() { return (double)damage; };
	double getHp() { return (double)hp; };
	void attacked(double da) { hp -= da / 2.0; };
	void display() { cout << "rank=" << (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << money << endl; }
	void restore();
	double getRank() { return rank; };
	void escape() { money = 0; };
	void win(double);
	void upgrade();
	~Outman() { delete OA; };
};
void Outman::win(double me)
{
	exp += me;
	money += me;
	while (exp >= 10 * rank) upgrade();
}

void Outman::restore()
{
	if (hp > 10 && (hp <= rank * 10 * 0.5))
		while (hp < rank * 10)
		{
			if (money >= 10)
			{
				money -= 10;
				hp++;
			}
			else break;
		}
}
void Outman::upgrade()
{
	exp -= 10 * (rank);
	rank++;
	OA->upgrade();
	hp = rank * 10;
	damage = rank * 3;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		bool flag = true, eflag = false;
		bool winflag[4] = { false };
		int r, mgrad[4], i = 0;
		cin >> r; Outman Or(r);
		for (int i = 0; i < 4; i++) cin >> mgrad[i];
		NMonster nm(mgrad[0]);
		AMonster am(mgrad[3]);
		DMonster dm(mgrad[2]);
		SMonster sm(mgrad[1]);
		vector<Monster> ms;
		ms.push_back(nm); ms.push_back(sm); ms.push_back(dm); ms.push_back(am);
		Or.display();
		for (int i = 0; i < 4; i++) ms[i].display();
		int damage = Or.getDamage();//奥特曼的攻击力 
		while (flag)
		{
			for (int i = 0; i < 4; i++)
			{
				if (winflag[i] == false)//该怪兽还没被打倒 
				{
					if (ms[i].getType() == 'A')
						ms[i].attacked(damage + 1);
					else if (ms[i].getType() == 'D')
						ms[i].attacked((damage + 2) / 2);
					else ms[i].attacked(damage);
				}
			}
			for (int i = 0; i < 4; i++)
				if (ms[i].getHp() > 0 && winflag[i] == false)
				{
					if (ms[i].getType() == 'A')//怪兽攻击奥特曼 
						Or.attacked(ms[i].getDamage() + ms[i].getRank() / 2);
					else Or.attacked(ms[i].getDamage());
					if (Or.getHp() >= 10)//用奥特曼生命来判断，用get方法
					{
						Or.restore();
					}
					else
					{
						cout << "lose" << endl;
						Or.escape();
						Or.display();
						eflag = true;
						flag = false;
						break;
					}
				}
				else if (winflag[i] == false)//怪兽是这一轮死的 
				{
					cout << "win" << endl;
					if (ms[i].getType() == 'S')
						Or.win(ms[i].getRank() * 20 * 2);
					else if (ms[i].getType() == 'N')
						Or.win(ms[i].getRank() * 10);
					else Or.win(ms[i].getRank() * 15);
					Or.display();
					winflag[i] = true;
				}
			bool mflag = true;//首先初始化 
			for (int i = 0; i < 4; i++) if (winflag[i] == false)  mflag = false;//四个怪兽其中有一个没死，战斗还没结束 ,flag仍等于true 
			if (mflag == true)
			{
				flag = false;
				cout << "win all" << endl;
			}
		}
	}
}

