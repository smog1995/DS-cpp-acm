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
	int comparename(char *name1)
	{
		if (!strcmp(name, name1)) return 1;
		return 0;
	}
	void setId(char* id1)
	{
		strcpy_s(id, strlen(id1)+1,id1);
		id[strlen(id1) + 1] = '\0';
	};
	void setName(char *n)
	{
		strcpy_s(name, strlen(n)+1, n);
		name[strlen(n) + 1] = '\0';
	};
	void getId(char* _id)
	{
		strcpy_s(_id, strlen(id) + 1, id);
		_id[strlen(id)] = '\0';
	};
	void getName(char* _name)
	{
		strcpy_s(_name, strlen(name) + 1, name);
		_name[strlen(name)] = '\0';
	}
	void print() { cout << "Name: " << name << " " << "ID: " << id << endl; };

};
class CInternetUser :public CPeople
{
	char password[20];
public:
	CInternetUser() {};
	void registerUser(char *_id, char *_name, char *_password)
	{
		setId(_id);
		setName(_name);
		strcpy_s(password, strlen(_password)+1, _password);
		password[strlen(_password) + 1] = '\0';
	};
	int login(char *_id, char *_pass)
	{
		if (compareid(_id) == 0) return 0;
		if (strcmp(_pass, password)) return 0;//����0�����
		return 1;
	};



};
class CBankCustomer :public CPeople
{
	double balance;
public:
	CBankCustomer() :balance(0), CPeople() {};
	void openAccount(char *_id, char *_name);
	double getBalance() { return balance; };
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
	int flag;//������ǽ����Ƿ��ǵ�һ�δ�ȡ���ʼ��Iybalance)
public:
	CInternetBankCustomer() :Ibalance(0), Iybalance(0), ints(0), tdincome(0), ytints(0) {};
	int withdraw(double m);
	int deposit(double m);
	void setYIbalance() { Iybalance = Ibalance; };
	void setInterest(double interest) { ytints = ints; ints = interest / 10000; };
	//void setYtints() { ytints = y; };
	void calculateProfit();
	void print();
	int login(char *_id, char *_password);
};
int CInternetBankCustomer::login(char *_id, char *_password)
{
	if (!CInternetBankCustomer::login(_id, _password)) return 0;
	char bid[20] = { '\0' }, bname[20] = { '\0' };
	CBankCustomer::getId(bid);
	CBankCustomer::getName(bname);
	if ((!CInternetUser::compareid(bid)) || (!CInternetUser::comparename(bname)))return 0;
	return 1;
}
void CInternetBankCustomer::calculateProfit()
{
	//if (ints == 0) tdincome = ytints *Iybalance;
	 tdincome = ytints * Iybalance;
	Ibalance += tdincome;
	flag = 0;//ÿ�����������flag
}
void CInternetBankCustomer::print()
{
	CPeople::print();
	cout << "Bank balance: " << CBankCustomer::getBalance() <<endl;
	cout << "Internet bank balance: " << Ibalance << endl;
	cout << endl;
}
int CInternetBankCustomer::deposit(double m)
{
	if (flag == 0)
	{
		Iybalance = Ibalance;
		flag = 1;
	}
	if (CBankCustomer::withdraw(m))
	{
		Ibalance += m;
		return 1;
	}
	return 0;//���ʧ��(�����д����˻�����0)
}
int CInternetBankCustomer::withdraw(double m)
{
	if (flag == 0)
	{
		Iybalance = Ibalance;
		flag = 1;
	}
	if (Ibalance >= m)
	{
		Ibalance -= m;
		//Iybalance -= m;//����ȡ���������
		CBankCustomer::deposit(m);
		return 1;
	}
	return 0;//���˻���������ʧ�ܷ���0
}
int main()
{
	int t, no_of_days, i;
	char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
	double money, interest;
	char op_code;
	//������԰�����t
	cin >> t;
	while (t--)
	{
		//���뻥�����û�ע��ʱ���û���,id,��½����
		cin >> i_xm >> i_id >> i_mm;
		//�������п����û���,id
		cin >> b_xm >> b_id;
		//���뻥�����û���½ʱ��id,��½����
		cin >> ib_id >> ib_mm;
		CInternetBankCustomer ib_user;
		ib_user.registerUser(i_id, i_xm, i_mm);
		ib_user.openAccount(b_id, b_xm);
		if (ib_user.login(ib_id, ib_mm) == 0)  //�������û���½,��id�����벻��;�Լ����п���������id�뻥��������������id��ͬ
		{
			cout << "Password or ID incorrect" << endl;
			continue;
		}
		//��������
		cin >> no_of_days;
		for (i = 0; i < no_of_days; i++)
		{
			//�����������, ���, ������Ԫ����
			cin >> op_code >> money >> interest;
			switch (op_code)
			{
			case 'S':  //�����������������ʻ�����
			case 's':
				if (ib_user.deposit(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				break;
			case 'T':  //�ӻ���������ת�������ʻ�
			case 't':
				if (ib_user.withdraw(money) == 0)
				{
					cout << "Internet bank balance not enough" << endl;
					continue;
				}
				break;
			case 'D':  //ֱ���������ʻ����
			case 'd':
			{
				ib_user.setYIbalance();//��ʼ���������
				ib_user.CBankCustomer::deposit(money);
			}

				break;
			case 'W':  //ֱ�Ӵ������ʻ�ȡ��
			case 'w':
				if (ib_user.CBankCustomer::withdraw(money) == 0)
				{
					cout << "Bank balance not enough" << endl;
					continue;
				}
				else ib_user.setYIbalance();
				break;
			default:
				cout << "Illegal input" << endl;
				continue;
			}
			ib_user.setInterest(interest);
			ib_user.calculateProfit();
			//����û���,id 
			//����������
			//��������������˻����
			ib_user.print();
		}
	}
	return 0;
}