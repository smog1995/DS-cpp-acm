#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
class BiTreeNode
{
public:
	char data;
	BiTreeNode* lc, *rc;
	BiTreeNode()
	{
		lc = rc = NULL;
	}
};
class BiTree {
private:
	int pos;
	string Tstr;
	BiTreeNode* Root;
	queue<BiTreeNode*> q;
public:
	
	void LevelOrder() {
		queue<BiTreeNode*> q;
		q.push(Root);
		while (!q.empty())
		{
			BiTreeNode* p = q.front();
			cout << p->data;
			q.pop();
			if (p->lc)q.push(p->lc);
			if (p->rc)q.push(p->rc);
		}
		cout << endl;
	}
	void LOrder(BiTreeNode* p)
	{
		if (!p) return;
		p=q.pop();
		cout << p->data;
		if (p->lc) q.push(p->lc);
		if (p->rc) q.push(p->rc);
	}
	BiTreeNode* preCreate()
	{
		BiTreeNode* T;
		char c = Tstr[pos++];
		if (c == '0') return NULL;
		T = new BiTreeNode();
		T->data = c;
		T->lc = preCreate();
		T->rc = preCreate();
		return T;

	}
	void PostOrder()
	{
		stack<BiTreeNode*> s;
		BiTreeNode* p=Root;
		BiTreeNode* r=NULL;
		while (p || !s.empty())
		{
			if (p)
			{
				s.push(p);
				p = p->lc;
			}
			else {
				p = s.top();
				if (p->rc&&p->rc != r)
				{
					p = p->rc;
					s.push(p);
					p = p->lc;
				}
				else {
					cout << p->data;
					s.pop();
					r = p;
					p = NULL;
				}
			}
		}
		cout << endl;
	}
	void CreateT(string str)
	{
		
		pos = 0;
		Tstr = str;
		Root = preCreate();
		q.push(Root);//层次遍历递归实现
		LOrder(Root);
	}
	~BiTree()
	{
		pos = 0;
		delete Root;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		BiTree T;
		T.CreateT(str);
		T.PostOrder();
	}
}
