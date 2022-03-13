#include <iostream>
using namespace std;
#define int long long 
signed main()
{
	int n;
	cin>>n;
	int e[n][n];
	memset(e,0,sizeof(e));
	for(int i=0,u,k;i<n;i++)
	{
		cin>>u>>k;
		for(int j=0,v;j<k;j++)
		{
			cin>>v;
			e[u-1][v-1]=1;
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cout<<e[i][j]<<" \n"[j==n-1];
}



