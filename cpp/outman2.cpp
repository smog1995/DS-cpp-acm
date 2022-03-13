#include <iostream>
#include <vector>
using namespace std;
class Angel {
	double rank, damage, money, exp;
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
	double getRank() { return rank; };//知道等级就知道了攻击型守护神的攻击力
	void attacked(int da) { hp -= da; };
	double getDamage() { return damage; };
	double getHp() { return hp; };
	void display() { cout << "rank=" << (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money << ")"<<endl; }
};
class NMonster :public Monster {

public:
	NMonster(double rank) :Monster(rank, rank * 2, rank * 10, rank * 10, rank * 10) { Monster::setType('N'); };
	
};
class BOSS :public Monster
{
private: int count;
public:
	double XP() { return Monster::getDamage() * 3; };
	BOSS() :Monster(10, 50, 300, 1001, 1000) {};
	int getcount() { return count; }
	void attacked1(double da);

};
void BOSS::attacked1(double da)
{
	count++;
	Monster::attacked(da);
}
class Outman {
	double damage, hp, money, exp, rank;
	Angel *OA;
public:
	Outman(double r) :rank(r), hp(r * 10), damage(r * 3), money(r * 10), exp(0) { OA = new Angel(r, r / 2, 0, 0); };
	double getDamage() { return damage; };
	double getHp() { return hp; };
	void attacked(double da) { hp -= da; if (hp < 0) hp = 0; };
	void attacked1(double da) { attacked(da / 2); };
	void display() { cout << "奥特曼状态(" << "rank=" << (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money <<")"<< endl; };
	void restore();
	double getRank() { return rank; };
	void escape() { money = 0; };
	void win(double);
	void winboss(double);
	void upgrade();
	~Outman() { delete OA; };
};
void Outman::win(double me)
{
	exp += me;
	money += me;
	while (exp >= 10 * rank) upgrade();
}
void Outman::winboss(double m)
{
	money += 1;
	win(m);
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
	while (t--)
	{
		int orank;
		bool flag = true, eflag = false, cflag = true;//创建怪兽：cflag 
		cin >> orank;
		Outman Or(orank);
		int num, mrank;
		cin >> num >> mrank;
		NMonster m(mrank);
		Or.display();
		while (flag&&num)
		{
			if (cflag)
			{
				m = NMonster(mrank);
				cflag = false;
			}
			m.attacked(Or.getDamage());
			if (m.getHp() > 0)
			{
				Or.attacked(m.getDamage());
				if (Or.getHp() > 10)//用奥特曼生命来判断，用get方法
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
				}
				//cout << "怪兽：";
				//m.display();
			//	cout << "奥特曼：";

			}
			else
			{
				cout << "win" << endl;
				cflag = true;
				Or.win(m.getRank() * 10);
				num--;
			}

		}
		if (eflag == false && flag == true)
		{
			BOSS boss;
			Or.display();
			while (flag)
			{
				boss.attacked1(Or.getDamage());
				if (boss.getHp() > 0)
				{
					if (boss.getcount() % 5 == 0) Or.attacked(boss.getDamage() * 3);
					else Or.attacked1(boss.getDamage());
					if (Or.getHp() > 10)//用奥特曼生命来判断，用get方法
					{
						Or.restore();
					}
					else
					{
						cout << "lose" << endl;
						Or.escape();
						eflag = true;
						flag = false;
						Or.display();
						break;
					}
				}
				else
				{
					cout << "win Boss" << endl;
					Or.winboss(1000);
					flag = false;
					Or.display();
				}
			}

		}
	}
}