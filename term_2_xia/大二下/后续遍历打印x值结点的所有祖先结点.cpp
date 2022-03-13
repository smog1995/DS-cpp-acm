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
		while (p&&x != p->val)//����1���������ջ 
		{
			Stack[++top].T = p;
			Stack[top].tag = 0;
			p = p->lc;
		}
		if (p&&p->val == x) {//����2�����ʲ������������ֵΪ 
			while (top != -1)
			{
				cout << Stack[top--].T->val << " ";
			}
			break;
		}
		while (top !=-1 && Stack[top].tag == 1)//
			top--;
		if (top != -1)//ջ�������Һ��ӻ�δ���� 
		{
			Stack[top].tag = 1;//����Ϊ1��ʾ���ʹ��Һ���(��һ�������Ƿ����Һ��ӣ� 
			p = Stack[top].T->rc;//Ȼ������ѭ��ʱ������Һ��Ӳ�Ϊ�գ��ͻ���з��ʣ�������1�Ͳ���2�� 
		}
	}
}
int i = -1;
//�������д���������
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