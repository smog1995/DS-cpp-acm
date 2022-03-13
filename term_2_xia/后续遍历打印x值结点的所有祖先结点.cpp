#include <iostream>
#include <queue>

int top = -1;
using namespace std;
class TNode {
public:
	int val;
	TNode *lc, *rc;
	TNode() {
		lc = rc = NULL;
	}
};
typedef struct {
	TNode *T;
	int tag;

}stack;
stack Stack[1000];
void postOrder(TNode* r, int x)
{
	TNode* p = r;
	while (p || top != -1)
	{
		while (p&&x != p->val)//操作1，将结点入栈 
		{
			Stack[++top].T = p;
			Stack[top].tag = 0;
			p = p->lc;
		}
		if (p&&p->val == x) {//操作2，访问操作，即若结点值为 
			while (top != -1)
			{
				cout << Stack[top--].T->val << " ";
			}
			break;
		}
		while (top !=-1 && Stack[top].tag == 1)//
			top--;
		if (top != -1)//栈顶结点的右孩子还未访问 
		{
			Stack[top].tag = 1;//设置为1表示访问过右孩子(下一条语句就是访问右孩子） 
			p = Stack[top].T->rc;//然后再来循环时，如果右孩子不为空，就会进行访问（即操作1和操作2） 
		}
	}
}
int i = -1;
//先序序列创建二叉树
TNode* createT(int c[])
{
	TNode* T = new TNode();
	if (!c[++i] || i >= 10)  return NULL;
	T->val = c[i];
	T->lc = createT(c);
	T->rc = createT(c);
	return T;
}
void pre(TNode* r)
{
	if (!r) return;
	cout << r->val << " ";
	pre(r->lc);
	pre(r->rc);
}
int main()
{
	int c[10];
	for (int i = 0; i < 10; i++)
		cin >> c[i];
	TNode* r = createT(c);
	pre(r);
	cout << endl;
	postOrder(r, 8);
}