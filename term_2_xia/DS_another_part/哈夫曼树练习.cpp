#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 class HuffNode{
 	int weight;
 	int parent;
 	int lc;
 	int rc;
 };
 class HuffMan{
 	private:
 		void MakeTree();
 		void SelectMin(int pos,int *s1,int *s2);
 	public:
 		int len;//节点数
		 int lnum;//叶子数量
		 HuffNode* huffTree;
		 string *huffCode;
		 void MakeFree(int n,int wt[]);
		 void Coding();
		 void Destroy();
		 int Decode(const string codestr,char txtstr[]);
		  
 };
 void HuffMan::SelectMin(int pos,int *s1,int *s2)
 {
 	int w1=w2=9999;
 	*s1=*s2=0;
 	for(int i=1;i<=pos;i++)
 	{
 		if(huffTree[i].parent==0)
 		{
 			if(w1>huffTree[i].weight)
 			{
 				*s2=*s1;
 				w2=w1;
 				*s1=i;
 				w1=huffTree[i].weight;
			 }
			 else if(w2>huffTree[i].weight)
			 {
			 	*s2=i;
			 	w2=huffTree[i].weight;
			 }
		 }
	 }
 }
 void HuffMan::MakeTree()
 {
 	int i,s1,s2;
 	for(i=lnum+1;i<=len;i++)
 	{
 		SelectMin(i,s1,s2);
 		huffTree[i].lc=s1;
 		huffTree[s1].parent=i;
 		huffTree[i].rc=s2;
 		huffTree[s2].parent=i;
 		huffTree[i].weight=huffTree[s1].weight+huffTree[s2].weight;
	 }
 }
 void HuffMan::MakeFree(int n,int wt[])
 {
 	lnum=n;
 	len=2*n-1;
 	huffTree=new HuffNode[2*n];
 	huffCode=new string[lnum+1];
 	for(int i=1;i<=len;i++)
 	{
 		if(i>n) huffTree[i].weight=0;
 		else huffTree[i].weight=wt[i-1];
 		huffTree[i].parent=huffTree[i].lc=huffTree[i].rc=0;
 	
	}
	MakeTree();
 }
bool HuffMan::Coding()
 {
 	char* cd;
 	int i,c,f,start;
 	cd=new char[lnum];
 	cd[lnum-1]='\0';//该编码长度最长为lnum-1
	 for(i=1;i<=lnum;i++)
	 {
	 	start=lnum-1;
	 	for(c=i,f=huffTree[c].parent;f;c=f,f=huffTree[f].parent)
	 	{
	 		if(huffTree[f].lc==c) cd[--start]='0';
	 		else if(huffTree[f].rc==c) cd[--start]='1';
	 		else return -1;
	 		
		}
	 }
 }
