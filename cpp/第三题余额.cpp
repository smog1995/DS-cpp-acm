#include <iostream>
#include <cstring>
using namespace std;
class CPeople {
	char id[20];
	char name[20];
public:
	CPeople() {};
	int compareid(char* id1)
	{
		if (!strcmp(id, id1)) return 1;
		return 0;
	};
	void setId(char* id1)
	{
		strcpy(id, id1);
		id[strlen(id1) + 1] = '\0';
	};
	void setName(char *n)
	{
		strcpy(name, n);
		name[strlen(n) + 1] = '\0';
	};
	void print() { cout << "Name: " << name << " " << "ID: " << id << endl; };

};
class CInternetUser :virtual public CPeople
{
	char password[20];
public:
	CInternetUser() {};
	void registerUser(char *_id, char *_name, char *_password)
	{
		setId(_id);
		setName(_name);
		strcpy(password,  _password);
		password[strlen(_password) + 1] = '\0';
	};
	int login(char *_id, char *_pass)
	{
		if (compareid(_id) == 0) return 0;
		if (strcmp(_pass, password)) return 0;//返回0是相等
		return 1;
	};
	void print(){CPeople::print();};


};
class CBankCustomer :virtual public CPeople
{
	double balance;
public:
	CBankCustomer() :balance(0), CPeople() {};
	void openAccount(char *_id, char *_name);
	double getBalance() { return balance; }
	void deposit(double m) { balance += m; };
	int withdraw(double m);

};
void CBankCustomer::openAccount(char *_id, char *_name)
{
	CPeople::setId(_id);
	CPeople::setName(_name);
};
int CBankCustomer::withdraw(double m)
{
	if (balance >= m)
	{
		balance -= m;
		return 1;
	}
	return 0;
};

class CInternetBankCustomer :public CInternetUser, public CBankCustomer
{
	double Ibalance, Iybalance, tdincome, ints, ytints;
public:
	CInternetBankCustomer() :Ibalance(0), Iybalance(0), ints(0), tdincome(0), ytints(0) {};
	int withdraw(double m);
	int deposit(double m);
	void setYIbalance() { Iybalance = Ibalance; };
	void setInterest(double interest) { ytints = ints; ints = interest / 10000; };
	//void setYtints() { ytints = y; };
	void calculateProfit();
	void print();
};
void CInternetBankCustomer::calculateProfit()
{
	//if (ints == 0) tdincome = ytints *Iybalance;
	 tdincome = ytints * Iybalance;
	Ibalance += tdincome;
}
void CInternetBankCustomer::print()
{
	CInternetUser::print();
	cout << "Bank balance: " << CBankCustomer::getBalance() <<endl;
	cout << "Internet bank balance: " << Ibalance << endl;
	cout << endl;
}
int CInternetBankCustomer::deposit(double m)
{
	if (CBankCustomer::withdraw(m))
	{
		Ibalance += m;
		return 1;
	}
	return 0;//存款失败(从银行存入账户返回0)
}
int CInternetBankCustomer::withdraw(double m)
{
	if (Ibalance >= m)
	{
		Ibalance -= m;
		//Iybalance -= m;//当日取款部分无收益
		CBankCustomer::deposit(m);
		return 1;
	}
	return 0;//从账户存入银行失败返回0
}
int main()
{
	int t, no_of_days, i;
	char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
	double money, interest;
	char op_code;
	//输入测试案例数t
	cin >> t;
	while (t--)
	{
		//输入互联网用户注册时的用户名,id,登陆密码
		cin >> i_xm >> i_id >> i_mm;
		//输入银行开户用户名,id
		cin >> b_xm >> b_id;
		//输入互联网用户登陆时的id,登陆密码
		cin >> ib_id >> ib_mm;
		CInternetBankCustomer ib_user;
		ib_user.registerUser(i_id, i_xm, i_mm);
		ib_user.openAccount(b_id, b_xm);
		if (ib_user.login(ib_id, ib_mm) == 0||(strcmp(i_id,b_id))!=0||(strcmp(i_xm,b_xm))!=0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
		{
			cout << "Password or ID incorrect" << endl;
			continue;
		}
		//输入天数
		cin >> no_of_days;
		for (i = 0; i < no_of_days; i++)
		{
			//输入操作代码, 金额, 当日万元收益
			cin >> op_code >> money >> interest;
			ib_user.setYIbalance();
			switch (op_code)
			{
			case 'S':  //从银行向互联网金融帐户存入
			case 's':
				if (ib_user.deposit(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				break;
			case 'T':  //从互联网金融转入银行帐户
			case 't':
				if (ib_user.withdraw(money) == 0)
				{
					cout << "Internet bank balance not enough" << endl;
					continue;
				}
				break;
			case 'D':  //直接向银行帐户存款
			case 'd':
			{
				ib_user.CBankCustomer::deposit(money);
			}

				break;
			case 'W':  //直接从银行帐户取款
			case 'w':
					if (ib_user.CBankCustomer::withdraw(money) == 0)
					{
						cout << "Bank balance not enough" << endl;
						continue;
					}
				break;
			default:
				cout << "Illegal input" << endl;
				continue;
			}
			ib_user.setInterest(interest);
			ib_user.calculateProfit();
			//输出用户名,id 
			//输出银行余额
			//输出互联网金融账户余额
			ib_user.print();
		}
	}
	
	return 0;
}
