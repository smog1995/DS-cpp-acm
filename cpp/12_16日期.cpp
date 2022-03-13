#include <iostream>
#include <string>
#include <mem.h>
using namespace std;
bool isLeapYear(int y)
{
	if (y%400==0||(y%4==0&&y%100!=0)) return true;
	return false;
}
int Yallday(int y)
{
	if(isLeapYear(y)) return 366;
	return 365;
}

class Student
{
	int y, m, d;
public:
	string name;
	Student(){	};
	Student(string n, int y1, int m1, int d1) :y(y1), m(m1), d(d1),name(n){}
	int operator-(Student&);
};
int Student::operator-(Student& s)
{
	int day=0;
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int y1,y2,m1,m2,d1,d2;
	if(y1>y2||(y1==y2&&m1>m2)||(y1==y2&&m1==m2&&d1>d2))
	{
		y1=y;m1=m;d1=d;
		y2=s.y;m2=s.m;d2=s.d;
	}
	else
	{
		y2=y;m2=m;d2=d;
		y1=s.y;m1=s.m;d1=s.d;
	}
	if(y1==y2&&m1==m2)
	{
		day=d1-d2;
		return day;
	}
	else
	{
		day+=d1;//加以当前天数 
		if(y1>y2)
		{
			if(isLeapYear(y1)) a[1]=29;
			for(int i=m1;i>=1;i++)
			day+=a[i-1];
			y1--;
		}
		while(y1>y2)
		{
			day+=Yallday(y1);
			y1--;
		}
		if(isLeapYear(y1)) a[1]=29;
		else a[1]=28;
		for(int i=12;i>m2;i--)
		{
			day+=a[i-1];
		}
		day+=a[m2-1]-d2;
	}
	return day;
}

int main()
{
	int t,i=0;
	cin>>t;
	Student *s;
	s=new Student[t];
	
	while(t--)
	{
		int y,m,d;
		string n;
		cin>>n>>y>>m>>d;
		s[i++]=Student(n,y,m,d);
	}
	int a[t][t],maxd=0;
	memset(a,0,sizeof(a));
	for(int i=0;i<t;i++)
	{
		for(int i1=i;i1<t;i1++)
		{
			a[i][i1]=s[i]-s[i1];
			if(maxd<a[i][i1]) maxd=a[i][i1];
		}
	}
	for(int i=0;i<t;i++)
	for(int i1=i;i1<t;i1++)
	{
		if(maxd==a[i][i1])
		
		{
			cout<<s[i].name<<"和"<<s[i1].name<<"年龄相差最大，为" <<maxd<<"天。"<<endl;
			break;
		}
	}
	
}
