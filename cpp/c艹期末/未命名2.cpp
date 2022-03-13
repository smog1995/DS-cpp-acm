#include <iostream>
using namespace std;
template <class T>
class Matrix
{
	T **t;
	int r,c;
	public:
		Matrix(int n,int m,T** t1);
		void transport();
		void print();
		~Matrix(){delete[] t;
		}
};
template <class T>
Matrix<T>::Matrix(int n,int m,T** t1)
{
	r=n;c=m;
	t=new T*[n];
	for(int i=0;i<n;i++)
	t[i]=new T[m];
	for(int i1=0;i1<n;i1++)
	for(int i2=0;i2<m;i2++)
	t[i1][i2]=t1[i1][i2];
	
}
template <class T>
void Matrix<T>::transport()
{
	T **tt;
	tt=new T*[c];
	for(int i=0;i<c;i++)
	tt[i]=new T[r];
	for(int i1=0;i1<c;i1++)
	for(int i2=0;i2<r;i2++)
	tt[i1][i2]=t[i2][i1];
	delete[] t;
	t=tt;
	int tem=r;
	r=c;
	c=tem;
}
template <class T>
void Matrix<T>::print()
{
	for(int i=0;i<r;i++)
	{
		for(int i1=0;i1<c;i1++)
		cout<<t[i][i1]<<" ";
		cout<<endl;
	}
	
}
int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		char type;
		int n,m;
		cin>>type>>n>>m;
		if(type=='I')
		{
			int **I=new int*[n];
			for(int i=0;i<n;i++)
			I[i]=new int[m];
			for(int i1=0;i1<n;i1++)
			for(int i2=0;i2<m;i2++)
			cin>>I[i1][i2];
			Matrix<int> mi(n,m,I);
			mi.transport();
			mi.print();
		}
		else if(type=='D')
		{
			double **D=new double*[n];
			for(int i=0;i<n;i++)
			D[i]=new double[m];
			for(int i1=0;i1<n;i1++)
			for(int i2=0;i2<m;i2++)
			cin>>D[i1][i2];
			Matrix<double> md(n,m,D);
			md.transport();
			md.print();
		}
		else if(type=='C')
		{
			char **C=new char*[n];
			for(int i=0;i<n;i++)
			C[i]=new char[m];
			for(int i1=0;i1<n;i1++)
			for(int i2=0;i2<m;i2++)
			cin>>C[i1][i2];
			Matrix<char> mc(n,m,C);
			mc.transport();
			mc.print();
		}
		
	}
	
}
