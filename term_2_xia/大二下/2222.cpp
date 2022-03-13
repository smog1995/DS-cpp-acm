#include <iostream>
using namespace std;

#define ok 9999999
#define error -9999999
class ListNode
{
public:
	int data;
	ListNode* next;
	ListNode() { next = NULL; }
};
class LinkList
{
public:
	ListNode *head;
	ListNode *tail;
	int len;
	LinkList() {
		head = new ListNode();
		len = 0;
		tail = head;
	}
	void LL_Insert( int x)
	{
		ListNode* s = new ListNode();
		s->data = x;
		tail->next = s;
		tail = s;
	}
	LinkList(int n)
	{
		head = new ListNode();
		ListNode *r = head;
		len = n;
		while (n--)
		{
			ListNode *s = new ListNode();
			cin >> s->data;
			r->next = s;
			r = s;
		}
		r->next = NULL;
	}
	~LinkList() {
		ListNode *p = head, *q;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
		}//头结点也要回收 
		len = 0;
		head = NULL;
	}
	void LL_merge(LinkList *Lb)
	{
		LinkList *Lc = new LinkList();
		ListNode* pa = head->next;
		ListNode* pb = Lb->head->next;
		ListNode* pc = Lc->head;
		while (pa&&pb)
		{
			if ((pa->data) > (pb->data))
			{
				pc->next = pb; pc = pb; pb = pb->next;
			}
			else
			{
				pc->next = pa; pc = pa; pa = pa->next;
			}
		}
		pc->next = pa ? pa : pb;
		Lc->LL_display();
	}
	void LL_display()
	{
		ListNode *p;
		p = head->next;
		while (p)
		{
			cout << p->data << ' ';
			p = p->next;
		}
		cout << endl;
	}
};
int main()
{
	int n, m;
	cin >> n;
	LinkList* La = new LinkList(n);
	cin >> m;
	LinkList* Lb = new LinkList(m);
	La->LL_merge(Lb);
}