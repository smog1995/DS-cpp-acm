#include<iostream>
using namespace std;
class CPeople
{
	char id[20];
	char name[20];
public:
	void setId(char *_id)
	{
		strcpy(id, _id);
		id[19] = '\0';
	}
	void setName(char* _name)
	{
		strcpy(name, _name);
		name[19] = '\0';
	}
	bool cmpId(char *_id)
	{
		return (!strcmp(id, _id));
	}
	/*bool cmpName(char *_name)
	{
		return (!strcmp(name, _name););
	}*/
	CPeople(char* _id, char* _name)
	{
		strcpy(id,_id);
		id[19] = '\0';
		strcpy(name, _name);
		name[19] = '\0';
	}
};
class CInternetUser :public CPeople
{
	char password[20];


public:
	CInternetUser(char )
	void register(char *_id, char *_name, char *_password)
	{
		CPeople::setId(_id);
		CPeople::setName(_name);
		strcpy(password, _password);
	}
	bool login(char *_id,char *mm)
	{
		return (CPeople::cmpId(_id))&&(!strcmp(password,mm));
	}
};
class CBankCustomer :public CPeople
{
	double balance;
public:
	void openAccount(char *_name, char *_id)
	{
		CPeople::setId(_id);
		CPeople::setName(_name);

	}
	void deposit(double d)
	{
		balance += d;
	}
	int withdraw(double d)
	{

		if (balance < d) return 0;
		else balance -= d;
		return d;
	}
	CBankCustomer();
};
class CInternetBankCustomer :public CPeople
{

};