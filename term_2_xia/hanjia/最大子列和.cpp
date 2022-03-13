#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int thissum=0;
	int sum=0,i1=0,j1=0,i2=0,j2=0;
	for(int i=0;i<n;i++)
	{
		thissum+=a[i];
		j1++;
		if(thissum<0) 
		{
			thissum=0;
			i1=i+1;
			j1=0;
		}
		if(thissum>sum) 
		{
			sum=thissum;
			i2=i1;
			j2=j1;
		}
	}
	if(sum>0)
	{
		cout<<sum<<" "<<a[i2]<<" "<<a[i2+j2-1]<<endl;
	}
	else if(a[i2]==a[j2])
	{
		cout<<0<<" "<<a[0]<<" "<<a[n-1]<<endl;
	}
	else cout<<0<<" "<<0<<" "<<0<<endl;
 } 
