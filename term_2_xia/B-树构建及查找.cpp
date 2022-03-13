#include <iostream>     
#include <queue> 
using namespace std;

int m;

class BTNode
{
public:
	int keyNum; // 关键字个数 
	BTNode *parent; // 指向双亲结点 
	int *keys; // 关键字向量 
	BTNode **ptr; // 子树指针向量 
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
	BTNode *pt; // 指向找到的结点
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
	void insert(BTNode *t, int i, int k, BTNode *ap); // 将k和ap分别插入t->key[i+1]和t->ptr[i + 1] 
	int search(BTNode *t, int k); // 在p->key[1...keynum]中查找 k
	void split(BTNode *q, int s, BTNode *&ap); // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap 
	void newRoot(BTNode *&t, BTNode *q, int x, BTNode *ap); // 生成含信息(t, x, ap)的新根结点t*ap, 原t和 ap为子树指针
	void insertBT(BTNode *&t, int k, BTNode *q, int i); // 在结点t的子结点q的key[i]与key[i+1]之间插入k 
	Result *searchBT(BTNode *t, int k); // 在结点t中查找k 
public:
	BTree();
	~BTree();
	void insertBT(int key); // B-树插入操作 
	void searchBT(int key); // B-树查找操作 
	void levelOrder(); // B-树层次遍历 
};

void BTree::insert(BTNode *t, int i, int k, BTNode *ap)
{
	// 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
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
	// 在p->key[1...keynum]中查找 k
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
		//key【1】空出来了，可以进行插入,ptr[1]也是,即<key[1]
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
	// 将q->key[s+1...m],q->ptr[s...m]移入新结点ap
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
		// 生成含信息(t, x, ap)的新根结点t, 原t和 ap为子树指针
		BTNode* newt = new BTNode();
		newt->keys[1] = x;
		newt->keyNum = 1;
		newt->ptr[1] = t;
		newt->ptr[2] = ap;
		t = newt;
	}

	Result *BTree::searchBT(BTNode *t, int k)
	{
		// 参考课本240页算法9.13
		BTNode* p = t,*q=NULL;
		int flag = 0;
		int i = 0;
		//情况1：该关键字存在，此时返回的r-》tag为1，不进行插入
		//情况2：当p=NULL时，即查找失败，返回的r—》tag为0，会进行插入
		//q用来保存含与该关键字相等或距离最小范围的结点，查找失败时p=NULL，q为p的父节点，成功时p即为含该关键字k的结点
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
	//t为b树根结点，k为关键字，q为插入结点位置，i为关键字序号(关键字插入的位置）
	void BTree::insertBT(BTNode *&t, int k, BTNode *q, int i)
	{
		// 参考课本244页算法9.14
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
				if (q) i = search(q, x);//查找应该将父节点插到哪里
			}
		}
		if (!flag) newRoot(t, q, x, ap);
		
	}

	// B树初始化 
	BTree::BTree()
	{
		root = NULL;
	}

	BTree::~BTree()
	{
		root = NULL;
	}

	// B-树插入操作
	void BTree::insertBT(int key)
	{
		Result *r = searchBT(root, key);
		if (!r->tag)
		{
			insertBT(root, key, r->pt, r->i);
		}
		return;
	}

	// B-树查找操作
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

	// B-树层次遍历输出关键字 
	void BTree::levelOrder()
	{
		queue<BTNode*> tq;
		BTNode *p = root;
		// 首结点入队 
		if (p)
		{
			tq.push(p);
		}
		// 层次遍历树 
		while (!tq.empty())
		{
			p = tq.front();
			tq.pop();
			// 输出结点p的key 
			cout << p->keys[1];
			for (int i = 2; i <= p->keyNum; i++)
			{
				cout << ':' << p->keys[i];
			}
			cout << ' ';
			// 自结点入栈 
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
			// 构建B-树 
			cin >> n;
			BTree bTree;
			while (n--)
			{
				cin >> key;
				bTree.insertBT(key);
			}
			// 按层次遍历输出B-树 
			bTree.levelOrder();
			cout << endl;
			// 查找B-树结点 
			cin >> k;
			while (k--)
			{
				cin >> key;
				bTree.searchBT(key);
			}
		}
		return 0;
	}