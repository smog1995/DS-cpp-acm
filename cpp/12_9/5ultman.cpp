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
	void display() { cout <<"����״̬(rank="<< (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money << ")" << endl; }
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
	stream << "������״̬(rank=" << u.getRank() << " hp=" << u.getHp() <<" damage="<<u.getDamage()<< " exp=" << u.getExp() << " money=" << u.getMoney()<<")"<<endl;
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
	if (m.getRank() < rank)//���޵ȼ����ڰ������ȼ�
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

	int ograd;   cin >> ograd;//����������ĵȼ�ֵ�����õȼ�ֵ������һ������������

	Ultraman uobj(ograd);

	cout << uobj;  //��ʾ�����������ʼ״̬



	int t;   cin >> t;//������Դ���

	while (t--) {

		char c = 0;

		while (1) {

			cin >> c;//����Ҫʹ�õ�ħ������G������³�˫��B����������У�X�������Ǵ󷨣�Y������Ե���

			if (c == 'G') {

				cout << "****���³�˫****" << endl;

				++uobj;

				cout << "****�ɹ�����****" << endl;

				break;

			}

			else if (c == 'B') {

				cout << "****��������****" << endl;

				--uobj;

				cout << "****���Ҽ���****" << endl;

				break;

			}

			else if (c == 'X') {

				int r; cin >> r;//������޵ĵȼ�ֵ�����õȼ�ֵ������һ�����޶�����ʾ�����ʼ״̬��

				NMonster mobj(r);

				mobj.display();

				cout << "****���Ǵ�****" << endl;

				if (uobj < mobj)cout << "****�󹦸��****" << endl;

				else cout << "****��δ�ɹ�****" << endl;

				break;

			}

			else if (c == 'Y') {

				int r; cin >> r;//������޵ĵȼ�ֵ�����õȼ�ֵ������һ�����޶�����ʾ�����ʼ״̬��

				NMonster mobj(r);

				mobj.display();

				cout << "****��Ե���****" << endl;

				if (uobj == mobj)cout << "****��Ե�з�****" << endl;

				else cout << "****��Ե�޷�****" << endl;

				break;

			}

			else cout << "����������ħ��������" << endl;

		}

		cout << uobj;

	}

	return 0;

}
