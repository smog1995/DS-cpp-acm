#include<iostream>
#include <cstring>
using namespace std;
class Employee
{
	char name[40];
	char state[40];
	int flag;
	unsigned int year,level;
	public:
		virtual int salary();
		int getLevel(){return level;};
		int getYear(){return year;};
		Employee(char *n,char *s,int l,int y);
		void show();
 };
 int Employee::salary()
 {
 	return (1000+500*level+50*year);
 }
 Employee::Employee(char* n,char *s,int l,int y)
 {
	flag=0;
 	if(strcmp(s,"Employee")&&strcmp(s,"Manager")&&strcmp(s,"Teamleader")) flag=1;
 	else if(l<0||y<0) flag=2;
 	else
 	{
 		strcpy(name,n);
 		name[strlen(n)]='\0';
 		strcpy(state,s);
 		state[strlen(s)]='\0';
 		year=y;level=l;
 		flag=3;
	}
 }
void Employee::show()
{
	if(flag==1) cout<<"error position."<<endl;
	else if(flag==2) cout<<"error grade or year."<<endl;
	else 
	{
		cout<<name<<":"<<state<<",Salary:"<<salary()<<endl;
	}
}
class Teamleader:public Employee
{
	public:
		Teamleader(char *n,char *s,int l,int y):Employee(n,s,l,y){};
		int salary();
};
int Teamleader::salary()
{
	return (3000+800*getLevel()+100*getYear());
}
class Manager:public Employee
{
	public:
		Manager(char *n,char *s,int l,int y):Employee(n,s,l,y){};
		int salary();
};
int Manager::salary()
{
	return (5000+1000*(getLevel()+getYear()));
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char n[40],s[40];
		int l,y;
		cin>>n>>s>>l>>y;
		
		if(!strcmp(s,"Manager")) 
		{
			Manager m(n,s,l,y);
			m.show();
		}
		else if(!strcmp(s,"Teamleader")) 
		{
			Teamleader t(n,s,l,y);
			t.show();
		}
		else 
		{
			Employee e(n,s,l,y);
			e.show();
		}
	}
	
}
