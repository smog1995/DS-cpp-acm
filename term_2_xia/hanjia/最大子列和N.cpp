#include <iostream>
using namespace std;
int main()
{
	int ThisSum,max;
	int a[10]={1,-2,3,5,12,10,-10,2,9,-10};
	for(int i=0;i<10;i++)
	{
		ThisSum+=a[i];
		if(ThisSum<0)ThisSum=0;
		else if(max<ThisSum) max=ThisSum;
		 
	}
	cout<<max<<endl;;
 } 
