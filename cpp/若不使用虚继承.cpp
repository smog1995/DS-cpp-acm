#include <iostream>
using namespace std;
class A
{//家虚函数与不加虚函数在派生类中重定义有什么不同 
	int a;
	public:
		void printa(){cout<<a<<"(A类)"<<endl;};
		void seta(int x){a=x;};
		int geta(){return a;};
 } ;
 class B:public A
{
	public:
		B(){};
		void printa(){cout<<geta()<<"(B类)"<<endl;}; 
};
class C:public A
{
	public:
		C(){};
		void printa(){cout<<geta()<<"C类"<<endl;}
};
class D:public B,public C
{
	public:
		D(){};
	void print(){cout<<"B的a："<<B::geta()<<" C的a"<<C::geta()<<endl;}
};
int main()
{
	D d;
	d.B::seta(10);
	d.C::seta(11);
	d.B::printa();
	d.C::printa();
	d.print();
}
