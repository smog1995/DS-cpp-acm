#include <iostream>
using namespace std;
#define ok 9999999
#define error -9999999
class ListNode
{
public:
	ListNode* next;
	int data;
	ListNode()
	{
		next = NULL;
	}
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
	int LL_insert(int i, int item)
	{
		ListNode* p = LL_index(i - 1);//获取前驱
		ListNode *s = new ListNode();
		if (!s || !p) return error;
		s->data = item;
		s->next = p->next;
		p->next = s;
		len++;
		return ok;
	}
	int LL_del(int i)
	{
		ListNode* p = LL_index(i - 1);
		if (!p)return error;
		ListNode* q = p->next;
		p->next = p->next->next;
		delete q;
		len--;
		return ok;
	}
	ListNode* LL_index(int i)
	{
		if (i < 0) return NULL;
		int j = 0;
		ListNode* p = head;
		while (p && j < i)
		{
			p = p->next;
			j++;
		}
		if (j > i) return NULL;
		return p;
	}
	void insert(ListNode* p, ListNode* s)
	{
		s->next = p->next;
		p->next = s;
	}
	void del(ListNode* p)
	{
		ListNode* q = p->next;
		p->next = q->next;
		delete q;
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
	void swap(int pa, int pb)
	{
		ListNode* p1 = LL_index(pa - 1);
		ListNode* p2 = LL_index(pb - 1);
		if (!p1 || !p2||!p1->next||!p2->next) cout << "error" << endl;
		else {
			ListNode* t = p1->next;
			p1->next = p2->next;
			p2->next = t;
			t = p1->next->next;
			p1->next->next = p2->next->next;
			p2->next->next = t;
			
			LL_display();
		}
	}
};
int main()
{
	int n;
	cin >> n;
	LinkList List(n);
	List.LL_display();
	int x, y;
	cin >> x >> y;
	List.swap(x,y);
	cin >> x >> y;
	List.swap(x, y);
}