#include <iostream>
using namespace std;

#define LH 1 // ��� 
#define EH 0 // �ȸ� 
#define RH -1 // �Ҹ� 

class BiNode
{
public:
	int key; // �ؼ�ֵ
	int bf; // ƽ������ 
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

// ����������
class BST
{
private:
	BiNode *root; // �����ָ�� 
	void rRotate(BiNode *&p);
	void lRotate(BiNode *&p);
	void leftBalance(BiNode *&t);
	void rightBalance(BiNode *&t);
	int insertAVL(BiNode *&t, int key, bool &taller); // ����Ԫ�ز���ƽ�⴦��
	void inOrder(BiNode *p);
public:
	BST();
	void insertAVL(int key); // ��������������Ԫ�� 
	~BST();
	void inOrder(); // ������� 
};

// ��pΪ���Ķ������������������� 
void BST::rRotate(BiNode *&p)
{
	BiNode* lc;
	lc = p->lChild;
	p->lChild = lc->rChild;
	lc->rChild = p; p = lc;
}

// ��pΪ���Ķ������������������� 
void BST::lRotate(BiNode *&p)
{
	// �ο��α�236ҳ�㷨9.10
	BiNode *rc;
	rc = p->rChild;
	p->rChild = rc->lChild;
	rc->lChild = p; p = rc;
}

// tΪ���Ķ�������������ƽ����ת����
void BST::leftBalance(BiNode *&t)
{
	// �ο��α�238ҳ�㷨9.12
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

// tΪ���Ķ�������������ƽ����ת����
void BST::rightBalance(BiNode *&t)
{
	// �ο��α�238ҳ�㷨9.12
	BiNode* rc = t->rChild;
	switch (rc->bf)
	{
	case LH: {//�����������������������
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


// ������������ʼ��
BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	root = NULL;
}

// ����Ԫ�ز���ƽ�⴦��
void BST::insertAVL(int key)
{
	bool taller = false;
	insertAVL(root, key, taller);
}


// �������
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
		// ��������ƽ���������ڲ���Ԫ��ʱ��ƽ�⴦�� 
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
