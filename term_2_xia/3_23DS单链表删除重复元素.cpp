#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	int length;
	Node() {
		length = 0;
		next = NULL;
	}

};


Node* CreateL(int n)
{
	Node* L = new Node();
	Node * r = L;
	L->length = n;
	int x;
	for (int i = 0; i < n; i++)
	{
		Node* s = new Node();
		cin >> x;
		s->data = x;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}

Node* del(Node* L,int x,int &f)
{
	Node* p = L->next, *q = L;
	while (p&&p->data != x)
	{
		q = p;
		p = p->next;
	}
	if (!p) return NULL;
	if (p->data == x)
	{
		q->next = p->next;
		delete p;
		f = 1;
	}
	return q;
}
void Del(Node* L)
{
	Node* p = L->next;
	while (p)
	{
		int x = p->data;
		Node* F = p;
		while (F)
		{
			int f = 0;
			F = del(F,x,f);
			if (f) L->length--;
		}
		p = p->next;
	}
}
void display(Node* L)
{
	cout << L->length << ": ";
	Node* p = L->next;
	for (int i = 0; p; i++)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		
		cin >> n;
		Node* L = CreateL(n);
		Del(L);
		display(L);
	}
}