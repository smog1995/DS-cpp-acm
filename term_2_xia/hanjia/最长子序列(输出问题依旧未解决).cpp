#include <iostream>
using namespace std;
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	char X[10]="adcewsdxq",Y[8]="acwsddx";
	int x[10][8];
	int d=0; 
	for(int i=0;i<10;i++)
	for(int i1=0;i1<8;i1++)
	x[i][i1]=0;
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<8;j++)
		{
			if(X[i-1]==Y[j-1]) 
			{
				x[i][j]=x[i-1][j-1]+1;
				if(d!=x[i][j]) 
				{
					cout<<Y[j-1];
					d=x[i][j];
				}
			}
			else 
			x[i][j]=max(x[i-1][j],x[i][j-1]);
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int i1=0;i1<8;i1++)
		cout<<x[i][i1]<<" ";
		cout<<endl;
	}
	
 } 
