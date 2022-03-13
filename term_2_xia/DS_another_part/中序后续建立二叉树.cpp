#include <iostream>
using namespace std;
class TNode
{
	public:
		int val;
		TNode* left;
		TNode* right;
		TNode()
		{
			left=right=NULL;
		}
};
class Tree
{
	public:
		TNode* root;
		int v;
		TNode* InPost(int a[],int b[],int l1,int h1,int l2,int h2)
		{
			if(h1<l1) return NULL;
			TNode* root=new TNode();
			root->val=b[h2];
			int x,i;
			for(i=l1;i<h1&&b[h2]!=a[i];i++);
			int inl=i-l1;
			root->left=InPost(a,b,l1,i-1,l2,l2+inl-1);
			root->right=InPost(a,b,i+1,h1,l2+inl,h2-1);
			return root;
			
		}
		void Pre(TNode* r)
		{
			if(!r) return ;
			cout<<r->val<<" ";
			if(!r->left&&!r->right)
			{
				if(r->val<v) v=r->val;
			}
			Pre(r->left);
			Pre(r->right);
		}
		void CreateT(int t)
		{
			v=9999;
			int *a=new int[t];
			for(int i=0;i<t;i++)
			cin>>a[i];
			int *b=new int[t];
			for(int i=0;i<t;i++)
			cin>>b[i];
			root=InPost(a,b,0,t-1,0,t-1);
			Pre(root);cout<<endl; 
			cout<<v<<endl;
		}
};
int main()
{
	Tree *T=new Tree();
	int t;
	cin>>t;
	T->CreateT(t);
}
