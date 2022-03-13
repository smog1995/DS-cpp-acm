#include <iostream>
using namespace std;
class Monster {
	int damage, hp, money, exp, rank;
public:
	Monster(int r, int d, int h, int m, int e) :rank(r), damage(d), hp(h), money(m), exp(e) {};
	int getRank() { return rank; };
	int getDamage() { return damage; };
	int getHp() { return hp; };
	int getExp() { return exp; };
	int getMoney() { return money; };
	void display() { cout <<"怪兽状态(rank="<< (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money << ")" << endl; }
};
class NMonster :public Monster {

public:
	NMonster(int rank) :Monster(rank, rank * 2, rank * 20, rank * 10, rank * 10) {};
};
class Ultraman
{
	int damage, hp, money, exp, rank;
public:
	Ultraman(int r) :rank(r), hp(r * 10), damage(r * 3), money(r * 10), exp(0) {};
	int getDamage() { return damage; };
	int getRank() { return rank; };
	int getExp() { return exp; };
	int getMoney() { return money; };
	int getHp() { return hp; };
	Ultraman& operator++();
	Ultraman operator++(int);
	Ultraman& operator--();
	Ultraman operator--(int);
	bool operator<(Monster);
	bool operator==(Monster);
	friend ostream& operator<<(ostream&,Ultraman&);
};
ostream& operator<<(ostream& stream,Ultraman& u)
{
	stream << "奥特曼状态(rank=" << u.getRank() << " hp=" << u.getHp() <<" damage="<<u.getDamage()<< " exp=" << u.getExp() << " money=" << u.getMoney()<<")"<<endl;
	return stream;
}
bool Ultraman::operator==(Monster m)
{
	if (m.getRank() == rank)
	{
		hp += m.getHp();
		exp += m.getExp();
		damage += m.getDamage();
		money += m.getMoney();
		return true;
	}
	return false;
}
Ultraman& Ultraman::operator++()
{
	rank *= 2;
	damage = rank * 3;
	hp = rank * 10;
	exp *= 2;
	money *= 2;
	return *this;
}
Ultraman Ultraman::operator++(int)
{
	Ultraman u=*this;
	rank *= 2;
	damage = rank * 3;
	hp = rank * 10;
	exp *= 2;
	money *= 2;
	return u;
}
Ultraman& Ultraman::operator--()
{
	hp /= 2;
	damage /= 2;
	money /= 2;
	exp /= 2;
	return *this;
}
Ultraman Ultraman::operator--(int)
{
	Ultraman u = *this;
	hp /= 2;
	damage /= 2;
	money /= 2;
	exp /= 2;
	return u;
}
bool Ultraman::operator<(Monster m)
{
	if (m.getRank() < rank)//怪兽等级低于奥特曼等级
	{
		hp += m.getHp() / 2;
		money += m.getMoney() / 2;
		exp += m.getExp() / 2;
		damage += m.getDamage() / 2;
		return true;
	}
	return false;
}

int main() {

	int ograd;   cin >> ograd;//输入奥特曼的等级值，利用等级值，声明一个奥特曼对象。

	Ultraman uobj(ograd);

	cout << uobj;  //显示奥特曼对象初始状态



	int t;   cin >> t;//输入测试次数

	while (t--) {

		char c = 0;

		while (1) {

			cin >> c;//输入要使用的魔法袋，G代表好事成双，B代表祸不单行，X代表吸星大法，Y代表有缘相会

			if (c == 'G') {

				cout << "****好事成双****" << endl;

				++uobj;

				cout << "****成功翻倍****" << endl;

				break;

			}

			else if (c == 'B') {

				cout << "****祸不单行****" << endl;

				--uobj;

				cout << "****不幸减半****" << endl;

				break;

			}

			else if (c == 'X') {

				int r; cin >> r;//输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。

				NMonster mobj(r);

				mobj.display();

				cout << "****吸星大法****" << endl;

				if (uobj < mobj)cout << "****大功告成****" << endl;

				else cout << "****尚未成功****" << endl;

				break;

			}

			else if (c == 'Y') {

				int r; cin >> r;//输入怪兽的等级值，利用等级值，声明一个怪兽对象并显示对象初始状态。

				NMonster mobj(r);

				mobj.display();

				cout << "****有缘相会****" << endl;

				if (uobj == mobj)cout << "****有缘有分****" << endl;

				else cout << "****无缘无分****" << endl;

				break;

			}

			else cout << "请重新输入魔法袋类型" << endl;

		}

		cout << uobj;

	}

	return 0;

}
