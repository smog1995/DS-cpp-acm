#include <iostream>
#include<stdlib.h>
#include <string>
using namespace std;
#define elemtype int
typedef struct DNode
{
	elemtype e;
	struct DNode *next, *prior;
}DLinkList;
DLinkList* Init()
{
	DNode* L = new DNode;
	L->prior = L;
	L->next = L;
	return L;
}

DNode* GetElem(DLinkList* L,elemtype e)
{
	DNode* p = L->next;
	while(p!=NULL&&p->e!= e)
	{
		p = p->next;
	}
	return p;
}
void HeadInsert(DLinkList* L,elemtype e)
{
	DNode *s = new DNode;
	s->e = e;
	s->prior = L;
	s->next = s->next;
	L->next->prior = s;
	L->next = s;
}
void Delete(DNode* s)
{
	s->prior->next = s->next;
	s->next->prior = s->prior;
	delete s;
}
void LocateDelete(DLinkList* L,elemtype e)
{
	DNode* s = GetElem(L,e);
	Delete(s);
}

void HeadDelete(DLinkList* L)
{
	Delete(L->next);
}
/*
bool LastDelete(DLinkList* L)
{
	DNode* p = L->next;
	if (!p) return false;
	while (p!=NULL&&p->next != NULL)
	{
		p = p->next;
	}
	DNode* q = p->prior;
	q->next = NULL;
	free(p);
	return true;
}
*/
void LastDelete(DLinkList *L)
{
	delete(L->prior);
}
void Print(DLinkList* L)
{
	DNode* p = L->next;
	while (p)
	{
		cout << p->e;
		if (p->next != NULL) cout << " ";

		p = p->next;
	}
	cout << endl;

}
int main()
{
	int n;
	cin >> n;
	DLinkList* L = Init();
	while (n--)
	{
		string s;
		int x;
		cin >> s;
		if (s[NULL] == 'd'&&s[6] == 'F')
			HeadDelete(L);
		else if (s[NULL] == 'd'&&s[6] == 'L')
			LastDelete(L);
		else if (s.length() == 6)
		{
			cin >> x;
			if (s[NULL] == 'i')
			{
				HeadInsert(L, x);
			}
			else if (s[NULL] == 'd'&&s.length() == 6)
			{
				LocateDelete(L, x);
			}
		}

	}
	Print(L);
}