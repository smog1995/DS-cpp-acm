#include <iostream>
#define Maxsize 1000
using namespace std;
typedef struct 
{
	int data;
	Node* lchild,rchild;
}Tree,Node;
int Stack[Maxsize];
int top=-1;
bool Push(Stack* S,int x)
{
	if(top==Maxsize-1)return false;
	S[++top]=x;
	return true;
}
bool Pop(Stack* S,int &x)
{
	if(top==-1) return false;
	x=S[top--];
	return true;
}
 int main()
 {
 	//中序遍历 
 	InitStack(Stack);
 	while(T||!isEmpty(S))
 	{
 		while(T)
 		{
 			Push(S,T);
 			T=T->lchild;
		 }
		 if(!IsEmpty(S))
		 {
		 	Pop(S,T);
			visit(T);
			T=T->rchild;
		 }
	 }
	 //递归实现 
	  void InOrder(Tree T)
	  {
	  	InOrder(T->lchild);
	  	visit(T);
	  	InOrder(T->rchild);
	  }
	  //中序线索二叉树线索化 
	  void InThread(Tree& p,Node* pre)
	  {
	  		if(p!=NULL)
	  		{
	  			InThread(p->lchild,pre);
	  			if(p->lchild==NULL)
	  			{
	  				p->lchild=pre;
	  				p->ltag=1;
				}
				if(pre&&pre->rchild==NULL)
				{
					pre->rchild=p;
					pre->rtag=1;
				}
			}
			pre=p;
			InThread(p->rchild,pre);
	  } 
	  void CreateThread(Tree& T)
	  {
	  	Node *pre=NULL;
	  	InThread(T,pre);
	  	pre->rchild=NULL;
	  	pre->rtag=1;//无后继 

	  }
	  Node* FirstNode(Node* p)
	  {
	  	while(ltag==0) p=p->ltag;
	  	return p;
	  }
	  Node* NextNode(Node* p)
	  {
	  	if(rtag==1) return p->rchild;
	  	else return FirstNOde(p->lchild);
	   } 
	  //中序线索遍历算法
	  for(Node* p=FirstNode(T);p!=NULL;p=NextNode(p)) 
 }
