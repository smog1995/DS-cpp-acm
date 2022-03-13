#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int n;
class TNode {
public:
	int val;
	TNode* lc, *rc;
	TNode()
	{
		lc = rc = NULL;
	}
};
void pre(int c[],int i)
{
	if (c[i] == 0||i>n-1) return;
	cout << c[i]<<" ";
	pre(c, 2*i + 1);
	pre(c, 2*i + 2);
}
TNode* LevelCreateT(int c[])
{
	int i = 0;
	queue<TNode*> q;
	TNode* root = new TNode();
	root->val = c[i++];
	q.push(root);
	while (!q.empty()&&i<n)
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
void preOrder(TNode* r)
{
	stack<TNode*> s;
	TNode* p = r;
	while (p || !s.empty())
	{
		if (p)
		{
			cout << p->val << " ";
			s.push(p);
			p = p->lc;
		}
		else {
			p = s.top();
			s.pop();
			p = p->rc;
		}
	}
	cout << endl;
}
void InOrder(TNode* r)
{
	stack<TNode*> s;
	TNode* p = r;
	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lc;
		}
		else {
			p = s.top();
			cout << p->val << " ";
			s.pop();
			p = p->rc;
		}
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int *c = new int[n];
		for (int i = 0; i < n; i++)
			cin >> c[i];
		//pre(c, 0);
		//cout << endl;
		TNode* r=LevelCreateT(c);
		preOrder(r);
	}
}