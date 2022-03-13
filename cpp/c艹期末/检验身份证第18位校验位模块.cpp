#include <iostream>
using namespace std;
int main()
{
	char id[18];
	cin>>id;
	int sum=0;
	char b[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	for(int i=0;i<17;i++)
	 sum+=(id[i]-'0')*a[i];
	 sum%=11;
	 cout<<sum<<" "<<b[sum]<<" "<<id[17];
	 
}
