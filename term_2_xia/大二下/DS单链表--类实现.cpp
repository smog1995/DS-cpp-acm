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
		ListNode *p=head, *q;
		while (p)
		{
			q = p;
			p = p->next;
			delete q;
		}//头结点也要回收 
		len = 0;
		head = NULL;
	}
	ListNode* LL_index(int i)
	{
		if (i < 0) return NULL;
		int j = 0;
		ListNode* p = head;
		while (p&&j < i)
		{
			p = p->next;
			j++;
		}
		return p;//若超过len也返回NULL，为0也返回NULL 
	}
	int LL_get(int i)
	{
		if (i < 1) return error;
		int j = 1;
		ListNode* p = head->next;
		while (p&&j < i)
		{
			p = p->next;
			j++;
		}
		if (j > i) return error;
		return p->data;
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
void show(LinkList& L, int s)
{
	if (s == error) cout << "error" << endl;
	else L.LL_display();
}
int main()
{
	int n;
	cin >> n;
	LinkList List(n);
	List.LL_display();
	int idx, x;
	cin >> idx >> x;
	show(List, List.LL_insert(idx, x));
	cin >> idx >> x;
	show(List, List.LL_insert(idx, x));
	cin >> idx;
	show(List, List.LL_del(idx));
	cin >> idx;
	show(List, List.LL_del(idx));
	cin >> idx;
	ListNode* p = List.LL_index(idx);
	if (!p || p == List.head) cout << "error" << endl;
	else cout << p->data << endl;
	cin >> idx;
	p = List.LL_index(idx);
	if (!p || p == List.head) cout << "error" << endl;
	else cout << p->data << endl;
}