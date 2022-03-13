#include <iostream>
using namespace std;
#define Maxsize 50
typedef struct {
	ElemType data[Maxsize];
	int length;

}SqList;//˳�����Ա�
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




//��ʽ���Ա�
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
		//s->next = NULL;//Ϊʲô���ã���Ϊ�ڳ�ѭ����ֻ��һ�����ɽ���β����nextָ��NULL������Ϊ���һ����ӵĽ������һ�����ʱ�ܻ���nextָ��ô���ӵĽ��
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
	if (i == 0)return L;//Ϊ����
	if (i < 1)//����ֵ��Чʱ,������Ϊʲô��ֱ����<0
		return NULL;
	while (p&&j < i) {
		p = p->next;
		j++;
	}//�����������ȣ���Ϊΰ���p��next��NULL����᷵��NULL
	return p;//���ص�i������ָ��
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
//����������(�ҵ�ǰ����㣬�ں�����룩
bool IndexInsert(LinkList& L, int i)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	LNode* p = GetElem(L,i-1);//�ҵ�ǰ�����
	s->next = p->next;//ָ��p��next���
	p -> next = s;

	//��չ��ǰ�����

	//ֱ�ӽ�����Ľ���ֵ��������
	//ElemType temp=s->data;
	//s->data=p->data;
	//p->data=temp;

}



//˫������
typedef struct DNode
{
	Elemtype e;
	DNode *prior, *next;
}DNode,DLinkList;
//�������
//sΪ������Ľ�㣬pΪǰ�����
s->next = p->next;
p->next->prior = s;
s->prior = p;
p->next = s;