#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class TNode{
	public:
		char data;
		TNode *lc,*rc;
		TNode()
		{
			lc=rc=NULL;
		}
};
class Tree{
	private:
		void pre(TNode* r)
		{
			stack<TNode* > s;
			TNode* p=r;
			while(p||!s.empty())
			{
				if(p)
				{
					s.push(p);
					if(!p->lc&&!p->rc) q.push(p);
					p=p->lc;
				}
				else{
					p=s.top();
					s.pop();
					p=p->rc;
				}
			}
		}
	public:
		Tree(string str){
			pos=0;
			root=CreateT(str); 
		}
		TNode* root;
		queue<TNode*> q;
		int pos;
		void pre(){
			pre(root);
		}
		TNode* CreateT(string &str){
			TNode* t;
			char c=str[pos++];
			if(pos>str.length()||c=='0') t=NULL;
			else {
				t->data=str[pos];
				t->lc=CreateT(str);
				t->rc=CreateT(str);
			}
			return t;
		}
		
		void pref(TNode* p,TNode* child)
		{
			if(!p) return ;
			if(p->lc==child||p->rc==child) 
			cout<<p->data<<" ";
			pref(p->lc,child);
			pref(p->rc,child);
		}
		void Post(TNode* r)
		{
			stack<TNode*> s;
			TNode* p=r,*q;
			while(p||!s.empty())
			{
				if(p)
				{
					s.push(p);
					p=p->lc;
				}
				else{
					p=s.top();
					if(p->rc&&p->rc!=q)
					{
						
						p=p->rc;
						s.push(p);
						p=p->lc;
						
					}
					else{
						
						s.pop();
						cout<<p->data<<" ";
						q=p;
						p=NULL;
					}
				}
			}
		}
		void find()
		{
			while(!q.empty())
			{
				TNode* p=q.front();
				q.pop();
				pref(root,p);
				
			}
		}
}; 

int main()
{
	stack<TNode*> s;
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Tree T(str);
		T.pre();
		T.find();
	 } 
} 
