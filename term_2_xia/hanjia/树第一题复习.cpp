#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000
struct Node
{
	Node()
	{
		num_of_children=0;
		parent=-1;
	}
	int parent;
	int num_of_children;
	vector<int> children;
};
Node nodes[MAX];
int Depth[MAX];
int Height[MAX]; 
void rec(int root)
{
	for(int i=0;i<nodes[root].num_of_children;i++)
	{
		Depth[nodes[root].children[i]]=Depth[root]+1;
		rec(nodes[root].children[i]);
	}
}
void hrec(int)
{
	int h
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Depth[i]=0;
		int v,k;
		cin>>v>>k;
		nodes[i].num_of_children=k;
		int c;
		for(int j=0;j<k;j++)
		{
			cin>>c;
			nodes[v].children.push_back(c);
			nodes[c].parent=v;
		}
	}
	int root=0;
	for(int i=0;i<n;i++)
	{
		if(nodes[i].parent==-1)
		root=i;
	}
	rec(root);
	for(int i=0;i<n;i++)
	{
		printf("node %d: parent = %d, depth = %d, ",i,nodes[i].parent,Depth[i]);
		if(nodes[i].parent==-1) cout<<"root, ";
		else if(nodes[i].num_of_children==0) cout<<"leaf, ";
		else if(nodes[i].parent!=-1&&nodes[i].num_of_children!=0) cout<<"internal node, ";
		cout<<"[";
		for(int j=0;j<nodes[i].num_of_children;j++)
		{
			if(j!=nodes[i].num_of_children-1)
			cout<<nodes[i].children[j]<<", ";
			else cout<<nodes[i].children[j];
		}
		cout<<"]"<<endl;
	}
} 
