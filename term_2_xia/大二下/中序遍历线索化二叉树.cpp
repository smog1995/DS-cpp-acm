#include <iostream>
#include <stack>
#include <queue> 
using namespace std;
class TNode {
public:
	int val;
	int ltag, rtag;
	TNode* lc, *rc;
	TNode() {
		ltag = rtag = 0;
		lc = rc = NULL;
	}
};
int n;
TNode* LevelCreateT(int c[])
{
	int i = 0;
	queue<TNode*> q;
	TNode* root = new TNode();
	root->val = c[i++];
	q.push(root);
	while (!q.empty() && i < n)
	{
		TNode* p = q.front();
		q.pop();
		if (c[i])
		{
			p->lc = new TNode();
			p->lc->val = c[i];
			q.push(p->lc);
		}
		else p->lc = NULL;
		i++;
		if (i >= n) break;
		if (c[i])
		{
			p->rc = new TNode();
			p->rc->val = c[i];
			q.push(p->rc);
		}
		else p->rc = NULL;
		i++;
	}
	return root;
}
void InOrderThread(TNode* p, TNode* pre)
{
	if (p)
	{
		InOrderThread(p->lc, pre);
		if (!p->lc)
		{
			p->lc = pre;
			p->ltag = 1;
		}
		if (pre && !pre->rc)
		{
			pre->rc = p;
			pre->rtag = 1;
		}
		pre = p;
		InOrderThread(p->rc, pre);
	}
}
TNode* FirstNode(TNode* p)
{
	while (!p->ltag) p = p->lc;
	return p;
}
TNode* NextNode(TNode* p)
{
	if (!p->rtag) return FirstNode(p);
	return p->rc;
}
using namespace std;
int main()
{
	stack<TNode*> s;

	cin >> n;
	int *c = new int[n];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	TNode* p = LevelCreateT(c);
	TNode* pre = NULL;
	InOrderThread(p, pre);
	pre->rtag = 1;
	/*
	//中序线索化二叉树的迭代法

while(p||!s.empty())
{
	if(p)
	{
		s.push(p);
		p=p->lc;
	}
	else
	{
		p=s.top();
		s.pop();
		if(!p->lc)
		{
			p->lc=pre;
			p->ltag=1;
		}
		if(pre&&!pre->rc)
		{
			pre->rc=p;
			pre->rtag=1;
		}
		pre=p;
		p=p->rc;
	}
}
pre->rtag=1;
*/
//中序线索二叉树遍历
	for (TNode* p1 = FirstNode(p); p; p1 = NextNode(p1))
	{
		cout << p1->val << " ";
	}

}