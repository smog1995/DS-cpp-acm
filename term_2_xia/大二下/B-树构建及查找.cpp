#include <iostream>     
#include <queue> 
using namespace std;

int m;

class BTNode
{
public:
	int keyNum; // �ؼ��ָ��� 
	BTNode *parent; // ָ��˫�׽�� 
	int *keys; // �ؼ������� 
	BTNode **ptr; // ����ָ������ 
	BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = new int[m];
		ptr = new BTNode*[m];
	}

	~BTNode()
	{
		keyNum = 0;
		parent = NULL;
		keys = NULL;
		ptr = NULL;
	}
};

class Result
{
public:
	BTNode *pt; // ָ���ҵ��Ľ��
	int i;
	int tag;
	Result(BTNode *p, int m, int t)
	{
		pt = p;
		i = m;
		tag = t;
	}

	~Result()
	{
		pt = NULL;
		i = 0;
		tag = 0;
	}
};

class BTree
{
private:
	BTNode *root;
	void insert(BTNode *t, int i, int k, BTNode *ap); // ��k��ap�ֱ����t->key[i+1]��t->ptr[i + 1] 
	int search(BTNode *t, int k); // ��p->key[1...keynum]�в��� k
	void split(BTNode *q, int s, BTNode *&ap); // ��q->key[s+1...m],q->ptr[s...m]�����½��ap 
	void newRoot(BTNode *&t, BTNode *q, int x, BTNode *ap); // ���ɺ���Ϣ(t, x, ap)���¸����t*ap, ԭt�� apΪ����ָ��
	void insertBT(BTNode *&t, int k, BTNode *q, int i); // �ڽ��t���ӽ��q��key[i]��key[i+1]֮�����k 
	Result *searchBT(BTNode *t, int k); // �ڽ��t�в���k 
public:
	BTree();
	~BTree();
	void insertBT(int key); // B-��������� 
	void searchBT(int key); // B-�����Ҳ��� 
	void levelOrder(); // B-����α��� 
};

void BTree::insert(BTNode *t, int i, int k, BTNode *ap)
{
	// ��k��ap�ֱ����t->key[i+1]��t->ptr[i + 1]
	t->keyNum++;
	int j;
	for (j =t->keyNum; j >i+1; j--)
	{
		t->keys[j] = t->keys[j - 1];
	}
	t->keys[i + 1] = k;
	for (int j = t->keyNum + 1; j > i + 2; j--)
	{
		t->ptr[j] = t->ptr[j - 1];
	}
	t->ptr[i + 2] = ap;
	
}

int BTree::search(BTNode *t, int k)
{
	int i;
	for (i = t->keyNum; i >= 1 && k < t->keys[i]; i--)
		;
	return i;
	// ��p->key[1...keynum]�в��� k
	if (t->keys[1] > k)
	{
		for (int i = t->keyNum; i >=1; i--)
		{
			t->keys[i + 1] = t->keys[i];
		}
		for (int i = t->keyNum+1; i >= 1; i--)
		{
			t->ptr[i + 1] = t->ptr[i];
		}
		//key��1���ճ����ˣ����Խ��в���,ptr[1]Ҳ��,��<key[1]
		return 1;
	}
	for (int i = 1; i <= t->keyNum - 1; i++)
	{
		if (t->keys[i] <= k&&k < t->keys[i + 1]) return i + 1;

	}
	return 0;
}

void BTree::split(BTNode *q, int s, BTNode *&ap)
{
	// ��q->key[s+1...m],q->ptr[s...m]�����½��ap
	q->keyNum = s;
	for (int i = s + 1; i <= m; i++)
	{
		ap->keys[i-s] = q->keys[i];
	}
	ap->keyNum = m-s;
	for (int i = s; i <= m; i++)
		ap->ptr[i - s + 1] = q->ptr[i];

}


	void BTree::newRoot(BTNode *&t, BTNode *q, int x, BTNode *ap)
	{
		// ���ɺ���Ϣ(t, x, ap)���¸����t, ԭt�� apΪ����ָ��
		BTNode* newt = new BTNode();
		newt->keys[1] = x;
		newt->keyNum = 1;
		newt->ptr[1] = t;
		newt->ptr[2] = ap;
		t = newt;
	}

	Result *BTree::searchBT(BTNode *t, int k)
	{
		// �ο��α�240ҳ�㷨9.13
		BTNode* p = t,*q=NULL;
		int flag = 0;
		int i = 0;
		//���1���ùؼ��ִ��ڣ���ʱ���ص�r-��tagΪ1�������в���
		//���2����p=NULLʱ��������ʧ�ܣ����ص�r����tagΪ0������в���
		//q�������溬��ùؼ�����Ȼ������С��Χ�Ľ�㣬����ʧ��ʱp=NULL��qΪp�ĸ��ڵ㣬�ɹ�ʱp��Ϊ���ùؼ���k�Ľ��
		while (p && !flag)
		{
			i = search(p, k);
			if (i > 0 && p->keys[i] == k) flag = 1;
			else {
				q = p;
				p = p->ptr[i];
			}
		}
		if (flag) return new Result(p, i, 1);
		else return new Result(q, i, 0);
	}
	//tΪb������㣬kΪ�ؼ��֣�qΪ������λ�ã�iΪ�ؼ������(�ؼ��ֲ����λ�ã�
	void BTree::insertBT(BTNode *&t, int k, BTNode *q, int i)
	{
		// �ο��α�244ҳ�㷨9.14
		int x = k;
		BTNode* ap = NULL;
		int flag = 0;
		while (q && !flag)
		{
			insert(q, i, x, ap);
			if (q->keyNum < m) flag = 1;
			else {
				int s = (m / 2) + m % 2;
				split(q, s, ap);
				x = q->keys[s];
				q = q->parent;
				if (q) i = search(q, x);//����Ӧ�ý����ڵ�嵽����
			}
		}
		if (!flag) newRoot(t, q, x, ap);
		
	}

	// B����ʼ�� 
	BTree::BTree()
	{
		root = NULL;
	}

	BTree::~BTree()
	{
		root = NULL;
	}

	// B-���������
	void BTree::insertBT(int key)
	{
		Result *r = searchBT(root, key);
		if (!r->tag)
		{
			insertBT(root, key, r->pt, r->i);
		}
		return;
	}

	// B-�����Ҳ���
	void BTree::searchBT(int key)
	{
		Result *r = searchBT(root, key);
		if (!r->tag)
		{
			cout << "-1" << endl;
		}
		else
		{
			BTNode *p = r->pt;
			cout << p->keys[1];
			for (int i = 2; i <= p->keyNum; i++)
			{
				cout << ':' << p->keys[i];
			}
			cout << ' ' << r->i << endl;
		}
		return;
	}

	// B-����α�������ؼ��� 
	void BTree::levelOrder()
	{
		queue<BTNode*> tq;
		BTNode *p = root;
		// �׽����� 
		if (p)
		{
			tq.push(p);
		}
		// ��α����� 
		while (!tq.empty())
		{
			p = tq.front();
			tq.pop();
			// ������p��key 
			cout << p->keys[1];
			for (int i = 2; i <= p->keyNum; i++)
			{
				cout << ':' << p->keys[i];
			}
			cout << ' ';
			// �Խ����ջ 
			for (int i = 0; i <= p->keyNum; i++)
			{
				if (!p->ptr[i])
				{
					break;
				}
				tq.push(p->ptr[i]);
			}
		}
		return;
	}

	int main(void)
	{
		int t;
		cin >> t;
		while (t--)
		{
			cin >> m;
			int n, k, key;
			// ����B-�� 
			cin >> n;
			BTree bTree;
			while (n--)
			{
				cin >> key;
				bTree.insertBT(key);
			}
			// ����α������B-�� 
			bTree.levelOrder();
			cout << endl;
			// ����B-����� 
			cin >> k;
			while (k--)
			{
				cin >> key;
				bTree.searchBT(key);
			}
		}
		return 0;
	}