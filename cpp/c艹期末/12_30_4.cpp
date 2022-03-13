#include <iostream>
#include <memory.h>
using namespace std;
template <typename T>
class BoundArray
{
	T *t;
	int size;
	public:
		BoundArray(int n,T* t1);
		void sort();
		void search(T e);
};
template <class T>
BoundArray<T>::BoundArray(int n,T* t1)
{
	size=n;
	t=new T[n];
	for(int i=0;i<n;i++)
	t[i]=t1[i];
	
	
}
template <class T>
void BoundArray<T>::sort()
{
	T x;
	for(int i=0;i<size;i++)
	{
		
		for(int i1=i+1;i1<size;i1++)
		{
			if(t[i]>t[i1])
			{
				x=t[i1];
				t[i1]=t[i];
				t[i]=x;
			}
		}
	}
	for(int i=0;i<size;i++)
	cout<<t[i]<<" ";
	cout<<endl;
}
template <class T>
void  BoundArray<T>::search(T e)
{
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(t[i]==e) 
		{
			cout<<i<<endl;
			flag=1;
		}
	}
	if(flag==0)cout<<-1<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char type;
		int n;
		cin>>type>>n;
		if(type=='I')
		{
			int *I=new int[n];
			for(int i=0;i<n;i++)
			cin>>I[i];
			BoundArray<int> b(n,I);
			b.sort();
			int e;
			cin>>e;
			b.search(e);
		}
		else if(type=='D')
		{
			double *D=new double[n];
			for(int i=0;i<n;i++)
			cin>>D[i];
			BoundArray<double> bd(n,D);
			bd.sort();
			double de;
			cin>>de;
			bd.search(de);
		}
		else if(type=='C')
		{
			char *C=new char[n];
			for(int i=0;i<n;i++)
			cin>>C[i];
			BoundArray<char> bc(n,C);
			bc.sort();
			char ce;
			cin>>ce;
			bc.search(ce);
		}
	}
}
