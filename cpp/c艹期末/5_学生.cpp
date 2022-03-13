#include <iostream>
using namespace std;
class Student
{
	//static Student* sFirst;
	int number;
	int gra;
	public:
		Student(int num,int grade);
		void show(){cout<<number<<" "<<gra<<endl;
		}
		
};
//Student* Student::sFirst=0;
Student::Student(int num,int grade)
{
	number=num;
	gra=grade;
	//if(sFirst!=0) sFirst=this;
}
int main()
{
	Student stu[5]={Student(2019,100),Student(2018,99),Student(2017,98),Student(2016,97),Student(2011,101)};
	Student *s=stu;
	for(int i=0;i<5;i+=2)
	(s+i)->show();
	delete s;
	return 0;
}
