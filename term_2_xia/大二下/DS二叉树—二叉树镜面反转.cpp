#include <iostream>
using namespace std;
class BiTreeNode
{
public:
	char data;
	BiTreeNode* lc, *rc;
	BiTreeNode()
	{
		lc = rc = NULL;
	}
};
class BiTree {
private:
	int pos;
	BiTreeNode* Root;
	BiTreeNode* preCreate()
	{
		char c;
		BiTreeNode* T;
		cin >> c;
		if (c == '#' || c == '\n') T = NULL;
		else {
			T = new BiTreeNode();
			T->data = c;
			T->lc = preCreate();
			T->rc = preCreate();
		}
		pos++;
		return T;

	}
	void PostOrder(BiTreeNode* p)
	{
		if (!p) return;
		PostOrder(p->lc);
		PostOrder(p->rc);
		cout << p->data << " ";
	}
	void InOrder(BiTreeNode* p)
	{
		if (!p) return;
		InOrder(p->lc);
		cout << p->data << " ";
		InOrder(p->rc);
	}
	void PreOrder(BiTreeNode* p)
	{
		if (!p)return;
		cout << p->data << " ";
		PreOrder(p->lc);
		PreOrder(p->rc);
	}
	void LevelOrder() {
		BiTreeNode **que = new BiTreeNode*[pos];
		int front = 0, rear = 0;
		que[rear++] = Root;
		while (front < rear)
		{
			BiTreeNode* p = que[front++];
			cout << p->data << " ";
			if (p->lc) que[rear++] = p->lc;
			if (p->rc) que[rear++] = p->rc;
		}
		delete[] que;
		cout << endl;
	}
public:
	void FoutOrder()
	{
		Reverse(Root);
		if (!Root) {
			for(int i=0;i<4;i++)
			cout << "NULL" << endl;

			return;
		}
		PreOrder(Root);
		cout << endl;
		InOrder(Root);
		cout << endl;
		PostOrder(Root);
		cout << endl;
		LevelOrder();
	}
	void Reverse(BiTreeNode* p)
	{
		if (!p) return;
		Reverse(p->lc);
		Reverse(p->rc);
		BiTreeNode* temp;
		temp = p->rc;
		p->rc = p->lc;
		p->lc = temp;
	}
	
	void CreateT()
	{
		pos = 0;
		Root = preCreate();
	}
	~BiTree()
	{
		pos = 0;
		delete Root;
	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		BiTree T;
		T.CreateT();
		T.FoutOrder();
	}
}
