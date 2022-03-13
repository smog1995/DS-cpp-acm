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
	int len;
	LinkList() {
		head = new ListNode();
		len = 0;
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
	void LL_merge( LinkList *Lb)
	{
		LinkList *Lc=new LinkList();
		ListNode* pa = head->next;
		ListNode* pb = Lb->head->next;
		ListNode* r = Lc->head;
		while (pa&&pb)
		{
			if ((pa->data) > (pb->data))
			{
				ListNode* s = new ListNode();
				s->data = pb->data;
				r->next = s;
				r = s;
				pb = pb->next;
			}
			else
			{
				ListNode* s = new ListNode();
				s->data = pa->data;
				r->next = s;
				r = s;
				pa = pa->next;
			}
		}
		while (pa)
		{
			ListNode* s = new ListNode();
			s->data = pb->data;
			r->next = s;
			r = s;
			pb = pb->next;
		}
		while (pb)
		{
			ListNode* s = new ListNode();
			s->data = pa->data;
			r->next = s;
			r = s;
			pa = pa->next;
		}
		r->next = NULL;
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
	LinkList* Lb=new LinkList(m);
	La->LL_merge(Lb);
}