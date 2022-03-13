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
//先序遍历
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
			InOrder(T->lchild);//递归遍历左子树
			visit(T);//访问根节点
			InOrder(T->rchild);//递归遍历右子树
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

//层次遍历
void LevelOrder(BiTree T)
{
	InitQueue(Q);//初始化辅助队列
	BigTree p;
	EnQueue(Q, T);//将根节点入队
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);//对头结点出队
		visit(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);//左子树不为空，则左子树根结点入队
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);//右子树不为空，则右子树根节点入队
	}

}
*/
