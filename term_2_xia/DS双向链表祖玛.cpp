#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
class Node
{
public:
	char c;
	Node* next, *prior;
	Node() {
		next = prior = NULL;
	}
};
class ListNode {

public:
	Node* head;
	ListNode() {
		head = NULL;
	}
	void createL()
	{
		head = new Node();
		Node* r = head;
		char x[10000];
		cin >> x;
		int len = strlen(x);
		for(int i=0;i<len;i++)
		{
			Node* s = new Node();
			s->c = x[i];
			s->prior = r;
			r->next = s;
			r = s;
		}
	}
	void insertL(int idx, char c)
	{
		int i = 0;
		Node* p = head;
		while (p&&i < idx)
		{
			p = p->next;
			i++;
		}
		if (p)
		{
			Node* s = new Node();
			s->c = c;
			s->next = p->next;
			if (s->next)
				s->next->prior = s;
			s->prior = p;
			p->next = s;
		}
		
	}

	void remove()
	{
		Node* p = head->next;
		int flag = 0;
		char c;
		int num = 0;
		while (p)
		{
			if (num==0) c = p->c;
			if (p->c == c)
			{
				num++;
			}
			else {
				num = 1;
				c = p->c;
				
			}
			if (num >= 3)
			{
				Node *s = p;
				for (int i1 = 0; i1 < num; i1++)
					s = s->prior;
				while(s->next&&s->next->c==c)
				{
					delL(s);
				}
				flag = 1;
			}
			
			
			p = p->next;
			if (flag == 1)
			{
				p = head;
				flag = 0;
			}
		}
		
	}
	void delL(Node* p)
	{
		Node *s = p->next;
		p->next = s->next;
		if (s->next) s->next->prior = p;
		delete s;
	}
	void display()
	{
		if (!head->next)
		{
			cout << "-" << endl;
			return;
		}
		Node* p = head->next;
		while (p)
		{
			cout << p->c;
			p = p->next;
		}
		cout << endl;
	}
	~ListNode()
	{
		Node* p = head;
		while (p)
		{
			Node* s = p->next;
			p->next = s->next;
			delete s;
		}
		delete head;
	}
};
int main()
{
	ListNode* L = new ListNode();
	L->createL();
	int n;
	cin >> n;
	while (n--)
	{
		
		int x; char c;
		cin >> x >> c;

		L->insertL(x, c);
		L->remove();
		L->display();
	}
}

