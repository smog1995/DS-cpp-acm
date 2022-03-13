#include <iostream>
#include <string>
using namespace std;
class User
{
	int ID;
	string name;
public:
	void setName(string s) { name = s; };
	string getName() { return name; };
	void setID(int id) { ID = id; };
	int  getID() { return ID; };
	User(User& u)
	{
		ID = u.ID;
		name = u.name + "C";
	}
	User(int _id, string _name) :ID(_id), name(_name) {};

};
class RMB
{
	int r;
public:
	RMB(int _r) :r(_r) {};
	void add(int n) { r + n; };
	int getR() { return r; };
	RMB() {};
};
class BID
{
	static int productcount;
	User *u;
	int count;
	RMB *rmb;
public:
	static void setProductcount(int c) { productcount = c; };
	int getCount() { return count; };
	string getName() { return u->getName(); };
	int getR() { return rmb->getR(); };
	int getUID() { return u->getID(); };
	BID() {};
	BID(int _id,string  _name, int _count, int r) : count(_count)
	{
		u = new User(_id, _name);
		rmb = new RMB(r);
	};
	BID(BID& b) 
	{
		u = new User(*(b.u));
		rmb = new RMB(b.getR()+500);
		count = b.count;
	};
	~BID() { delete u; delete rmb; };


};
int BID::productcount = 0;
int main()
{
	int c;
	cin >> c;
	BID::setProductcount(c);
	BID **B=new BID*[4];
	for (int i = 0; i < 4; i++)
	{
		int id1, count1, rmb1;
		string name1;
		cin >> id1 >> name1 >> count1 >> rmb1;
		B[i] = new BID(id1,name1,count1,rmb1);
	}
	
	for (int i = 0; i < 3; i++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int id;
			cin >> id;
			for (int i = 0; i < 4; i++)
			{
				if (id == B[i]->getUID())
				{
					B[i] = new BID(*B[i]);
				}
			}
		}
	}
	int end=0,sb=0;
	for (int i = 0; i < 4; i++)
		if (B[i]->getCount() <= 100 && B[i]->getR() > end)
		{
			end = B[i]->getR();
			sb = i;
		}
	int end2=0,db1=0,db2=0;
	for(int i=0;i<4;i++)
		for (int i1 = i + 1; i1 < 4; i1++)
		{
			if ((B[i]->getCount() + B[i1]->getCount()) <= 100 &&( B[i]->getR() + B[i1]->getR()) > end2)
			{
				end2 = B[i]->getR() + B[i1]->getR();
				db1 = i;
				db2 = i1;
			}
		}
	if (end > end2)
	{
		cout << "总金额=" << end<< endl;
		cout << "中标人="<<B[sb]->getName() <<  endl;
	}
	else if (end < end2)
	{
		cout << "总金额=" << end2<< endl;
		cout << "中标人="<<B[db1]->getName() << "+" << B[db2]->getName() << endl;
	}
	for (int i = 0; i < 4; i++)
		delete B[i];
	delete[] B;
}