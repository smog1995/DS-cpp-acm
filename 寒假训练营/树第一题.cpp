#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
 	/*
 			基于课堂练习，实现第一题 
 	*/ 
struct Node
 {
 	Node()
 	{
 		depth=num_of_children=0;
 		parent=-1;
	}
 	int parent;
 	int depth;
 	vector<int> children;
 	int num_of_children;
  };
  void calcDepth(Node Nodes[],int root_id)//递归计算深度 
  {
  	for(int i=0;i<Nodes[root_id].num_of_children;i++)
  	{
  		Nodes[Nodes[root_id].children[i]].depth=Nodes[root_id].depth+1;
  		calcDepth(Nodes,Nodes[root_id].children[i]);
	}
  }

  int main(int argc ,const char* argv[])
  {
  	int n;
  	cin>>n;
  	Node t[n];
  	/*
	  for(int i=0;i<n;i++)//初始化树 
  	{
  		t[i].parent=-1;
  		t[i].lchild=t[i].rslibling=-1;
	}
	*/
  	for(int i=0;i<n;i++)//input child
  	{
  		int v,k;
  		cin>>v>>k;
  		t[v].num_of_children=k;
  		int c;
  		for(int j=0;j<k;j++)
  		{
  			cin>>c;
  			t[c].parent=v;
  			t[v].children.push_back(c);
  		
		}
	}
	int root;
	for(int i=0;i<n;i++)
	{
		if(t[i].parent==-1) root=i;
	}
	calcDepth(t,root);
	for(int i=0;i<n;i++)
	{
		printf("node %d: parent = %d, depth = %d, ",i,t[i].parent,t[i].depth);
		if(t[i].parent==-1) cout<<"root, ";
		else if(t[i].num_of_children==0) cout<<"leaf, ";
		else if(t[i].parent!=-1&&t[i].num_of_children!=0) cout<<"internal node, ";
		cout<<"[";
		for(int j=0;j<t[i].num_of_children;j++)
		{
			if(j!=t[i].num_of_children-1)
			cout<<t[i].children[j]<<", ";
			else cout<<t[i].children[j];
		}
		cout<<"]"<<endl;
	}
  }
