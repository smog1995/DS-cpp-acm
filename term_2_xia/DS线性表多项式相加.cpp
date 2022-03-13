#include <iostream>
using namespace std;
class pNode {
public:
	int xs;
	int e;
	pNode* next;
	pNode* head;
	pNode() {
		head = this;
		next = NULL;
	}
	pNode(int xs1, int e1) :xs(xs1), e(e1) {
		next = NULL;
		head = this;
	}
};
pNode* createL()
{
	pNode* L = new pNode();
	L->next = NULL;
	pNode* r = L->head;
	int n;
	cin >> n;
	while (n--)
	{
		int x, e;
		cin >> x >> e;
		pNode* s = new pNode(x, e);
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}
void display(pNode* L)
{
	pNode* p = L->next;
	while (p)
	{
		//不考虑系数为0 

		if (p->xs > 0)cout << (p->xs);
		else cout << "(" << (p->xs) << ")";
		if (p->e > 0) cout << "x^" << p->e;
		else if (p->e < 0) cout << "x^" << "(" << (p->e) << ")";
		if (p->next)cout << " + ";
		p = p->next;
	}
	cout << endl;
}
void add(pNode* L1, pNode* L2)
{
	pNode* h1 = L1->head, *h2 = L2;
	pNode* p1 = L1->next;
	pNode* p2 = L2->next;
	pNode* s;
	while (p1&&p2)
	{
		if ((p1->e) < (p2->e))
		{
			h1 = p1; p1 = p1->next;
		}
		else if ((p1->e) == (p2->e))
		{
			if ((p1->xs) + (p2->xs) == 0)
			{
				s = p1;
				h1->next = p1->next;
				p1 = p1->next;
				delete s;
				
			}
			else
			{
				p1->xs += p2->xs;
				h1 = p1;
				p1 = p1->next;
				
			}
			s = p2;
			h2->next = p2->next;
			p2 = p2->next;
			delete s;
		}
		else
		{
			h2->next = p2->next;
			p2->next = h1->next;
			h1->next = p2;
			h1 = p2;
			p2 = h2->next;
		}
	}
	h1->next = (p1!=NULL) ? p1 : p2;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		pNode* L1 = createL(), *L2 = createL();
		display(L1);
		display(L2);
		add(L1, L2);
		display(L1);

	}

}
