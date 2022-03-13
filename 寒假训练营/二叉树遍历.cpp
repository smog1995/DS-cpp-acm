#include <iostream>
using namespace std;
#define MAX 20000
struct Node
{
	Node()
	{
		degree = 0;
		parent = -1;
		lchild = rchild = -1;
	}
	int id,degree;
	int parent;
	int lchild, rchild;
};
int root = 0;
int Depth[MAX],Height[MAX];
void rec(Node t[], int root_id, int depth)
{
	Depth[root_id] = depth;
	if (t[root_id].rchild != -1) rec(t, t[root_id].rchild,depth+1);
	if (t[root_id].lchild != -1) rec(t, t[root_id].lchild,depth+1);
}
int height(Node t[],int u)
{
	if (u == -1) return 0;
	int lhigh = 0, rhigh = 0;
	if(t[u].lchild!=-1)
	lhigh = height(t,t[u].lchild);
	if(t[u].rchild!=-1)
	rhigh = height(t,t[u].rchild);
	return (Height[u] = (lhigh > rhigh) ? lhigh : rhigh);
}


Node t[MAX];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int id,rc,lc;
		cin >>id>> lc>>rc;
		t[i].id = id;
		t[i].lchild =lc;
		t[i].rchild =rc;
		if (lc != -1) t[i].degree++;
		if (rc != -1) t[i].degree++;
		if (lc != -1)
		t[lc].parent = i;
		if (rc != -1)
		t[rc].parent = i;
		
	}
	for (int i = 0; i < n; i++)
	{
		if (t[i].parent == -1) root = i;
	}
	rec(t, root,0);
	height(t, root);

}

/*
//�������
void PreOrder(BigTree T)
{
	if (T != NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
void InOrder(BigTree T)
{
	if (T != NULL)
	{
		if (T != NULL)
		{
			InOrder(T->lchild);//�ݹ����������
			visit(T);//���ʸ��ڵ�
			InOrder(T->rchild);//�ݹ����������
		}
	}
}
void PostOrder(BigTree T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

//��α���
void LevelOrder(BiTree T)
{
	InitQueue(Q);//��ʼ����������
	BigTree p;
	EnQueue(Q, T);//�����ڵ����
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);//��ͷ������
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);//��������Ϊ�գ�����������������
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);//��������Ϊ�գ������������ڵ����
	}

}
*/
