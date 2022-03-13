#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Node
{
	int key;
	Node *prev, *next;
};


//Á´±í³õÊ¼»¯
void Init(Node *L)
{
	L = new Node();
	L->prev = L;
	L->next = L;
	e= -1;
}
Node* listSearch(Node *L,int key)
{
	Node* cur = L->next;
	while (cur&&cur->key != key)
		cur = cur->next;
	return cur;
}
void Insert(Node* L,int key)
{
	Node* s = new Node();
	s->key = key;
	s->next = L->next;
	L->next->prev = s;
	s->prev = L->next;
	L->next = s;

}
void Delete(Node* L)
{
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
}
void deleteFirst(Node* L)
{
	Delete(L->next);
}
void deleteLast(Node* L)
{
	Delete(L->prev);
}
void deleteKey(Node* L, int key)
{
	Node* s=listSearch(L, key);
	Delete(s);
}

