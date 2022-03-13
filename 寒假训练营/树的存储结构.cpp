#include <iostream>
using namespace std;
 #define MAX 100
 struct Node
 {
 	int parent;
 	int lchild,rslibling;
 	
  } ;
  Node t[MAX];
  int main(int argc ,const char* argv[])
  {
  	int n;
  	cin>>n;
  	for(int i=0;i<n;i++)//³õÊ¼»¯Ê÷ 
  	{
  		t[i].parent=-1;
  		t[i].lchild=t[i].rslibling=-1;
	}
  	for(int i=0;i<n;i++)//input child
  	{
  		int v,d;
  		cin>>v>>d;
  		int c,s=-1;
  		for(int j=0;j<d;j++)
  		{
  			cin>>c;
  			t[c].parent=v;
  			if(j==0)
  			{
  				t[v].lchild=c;
  				s=c;
			}
			else 
			{
				t[s].rslibling=c;
			}
		}
	}
	int root;
	for(int i=0;i<n;i++)
	{
		if(t[i].parent==-1) root=i;
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<" parent:"<<t[i].parent<<" lchild:"<<t[i].lchild<<" sib:"<<t[i].rslibling<<endl;
	}
  }
