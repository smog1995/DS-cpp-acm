#include<iostream>
#include<cmath> 
using namespace std;


int main()
{
	int n=0,i;
	cin>>n;
	int k=(int)sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i)break;
	}
	if(i>k) cout<<n<<"is prime"<<endl;
	else cout<<n<<"is not prime"<<endl;
 } 
