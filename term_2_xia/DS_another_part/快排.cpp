#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void adjust(vector<int>& a,int k,int len)
{
	int temp=a[k];
	for(int i=2*k+1;i<len;i=2*i+1)
	{
		if(i<len-1&&a[i]>a[i+1]) i++;
		if(a[i]>=temp) break ;
		else{
			a[k]=a[i];
			k=i;
		}
	}
	a[k]=temp;
}
int main()
{
	int n;
	cin>>n;
	vector<int> a(n,0);
	
	for(int i=0;i<n;i++)
	cin>>a[i];
//	for(int i=0;i<a.size();i++)
//	cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=n/2-1;i>=0;i--)
	adjust(a,i,n);
	for(int i=0;i<n;i++)
	{
		int t=a[0];
		a[0]=a[n-1-i];
		a[n-1-i]=t;
		adjust(a,0,n-1-i);
		for(int i=0;i<n;i++)
		cout<<a[i]<<" "; 
		cout<<endl;
	}
	
}
