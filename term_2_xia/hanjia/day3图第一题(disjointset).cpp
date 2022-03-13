#include <iostream>
#include <stdio.h>
using namespace std;
int n,m,q,from,to;
int rank[100000],parent[100000];

int find(int x)
{
	if (x==parent[x]) return x;
	else return parent[x]=find(parent[x]);
}
bool isSame(int x,int y)
{
	return find(x)==find(y);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return ;
	if(rank[x]<rank[y]) parent[x]=y;
	else 
	{
		parent[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}
int main()
{
	int n,m;
	//n代表n个点，m代表m对关系 
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		rank[i]=0;
		parent[i]=i;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&from ,&to);
		if(!isSame(from,to))
		unite(from,to); 
	}
	scanf("%d",&q);
	int left,right;
	for(int i=0;i<q;i++)
	{
		scanf("%d %d",&left,&right);
		if(isSame(left,right)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}

