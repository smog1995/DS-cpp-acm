#include <iostream>
#include <cmath>
using namespace std;
int Min(int x,int y)
{
	return x<y?x:y;
 } 
int main()
{
	int n,m;
	cin>>n>>m;
	int C[m];
	for(int i=0;i<m;i++)
	cin>>C[i];
	int T[n+1];
	T[0]=0;
	for(int i=1;i<n+1;i++)
	T[i]=10000; 
	for(int i=0;i<m;i++)
	for(int j=C[i];j<=n;j++)
	{
		T[j]=Min(T[j],T[j-C[i]]+1);

	}
	cout<<T[n]<<endl;
}




