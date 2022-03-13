#include <iostream>
#include <string>
using namespace std;
 class Account
 {
 	public:
 		Account(string accno,string name,float balance);
 		~Account();
 		void Deposit(float amount);
 		void Withdraw(float amount);
 		float Getbalance();
 		void Show();
 		static int GetCount();
 		static float GetInterestRate();
 		static float SetInterestRate(float);
 		friend void Update(Account &a);
 		static float GetAllbal(){return allbal;};
 		void AddAllbal(){Account::allbal+=_balance;};
 	private:
 		static int count;
 		static float allbal;
 		static float InterestRate;
 		string _accno,_accname;
 		float _balance;
};
float Account::allbal=0;
int Account::count=0;
float Account::InterestRate=0;
Account::Account(string accno,string name,float balance)
{
	_accno=accno;
	_accname=name;
	_balance=balance;
}
void Account::Deposit(float amount)
{
	_balance+=amount;
}
void Account::Withdraw(float amount)
{
	if(amount>_balance) cout<<"error!"<<endl;
	else 
	{
		_balance-=amount;
	}
}
float Account::Getbalance()
{
	return _balance;
}
float Account::GetInterestRate()
{
	return InterestRate;
}
float Account::SetInterestRate(float in)
{
	InterestRate=in;
}
int Account::GetCount()
{
	return count;
}
void Account::Show()
{
	cout<<_accno<<" "<<_accname<<" "<<_balance<<" ";
}
void Update(Account& a)
{
	a._balance+=a._balance*Account::InterestRate;
}
int main()
{
	float interest;
	cin>>interest;
	Account::SetInterestRate(interest);
	Account **as;
	int n;
	cin>>n;
	as=new Account*[n];
	for(int i=0;i<n;i++)
	{
		string acc;
		float bal;
		string name;
		cin>>acc>>name>>bal;
		as[i]=new Account(acc,name,bal);
		int withd,depo;
		cin>>depo>>withd;
		as[i]->Deposit(depo);
		as[i]->Show();
		Update(*as[i]);
		cout<<as[i]->Getbalance()<<" ";
		as[i]->Withdraw(withd);
		cout<<as[i]->Getbalance()<<endl;
		as[i]->AddAllbal();
	}
	cout<<Account::GetAllbal()<<endl;
	delete[] as;
}
