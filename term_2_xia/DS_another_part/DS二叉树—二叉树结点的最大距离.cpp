#include <iostream>
#include <string>
#include <stack>
using namespace std;
class BiTreeNode {
public:
	char data;
	BiTreeNode *lc;
	BiTreeNode *rc;
	BiTreeNode() :lc(NULL), rc(NULL) {

	}
	~BiTreeNode() {
		delete lc;
		delete rc;
	}
};
class BiTree {
private:
	BiTreeNode *Root;
	int pos;
	int depth(BiTreeNode* r);
	string strTree;
	BiTreeNode* target;
	int max;
	BiTreeNode* CreateBiTree();
	void pre(BiTreeNode* p);
	void PostOrder(BiTreeNode* root,BiTreeNode* target,int &maxc);
	void pre1(int len, int i, BiTreeNode* p);
public:
	BiTree() {
		pos = 0;
		max=0;
	};
	~BiTree() {
	};
	void pre()
	{
		pre(Root);
	}
	void CreateTree(string TreeArray);
	void Post();
};
void BiTree::PostOrder(BiTreeNode* root,BiTreeNode* target,int &maxc)
{
	if(!root) return ;
	stack<BiTreeNode*> s;
	BiTreeNode* p=root;
	int count=0;

	BiTreeNode *r=NULL;
	while(p||!s.empty())
	{
		if(p)
		{
			p=p->lc;
		}
		else {
			p=s.top();
			if(p->rc&&p->rc!=r)
			{
				p=p->rc;
				s.push(p);
				count++;
				p=p->lc;
			}
			else {
				s.pop();
				count--;
				if(!p->lc&&!p->rc)
				{
					if(maxc<count)
					{
						maxc=count;
						target=p;
					}
				}
				r=p;
				p=NULL;
			}
		}
	}
	cout<<target->data<<" "<<maxc<<" "<<endl;
}
int BiTree::depth(BiTreeNode* r)
{
	if(!r) return 0;
	int ld=depth(r->lc);
	int rd=depth(r->rc);
	if(ld + rd > max)
	{
		max=ld+rd;
		target=r;
	}
	return (ld>rd)?ld+1:rd+1;
}
void BiTree::Post()
{
	depth(Root);
	int left=0,right=0;
	BiTreeNode* r=NULL,*l=NULL;
	PostOrder(target->lc,l,left);
	PostOrder(target->rc,r,right);
	if(!l&&!r)
	{
		cout<<"0:"<<endl;
	}
	else if(!l)
	{
		cout<<right<<":"<<target->data<<" "<<r->data<<endl;
	}
	else if(!r)
	{
		cout<<left<<":"<<l->data<<" "<<target->data<<endl;
	}
	else cout<<left+right<<":"<<l->data<<" "<<r->data<<endl;
}

void BiTree::CreateTree(string TreeArray)
{
	strTree.assign(TreeArray);
	Root = CreateBiTree();
}
BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode* T;
	if (pos>= strTree.length())return NULL;
	char c=strTree[pos++];
	if(c == '#') return NULL;
	T = new BiTreeNode();
	T->data = c;
	T->lc = CreateBiTree();
	T->rc = CreateBiTree();
	return T;
}
void BiTree::pre(BiTreeNode* p)
{
	if (!p) return;
	cout << p->data;
	pre(p->lc);
	pre(p->rc);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		BiTree T;
		string str;
		cin >> str;
		T.CreateTree(str);
		T.Post();
	
	}
}
