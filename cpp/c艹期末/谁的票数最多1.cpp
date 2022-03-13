#include <iostream>
#include <string>
using namespace std;
template<class T>
void Vote(T* t,int n)
{
	for(int i=0;i<n;i++)
	for(int i1=i+1;i1<n;i1++)
	{
		if(t[i1]>t[i])
		{
			T temp=t[i1];
			t[i1]=t[i];
			t[i]=temp;
		}
	}
	T people=t[0];
	T succe=t[0];
	int num=1;
	int max_num=0;
	for(int i=0;i<n;i++)
	{
		if(t[i+1]!=people)
		{
			people=t[i+1];
			if(max_num<num) 
			{
				max_num=num;
				succe=t[i];
			}
			num=1;
		}
		else
		{
			num++;
		}
	}
	cout<<succe<<" "<<max_num<<endl;
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		char type;
		int n;
		cin>>type;
		cin>>n;
		if(type=='I')
		{
			int *I=new int[n+1];
			for(int i=0;i<n;i++)
				cin>>I[i];
			Vote(I,n);
		}
		else if(type=='C')
		{
			char *C=new char[n+1];
			for(int i=0;i<n;i++)
			cin>>C[i];
			Vote(C,n);
		}
		else if(type=='S')
		{
			string *S=new string[n+1];
			for(int i=0;i<n;i++)
			cin>>S[i];
			Vote(S,n);
		} 
	}

	
 } 
