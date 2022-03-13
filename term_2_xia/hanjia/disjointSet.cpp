#include <iostream>
#include <vector>
using namespace std;
vector<int> r;
vector<int> p;

void makeSet(int x)
{
	p[x]=x;
	r[x]=0;
}
void disjointSet_init(int n)
{
	r.resize(n,0);
	p.resize(n,0);
	for(int i=0;i<n;i++) makeSet(i);
}
int findSet(int x)
{
	if(p[x]==x) return x;
	 findSet(p[x]);
}
bool same(int x,int y)
{
	return findSet(x)==findSet(y);
}
void unite(int x,int y)
{
	x=findSet(x);
	y=findSet(y);
	if(r[x]>r[y])
	{
		p[y]=x;
	}
	else 
	{
		p[x]=y;
		if(r[x]==r[y])
		r[y]++;
	}
}
int main()
{
	int n,a,b,q;
	int op;
	cin>>n>>q;
	disjointSet_init(n);

	for(int i=0;i<q;i++)
	{
		cin>>op>>a>>b;
		if(op==0)
		unite(a,b);
		else
		{
			if(same(a,b)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
	return 0;
}
