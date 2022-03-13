#include <iostream>
using namespace std;
#define MAX 25
struct Node
{
	Node()
	{
		parent=sibling=-1;
		degree=0;
		lc=rc=-1;
	}
	int parent;
	int lc,rc;
	int sibling;
	int degree;
};
Node nodes[MAX];
int Depth[MAX],Height[MAX];
void rec(int root,int depth)
{
	Depth[root]=depth;
	if(nodes[root].lc!=-1)
	rec(nodes[root].lc,depth+1);
	if(nodes[root].rc!=-1)
	rec(nodes[root].rc,depth+1);
}
int hrec(int root)
{
	if(root==-1) return 0;
	int h1=0,h2=0;
	if(nodes[root].lc!=-1)
	h1=hrec(nodes[root].lc)+1;
	if(nodes[root].rc!=-1)
	h2=hrec(nodes[root].rc)+1;
	return Height[root]=h1>h2?h1:h2;
	
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int v,lc,rc;
		cin>>v;
		cin>>lc>>rc;
		nodes[v].lc=lc;
		nodes[v].rc=rc;
		if(lc!=-1)
		{
			nodes[lc].parent=v;
			nodes[lc].sibling=rc;
			nodes[v].degree++;
		}
		if(rc!=-1)
		{
			nodes[rc].parent=v;
			nodes[rc].sibling=lc;
			nodes[v].degree++;
		}
		
	}
	rec(0,0);
	hrec(0);
	for(int i=0;i<n;i++)
	{
		cout<<"node:"<<i<<" parent="<<nodes[i].parent<<" sibling="<<nodes[i].sibling<<" degree="<<nodes[i].degree<<" depth="<<Depth[i]<<" Height="<<Height[i]<<endl;
	}
}
