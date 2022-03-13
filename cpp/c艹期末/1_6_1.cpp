#include <iostream>
#include <string>
using namespace std;

class Member

{
protected:
	int jifen, id;
	string name;
public:
	Member(int id1, string& n, int jf) :id(id1), name(n), jifen(jf) {};
	virtual void  Add(int y)
	{
		jifen += y;
	};
	int virtual Exchange(int jf);
	virtual void print();
};


int Member::Exchange(int jf)
{
	int yuan=jf/100;
	jifen -= yuan * 100;
	return yuan;
	//未考虑积分不足的情况
}

void Member::print()
{
	cout << "普通会员" << id << "--" << name << "--" << jifen << endl;
}
class VIP :public Member
{
	int addbili, exbili;
public:
	VIP(int id1, string& n, int jf, int addbili1, int exbili1) :Member(id1, n, jf),addbili(addbili1),exbili(exbili1) {};
	void Add(int y)
	{
		jifen += y * addbili;
	};
	int Exchange(int jf);
	void print();
};
int VIP::Exchange(int jf)
{
	int yuan = jf / exbili;
	jifen -= yuan * exbili;
	return yuan;
}
void VIP::print()
{
	cout << "贵宾会员" << id << "--" << name << "--" << jifen << endl;
}
int main()
{
	Member *m;
	int id, jf;
	string name;
	cin >> id >> name >> jf;
	m = new Member(id, name, jf);
	int consume, exc;
	cin >> consume >> exc;
	m->Add(consume);
	m->Exchange(exc);
	m->print();
	int addb, excb;
	cin >>id>>name>>jf>> addb >> excb;
	m = new VIP(id, name, jf,addb,excb);
	cin >> consume >> exc;
	m->Add(consume);
	m->Exchange(exc);
	m->print();
	delete m;
}