#include <iostream>
#include <string>
using namespace std;
class BaseAccount
{
	string name,account;
	int balance;
	public:
		BaseAccount(string n,string acc,int bal):name(n),account(acc),balance(bal){};
		virtual void withdraw(int m){if(m>balance) cout<<"insufficient"<<endl;else balance-=m;};
		virtual void deposit(int m){balance+=m;};
		int getBalance(){return balance;};
		virtual void display(){cout<<name<<" "<<account<<" Balance:"<<balance;};
};
class BasePlus:public BaseAccount
{
	int limit,limit_top;
	public:
		BasePlus(string n,string acc,int bal):BaseAccount(n,acc,bal),limit(0),limit_top(5000){};
		void withdraw(int m);
		void deposit(int m);
		void display();
};
void BasePlus::display()
{
	BaseAccount::display();
	cout<<" limit_sum:"<<limit;
}
void BasePlus::withdraw(int m)
{
	if(m<getBalance()) BaseAccount::withdraw(m);
	else
	{
		if(m<(getBalance()+limit_top))
		{
			int shengyu=m-getBalance();
			BaseAccount::withdraw(getBalance());
			limit+=shengyu;
		}
		else cout<<"insufficient"<<endl;
	}
}
void BasePlus::deposit(int m)
{
	if(m<limit) limit-=m;
	else 
	{
		int shengyu=m-limit;
		limit=0;
		BaseAccount::deposit(shengyu);
	}	
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string n,a;
		int b;
		cin>>n>>a>>b;
		BaseAccount *ba; 
		if(a[1]=='A')
		ba=new BaseAccount(n,a,b);
		else ba=new BasePlus(n,a,b);
		int d1,w1,d2,w2;
		cin>>d1>>w1>>d2>>w2;
		ba->deposit(d1);
		ba->withdraw(w1);
		ba->deposit(d2);
		ba->withdraw(w2);
		ba->display();
		cout<<endl;
		delete ba;
	 } 
}
