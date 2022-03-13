#include <iostream>
#include <cstdlib>
#include <memory.h>
using namespace std;
class CVector
{
	
	int *data;
	int n;
	public:
		friend class Matrix;
		CVector():n(5)
		{
			data=new int[n];
			for(int i=0;i<n;i++)
			data[i]=i; 
		}
		CVector(int n1,int *a):n(n1)
		{
			data = new int[n];
			memcpy(data,a,n*sizeof(int));
		}
		CVector(CVector& c)
		{
			n = c.n;
			data = new int[n];
			memcpy(data,c.data,n*sizeof(int));
		}
		~CVector(){	delete[] data;	};
		void print()
		{
			for(int i=0;i<n;i++)
			cout<<data[i]<<" ";
			cout<<endl;
		};
};
class Matrix
{
	
	int **m;
	int n;
	public:
		Matrix(int n1,int** ma):n(n1)
		{

			m = new int*[n];
			for (int i = 0; i < n; i++)
				m[i] = new int[n];
			for(int i=0;i<n1;i++)
			{
				for(int i1=0;i1<n1;i1++)
				m[i][i1]=ma[i][i1];
			}
		}
		bool judge(const CVector c )
		{
			if(c.n==n) return true;
			return false;
		};
		CVector Multi(const CVector& c); 
		~Matrix(){delete[] m;};
};
CVector Matrix::Multi(const CVector &c)
{
	int *a=new int[n];
	memset(a,0,n*sizeof(n));
	for(int i=0;i<n;i++)
	{
		for(int i1=0;i1<n;i1++)
		a[i]=a[i]+c.data[i1]*m[i1][i];
	}
	CVector *c1=new CVector(n, a);
	return *c1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int **m=new int*[n];
		for(int i=0;i<n;i++)
		m[i]=new int[n];
		for(int i=0;i<n;i++)
		for(int i1=0;i1<n;i1++)
		cin>>m[i][i1];
		Matrix m1(n,m);
		int n2;
		int *a;
		cin>>n2;
		a=new int[n2];
		for(int i=0;i<n2;i++)
		cin>>a[i];
		CVector c1(n2,a);
		if(!m1.judge(c1)) cout<<"error"<<endl;
		else
		{
		//	CVector c2=m1.Multi(c1);要使用临时对象赋值，则需要multi函数返回值为指针地址
		//	c2.print();
			(m1.Multi(c1)).print();
		}
		
	}
	
	
}
