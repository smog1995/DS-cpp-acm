#include <iostream>
using namespace std;
#define Maxsize 50
typedef struct {
	ElemType data[Maxsize];
	int length;

}SqList;//顺序线性表
bool ListInsert(SqList &L, int i, ElemType e)
{
	if (i<1 || i>L.length + 1) return false;
	if (L.length >= MaxSize) return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;
	L.length++;
	return true;
}
bool ListDelete(SqList &L, int i, ElemType e)
{
	if (i<1 || i>L.Length + 1) return false;
	if (L.length >= Maxsize) return false;
	for (int j = i; j <=L.length;j++ )
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}




//链式线性表
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;



LinkList List_HeadInsert(LinkList &L)
{
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
LinkList List_TailInsert(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	int x;
	LNode* s, *r = L;
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		r->next = s;
		//s->next = NULL;//为什么不用，因为在出循环后，只需一步即可将链尾结点的next指向NULL，而不为最后一次添加的结点在下一次添加时总会令next指向该次添加的结点
		r = s;
		s->data = x;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}
LNode* GetElem(LinkList L, int i)
{
	int j = 1;
	LNode* p = L->next;
	if (i == 0)return L;//为链首
	if (i < 1)//索引值无效时,疑问是为什么不直接是<0
		return NULL;
	while (p&&j < i) {
		p = p->next;
		j++;
	}//若超出链表长度，会为伟结点p的next即NULL，则会返回NULL
	return p;//返回第i个结点的指针
}
LNode* LocateElem(LinkList L, ElemType e)
{
	LNode* p = L->next;
	while (p != NULL && p->data != e)//
	{
		p = p->next;
	}
	return p;
}
//按索引插入(找到前驱结点，在后面插入）
bool IndexInsert(LinkList& L, int i)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	LNode* p = GetElem(L,i-1);//找到前驱结点
	s->next = p->next;//指向p的next结点
	p -> next = s;

	//扩展：前插操作

	//直接将插入的结点的值互调即可
	//ElemType temp=s->data;
	//s->data=p->data;
	//p->data=temp;

}



//双向链表
typedef struct DNode
{
	Elemtype e;
	DNode *prior, *next;
}DNode,DLinkList;
//插入操作
//s为将插入的结点，p为前驱结点
s->next = p->next;
p->next->prior = s;
s->prior = p;
p->next = s;