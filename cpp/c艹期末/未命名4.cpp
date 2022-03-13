#include <iostream>
#include <cstdlib>
#include <memory.h>
using namespace std;
class CVector
{
	int *data;
	int n;
	public:
		CVector():n(5)
		{
			data=new int[n];
			for(int i=0;i<n;i++)
			data[i]=i; 
		}
		CVector(int n1,int *a):n(n1)
		{
			data=new int[n];
			memcpy((void*)data,(void*)a,n1*sizeof(int) );
		}
		~CVector(){	delete[] data;	};
		void print()
		{
			for(int i=0;i<n;i++)
			cout<<data[i]<<" ";
			cout<<endl;
		};
};
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	CVector c1;
	CVector c2(n,a);
	c1.print();
	c2.print();
}
