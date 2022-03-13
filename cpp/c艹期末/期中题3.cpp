#include <iostream>
using namespace std;
class Account
{
	int balance;
	int number;
	char type;
	double rate;
public:
	Account(int num, char t, int bal) :number(num), balance(bal), type(t),rate(0.005){};
	Account(Account &a)
	{
		balance = a.balance; 
		type = a.type;
		rate = 0.015;
		number = a.number+50000000;
	}
	void jixi()
	{
		balance += balance * rate;
		cout << "Account" << number << "--sum=" << balance << endl;
	}
	void select()
	{
		cout << "Account=" << number;
			if (type == 'P')
				cout << "--Person";
			else cout << "--Enterprise";
			cout<<"--sum=" << balance << "--rate=" << rate << endl;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int num, bal;
		char t;
		cin >> num >> t >> bal;
		Account a1(num, t, bal);
		Account a2(a1);
		char do1,do2;
		cin >> do1>>do2;
		if (do1 == 'P')
			a1.select();
		else if(do1=='C') a1.jixi();
		if (do2 == 'P')
			a2.select();
		else if(do2=='C') a2.jixi();
	}
}