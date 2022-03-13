#include <iostream>
#include <string>
#include <stack>
using namespace std;
class TNode {
public:
	int weight;
	char val;
	TNode* lc, *rc;
	TNode() {
		lc = rc = NULL;
		weight = 0;
	}

};
int *c;
string str;
int i = 0, i1 = 0;
int wpl = 0;
TNode* preCreate()
{
	TNode* T = new TNode();
	if (str[i] == '0' || i >= str.length()) {
		i++;
		return NULL;
	}
	if (str[i] >= 'A'&&str[i] <= 'Z') T->weight = c[i1++];
	T->val = str[i++];
	T->lc = preCreate();
	T->rc = preCreate();
	return T;
}
int height(TNode* p, char c)
{
	stack<TNode*> s;
	TNode* r=NULL;
	s.push(p);
	int h = 0;
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
				s.pop();
				if (p->val == c)
				{
					while (!s.empty())
					{
						s.pop();
						h++;
					}
					break;
				}
				r = p;
				p = NULL;
			}
		}
	}
	return h;
}

void pre(TNode* p, TNode* r)
{
	if (!p) return;
	if (p->weight)
	{
		wpl = wpl + (p->weight)*(height(r, p->val)-1);
	}
	pre(p->lc, r);
	pre(p->rc, r);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		i = 0; i1 = 0; wpl = 0;
		cin >> str;
		int n;
		cin >> n;
		c = new int[n];
		for (int i1 = 0; i1 < n; i1++)
			cin >> c[i1];
		TNode* r = preCreate();
		i = 0;
		pre(r, r);
		cout << wpl << endl;

	}
}