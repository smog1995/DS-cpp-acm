#include <iostream>
using namespace std;

#define LH 1 // 左高 
#define EH 0 // 等高 
#define RH -1 // 右高 

class BiNode
{
public:
	int key; // 关键值
	int bf; // 平衡因子 
	BiNode *lChild, *rChild;
	BiNode(int kValue, int bValue)
	{

		key = kValue;
		bf = bValue;
		lChild = NULL;
		rChild = NULL;
	}

	~BiNode()
	{
		key = 0;
		bf = 0;
		lChild = NULL;
		rChild = NULL;
	}
};

// 二叉排序树
class BST
{
private:
	BiNode *root; // 根结点指针 
	void rRotate(BiNode *&p);
	void lRotate(BiNode *&p);
	void leftBalance(BiNode *&t);
	void rightBalance(BiNode *&t);
	int insertAVL(BiNode *&t, int key, bool &taller); // 插入元素并做平衡处理
	void inOrder(BiNode *p);
public:
	BST();
	void insertAVL(int key); // 二叉排序树插入元素 
	~BST();
	void inOrder(); // 中序遍历 
};

// 以p为根的二叉排序树作右旋处理 
void BST::rRotate(BiNode *&p)
{
	BiNode* lc;
	lc = p->lChild;
	p->lChild = lc->rChild;
	lc->rChild = p; p = lc;
}

// 以p为根的二叉排序树作左旋处理 
void BST::lRotate(BiNode *&p)
{
	// 参考课本236页算法9.10
	BiNode *rc;
	rc = p->rChild;
	p->rChild = rc->lChild;
	rc->lChild = p; p = rc;
}

// t为根的二叉排序树作左平衡旋转处理
void BST::leftBalance(BiNode *&t)
{
	// 参考课本238页算法9.12
	BiNode* lc = t->lChild;
	if (lc->bf == LH)
	{
		t->bf = lc->bf = EH;
		rRotate(t); 
	}
	else if (lc->bf == RH)
	{
		BiNode* rd = lc->rChild;
		if (rd->bf == LH) {
			t->bf = RH;
			lc->bf = EH;
		}
		else if (rd->bf == EH)
		{
			t->bf = lc->bf = EH;
		}
		else if (rd->bf == RH)
		{
			t->bf = EH;
			lc->bf = LH;
		}
		rd->bf = EH;
		lRotate(t->lChild);
		rRotate(t);
	}
}

// t为根的二叉排序树作右平衡旋转处理
void BST::rightBalance(BiNode *&t)
{
	// 参考课本238页算法9.12
	BiNode* rc = t->rChild;
	switch (rc->bf)
	{
	case LH: {//根右子树的左孩子需进行右旋
		BiNode* ld = rc->lChild;
		if (ld->bf == LH) {
			t->bf = EH; rc->bf = RH;
		}
		else if (ld->bf == EH)
		{
			t->bf = rc->bf = EH;
		}
		else
		{
			t->bf = LH; rc->bf = EH;
		}
		ld->bf = EH;
		rRotate(t->rChild);
		lRotate(t);
		
	}
	case RH:
	{
		t->bf = rc->bf = EH;
		lRotate(t); break;
	}
	}
}


int BST::insertAVL(BiNode *&T, int key, bool &taller)
{

	if (!T) {
		T = new BiNode(key,EH);
		taller = true;
	}
	else {
		if (T->key==key) {
			taller = false; return 0;
		}
		if (key < T->key)
		{
			if (!insertAVL(T->lChild, key, taller)) return 0;
			if(taller)
			switch (T->bf)
			{
			case LH:
				leftBalance(T); taller = false; break;
			case EH:
				T->bf = LH; taller = true; break;
			case RH:
				T->bf = EH; taller = false; break;
			}
		}
		else {
			if (!insertAVL(T->rChild, key, taller)) return 0;
			if (taller)
			{
				switch (T->bf)
				{
				case LH:
					T->bf = EH; taller = false; break;
				case EH:
					T->bf = RH; taller = true; break;
				case RH:
					rightBalance(T); taller = false; break;
				}
			}
		}
	}
}

void BST::inOrder(BiNode *p)
{
	if (p)
	{
		inOrder(p->lChild);
		cout << p->key << ':' << p->bf << ' ';
		inOrder(p->rChild);
	}

	return;
}


// 二叉排序树初始化
BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	root = NULL;
}

// 插入元素并作平衡处理
void BST::insertAVL(int key)
{
	bool taller = false;
	insertAVL(root, key, taller);
}


// 中序遍历
void BST::inOrder()
{
	inOrder(root);
}

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		// 构建二叉平衡树，并在插入元素时做平衡处理 
		int n, elem;
		cin >> n;
		BST tree;
		while (n--)
		{
			cin >> elem;
			tree.insertAVL(elem);
		}
		tree.inOrder();
		cout << endl;
	}

	return 0;
}
