#include <iostream>
using namespace std;
int main()
{
	int **p;//����һ������ָ�� 
	cout<<&p<<" "<<p<<endl; //��һ����ָ���������ĵ�ַ,�ڶ��������ָ��δ��ʼ���������ĵ�ַ 
	p=new int*[4];//��̬�����ָ�����һ��ָ������ ����ַ��ŵ���ָ������ĵ�ַ��

	cout<<&p<<" "<<p<<endl; //��ʱ�����ָ���������ĵ�ַ�������Ǹ���ַ�����ǵڶ��������ָ����Ϊ������̬����󣬵�ַΪָ������ĵ�ַ 
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
	cout<<"�ָ���-----------"<<endl;
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
		//p1��ָ���������ŵ���ָ������ĵ�ַ��p1[0]��ָָ�������е�һ��ָ��ĵ�ַ. 
	cout<<"�ָ���-------"<<endl;
	int *p2;
	cout<<p2<<endl;
	int a;
	p2=&a;
	cout<<&p2<<" "<<p2<<" "<<&a<<endl; 
	delete p;
}
