#include <iostream>
#include <cstring>
using namespace std;
class CDate
{

private:

	int year, month, day;

public:

	CDate(int y, int m, int d) :year(y), month(m), day(d) {};
	CDate() {
	};
	bool check(); //检验日期是否合法
	int getYear() { return year; };
	int getMonth() { return month; };
	int getDay() { return day; };
	bool isLeap() { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; };

	void print()
	{
		cout << year << "年" << month << "月" << day << "日";
	}

};
bool CDate::check()
{
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeap()) a[2] = 29;
	if (month < 1 || month>12 || day<1 || day>a[month] || year < 0) return false;
}
class COldID
{

protected:

	char *p_id15, *p_name; //15位身份证号码，姓名

	CDate birthday; //出生日期

public:

	COldID(char *p_idval, char *p_nameval, CDate &day)
	{
		p_id15 = new char[strlen(p_idval) + 1];
		strcpy(p_id15, p_idval);
		p_id15[strlen(p_idval)] = '\0';
		p_name = new char[strlen(p_nameval) + 1];
		strcpy(p_name, p_nameval);
		p_name[strlen(p_nameval)] = '\0';
		birthday = day;
	}

	virtual bool check(); //验证15位身份证是否合法

};

bool COldID::check()
{
	if (!birthday.check())
		return false;
	if (strlen(p_id15) != 15) return false;
	for (int i = 0; i < 15; i++)
		if (p_id15[i]<'0' || p_id15[i]>'9') return false;
	if (birthday.getDay() % 10 != p_id15[11] || birthday.getDay() / 10 != p_id15[10]
		|| birthday.getMonth() % 10 != p_id15[9] || birthday.getMonth() / 10 != p_id15[8]
		|| birthday.getYear() % 10 != p_id15[7] || birthday.getYear() / 10 % 10 != p_id15[6])
		return false;
	return true;
}
class CNewID :virtual public COldID
{
private:
	char* p_id18;
	CDate issueday;
	int validyear;
public:
	void print();
	CNewID(char* pid15, char* n, CDate &day, char* pid18, CDate &isd, int valid);
	bool check();
};
CNewID::CNewID(char* pid15, char* n, CDate &day, char* pid18, CDate &isd, int valid) :COldID(pid15, n, day)
{
	p_id18 = new char[strlen(pid18) + 1];
	strcpy(p_id18, pid18);
	p_id18[strlen(pid18)] = '\0';
	issueday = isd;
	validyear = valid;
}
bool CNewID::check()
{
	if (!COldID::check())
		return false;
	if (strlen(p_id18) != 18)
		return false;
	if (!issueday.check())
		return false;
	if ((issueday.getYear() + validyear) < 2015 || (issueday.getMonth() > 4 && (issueday.getYear() + validyear) == 2015)
		|| (issueday.getMonth() == 4 && (issueday.getYear() + validyear) == 2015 && issueday.getDay() > 7))
		return false;
	//
	char *newid18 = new char[19];
	for (int i = 0; i < 6; i++)
		newid18[i] = p_id15[i];
	if (birthday.getYear() < 2000)
	{
		newid18[6] = '1';
		newid18[7] = '9';
	}
	else
	{
		newid18[6] = '2';
		newid18[7] = '0';
	}
	for (int i = 8; i < 17; i++)
		newid18[i] = p_id15[i - 2];
	int sum = 0;
	char b[11] = { '1','0','X','9','8','7','6','5','4','3','2' };
	int a[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	for (int i = 0; i < 17; i++)
		sum += (newid18[i] - '0')*a[i];
	sum %= 11;
	p_id18[17] = b[sum];
	if (strcmp(newid18, p_id18)) return false;
	return true;
};


void CNewID::print()
{
	if (check())
	{
		cout << p_name << endl;
		cout << p_id18 << " ";
		issueday.print();
		cout << validyear << endl;
	}
	else cout << "illegal id" << endl;

}
int main()
{
	int t, y1, m1, d1, y2, m2, d2, v;
	char name[10], p15[20], p18[20];
	cin >> t;
	while (t--)
	{
		cin >> name >> y1 >> m1 >> d1 >> p15 >> p18 >> y2 >> m2 >> d2 >> v;
		CDate birth(y1, m1, d1);
		CDate issue(y2, m2, d2);
		COldID o(p15, name, birth);
		CNewID n(p15, name, birth, p18, issue, v);
		n.print();
	}
}
