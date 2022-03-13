#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Student
{
	string name;
	int year,month,day;
	public:
		Student() { };
		Student(string n,int y,int m,int d):name(n),year(y),month(m),day(d){};
		friend int operator-(Student& s1,Student& s2);
		friend void show(Student& s1,Student& s2);
 }; 
 void show(Student& s1,Student& s2)
{
	cout<<s1.name<<"和"<<s2.name<<"年龄相差最大，为" ;
}
 bool isLeapYear(int y)
 {
 	return (y%100!=0&&y%4==0)||(y%400==0);
 }
 int Yallday(int y)
 {
 	if(isLeapYear(y)) return 366;
 	return 365;
 }
int calcudayfrom1970(int y,int m,int d)
{
	int days=d;
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (isLeapYear(y)) a[2]=29;
	for(int i=1;i<m;i++)
	days+=a[i];
	for(int i=1970;i<y;i++)
	days+=Yallday(i);
	return days;
}
int operator-(Student& s1,Student& s2)
{
	int y1,m1,d1,y2,m2,d2;
	y1=s1.year;y2=s2.year;
	m1=s1.month;m2=s2.month;
	d1=s1.day;d2=s2.day;
	
	int x1=0,x2=0;
	x1=calcudayfrom1970(y1,m1,d1);
	x2=calcudayfrom1970(y2,m2,d2);
	return abs(x1-x2);	
}
int main()
{
	int t;
	cin>>t;
	Student **s;
	s=new Student*[t];
	int y,m,d;
	string name;
	for(int i=0;i<t;i++)
	{
		cin>>name>>y>>m>>d;
		s[i]=new Student(name,y,m,d);
		
	}
	int maxd=0;	
	int stu1,stu2;
	for(int i=0;i<t;i++)
	{
		for(int i1=i+1;i1<t;i1++)
		{
			if((*s[i]-*s[i1])>maxd)
			{
				maxd=*s[i]-*s[i1];//二级指针不要忘了带*才表示单个元素 
				stu1=i;stu2=i1;
			}
		}
	}
	show(*s[stu1],*s[stu2]);
	cout<< maxd << "天。" << endl;
}
