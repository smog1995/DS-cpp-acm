#include <iostream>
using namespace std;
class A
{//���麯���벻���麯�������������ض�����ʲô��ͬ 
	int a;
	public:
		void printa(){cout<<a<<"(A��)"<<endl;};
		void seta(int x){a=x;};
		int geta(){return a;};
 } ;
 class B:public A
{
	public:
		B(){};
		void printa(){cout<<geta()<<"(B��)"<<endl;}; 
};
class C:public A
{
	public:
		C(){};
		void printa(){cout<<geta()<<"C��"<<endl;}
};
class D:public B,public C
{
	public:
		D(){};
	void print(){cout<<"B��a��"<<B::geta()<<" C��a"<<C::geta()<<endl;}
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
