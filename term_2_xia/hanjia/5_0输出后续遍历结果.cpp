#include <iostream>
#include <string >
#include <algorithm>
#include <vector>
using namespace std;
vector<int > pre,in,post;
int n,pos;
void rec(int l,int r)
{
	if(l>=r) return ;
	int root=pre[pos++];
	int m=(int ) distance(in.begin(),find(in.begin(),in.end(),root));
	rec(l,m);
	rec(m+1,r);
	post.push_back(root);
 } 
 int main()
 {
 	int n,temp;
 	cin>>n;
 	for(int i=0;i<n;i++)
	 {
	 	cin>>temp;pre.push_back(temp);
	 }
	 for(int i=0;i<n;i++)
	 {
	 	cin>>temp;in.push_back(temp);
	 }
	 pos=0;
	 rec(0,n);
	 for(int i=0;i<n;i++)
	 cout<<post[i]<<" "; 
	 return 0;
 }
