#include <iostream>
#include <string>
#include <stack>
using namespace std;
class BiTreeNode
{
public:
	char data;
	int weight;
	BiTreeNode* lc, *rc;
	BiTreeNode()
	{
		lc = rc = NULL;
	}
};
class BiTree {
private:
	int pos;
	int i;
	int max;
	int *W;
	string Tstr;
	BiTreeNode* Root;
public:

	BiTreeNode* preCreate()
	{
		BiTreeNode* T;
		char c = Tstr[pos++];
		if (c == '0') return NULL;
		T = new BiTreeNode();
		T->data = c;
		T->weight = W[i++];
		T->lc = preCreate();
		T->rc = preCreate();
		return T;

	}
	int depth(BiTreeNode* p,int weight)
	{
		if (!p) return 0;
		weight += p->weight;
		if (weight > max) max = weight;
		depth(p->lc,weight);
		depth(p->rc, weight);
	}
	/*
	int PostOrder()
	{
		stack<BiTreeNode*> s;
		BiTreeNode* p = Root;
		BiTreeNode* r = NULL;
		int max=0;
		int wei = 0;
		while (p || !s.empty())
		{
			if (p)
			{
				s.push(p);
				wei += p->weight;
				if (max < wei) max = wei;
				p = p->lc;
			}
			else {
				p = s.top();
				if (p->rc&&p->rc != r)
				{
					p = p->rc;
					s.push(p);
					wei += p->weight;
					if (max < wei) max = wei;
					p = p->lc;
				}
				else {
					s.pop();
					wei-= p->weight;
					if (max < wei) max = wei;
					r = p;
					p = NULL;
				}
			}
		}
		return max;
	}
	*/
	void CreateT(string str)
	{
		i = 0;
		pos = 0;
		max = 0;
		Tstr = str;
		int n;
		cin >> n;
		W = new int[n];
		for (int i1 = 0; i1 < n; i1++)
			cin >> W[i1];
		Root = preCreate();
		//前序递归求最长路径
		depth(Root,0);
		cout << max << endl;
	}
	~BiTree()
	{
		pos = 0;
		delete Root;
		delete[] W;
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
		
	}
}
