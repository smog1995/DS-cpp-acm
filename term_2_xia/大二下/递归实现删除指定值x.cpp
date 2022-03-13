#include <iostream>
using namespace std;
class Node {
public:
	int x;
	Node* next;
	Node() {
		next = NULL;

	}
};
class List {
public:
	Node* head;

	List() {
		head = NULL;
	}
	void InitList()
	{
		int x;
		head = new Node();
		Node* r = head;
		for (int i = 0; i < 10; i++)
		{
			cin >> x;
			Node* s = new Node();
			s->x = x;
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}
	void display()
	{
		Node* p = head->next;
		while (p)
		{
			cout << p->x << " ";
			p = p->next;
		}
		cout << endl;
	}
};
void Deletex(Node* p, Node* q, int x1)
{
	if (q==NULL) return;
	if (q->x == x1) {
		Node* s = q;
		p->next = s->next;
		delete s;
		Deletex(p, p->next, x1);
	}
	else
	{
		Deletex(q, q->next, x1);
	}
}

int main()
{
	List *L = new List();
	L->InitList();
	Deletex(L->head, L->head->next, 3);
	L->display();
}