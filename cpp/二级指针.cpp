#include <iostream>
using namespace std;
int main()
{
	int **p;//定义一个二级指针 
	cout<<&p<<" "<<p<<endl; //第一个是指针变量本身的地址,第二个会输出指针未初始化随机分配的地址 
	p=new int*[4];//动态分配给指针变量一个指针数组 （地址存放的是指针数组的地址）

	cout<<&p<<" "<<p<<endl; //此时输出的指针变量本身的地址依旧是那个地址，但是第二个输出的指针因为经过动态分配后，地址为指针数组的地址 
	for(int i=0;i<4;i++)
	{
		p[i]=new int[10];
	}
	for(int i=0;i<4;i++)
	for(int i1=0;i1<10;i1++)
	{
		p[i][i1]=i1;
	}
	for(int i=0;i<4;i++)
	for(int i1=0;i1<10;i1++)
	{
		cout<<" "<<p[i][i1];
		if(i1%9==0&&i1!=0) cout<<endl;
	}
	cout<<&p<<" "<<p<<" "<<(p+0)<<" "<<p[0]<<endl;
	cout<<"分割线-----------"<<endl;
	int *p1[4];
	cout<<&p1<<" "<<p1<<endl;
	for(int i=0;i<4;i++)
	{
		p1[i]=new int[10];
	}
	for(int i=0;i<4;i++)
	for(int i1=0;i1<10;i1++)
	{
		p1[i][i1]=i1;
	}
	for(int i=0;i<4;i++)
	for(int i1=0;i1<10;i1++)
	{
		cout<<" "<<p1[i][i1];
		if(i1%9==0&&i1!=0) cout<<endl;
	}
		cout<<&p1<<" "<<p1<<" "<<(p1+0)<<" "<<p1[0]<<" "<<*p1[0]<<endl;
		//p1是指针变量，存放的是指针数组的地址，p1[0]是指指针数组中第一个指针的地址. 
	cout<<"分割线-------"<<endl;
	int *p2;
	cout<<p2<<endl;
	int a;
	p2=&a;
	cout<<&p2<<" "<<p2<<" "<<&a<<endl; 
	delete p;
}
