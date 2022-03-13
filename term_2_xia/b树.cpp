
#include <iostream>
#include <queue>
using namespace std;

struct B_Node;

struct Node //每个书中节点中的序列用链表实现，这里是链表的小单元
{
	int v;// 每个位置对应的权值
	B_Node* ptr;// 每个位置对应的下一层节点
	Node* nxt;
	Node() { ptr = NULL; nxt = NULL; v = 0; }
	Node(int v_) { ptr = NULL; nxt = NULL; v = v_; };
	void add(int v_)
	{
		Node* box = nxt;
		nxt = new Node(v_);
		nxt->nxt = box;
	}
};

struct B_Node //B树的节点
{
	int size; //节点的大小
	B_Node* parent;//父节点
	Node* list;//用链表实现的序列
	B_Node()
	{
		size = 1;
		parent = NULL;
		list = new Node();
		list->nxt = new Node(2147483647); //因为原定义中指向下一层的指针和权值是交错的，不太好处理，所以这里用一个极大值当作最后一个权值
										  //这样Node中的 v 和 ptr 的关系就可以理解为：ptr指向的节点中所有的权值都小于 v
	}
	B_Node(Node* l, int s)//用于拆分后在同层生成新节点
	{
		parent = NULL;
		list = new Node();
		size = s;
		list->nxt = l;
	}
	Node* find(int v_)//在节点中找到最后一个小于 v 的权值的位置
	{
		Node* cur = list;
		for (; cur->nxt != NULL && cur->nxt->v < v_; cur = cur->nxt);
		return cur;
	}
	~B_Node()
	{
		Node* cur = list;
		Node* net;
		while (cur != NULL)
		{
			net = cur->nxt;
			delete cur;
			cur = net;
		}
	}
};

struct B_Tree
{
	B_Node* root;
	int m;
	B_Tree() { root = NULL; m = 0; }
	B_Tree(int m_) { B_Tree(); m = m_; root = new B_Node(); }
	void Insert(int v) //插入一个新值
	{
		B_Node* cur = root;//从根节点开始找
		Node* pre=NULL;
		bool flag = 1;
		while (flag)//不停深入直到找到叶子节点
		{
			pre = cur->find(v);
			if (pre->nxt->ptr == NULL) flag = 0;//下一层没有节点 说明找到了叶子节点，此时pre就是待插入的位置
			else cur = pre->nxt->ptr;
		}
		pre->add(v);
		cur->size++;
		Update(cur);//维护
	}
	void Update(B_Node* cur)
	{
		if (cur->size <= m) return;// 该层合法
		int mid = (cur->size + 1) / 2; //确定准备弹上去的节点的位置
		Node* p = cur->list;//此时p准备存的是要弹上去的节点的位置
		for (int i = 1; i <= mid; i++)//找到要弹上去的权值
		{
			p = p->nxt;
		}
		int curv = p->v;//记录权值
		B_Node* now = new B_Node(p->nxt, cur->size - mid);//把右半部分生成为一个新节点
		cur->size = mid;//修改左半部分的大小
		p->nxt = NULL;
		if (cur->parent == NULL)//如果没有父节点 就新建一个
		{
			cur->parent = new B_Node();
			root = cur->parent;//更新根节点
			cur->parent->list->nxt->ptr = cur; //cur的父节点的第一个子节点是cur
		}
		now->parent = cur->parent; //右面新生成的节点认一下爹
		cur = cur->parent;//现在cur的含义变成了刚刚的父节点（为了少想一个变量名
		p = cur->find(curv);//现在p的含义变成了准备弹上去的权值待插入的位置
		p->add(curv);
		cur->size++;
		p->nxt->ptr = p->nxt->nxt->ptr; //弹上去的权值指向裂开后的左面
		p->nxt->nxt->ptr = now;//弹上去的权值右面的权值指向裂开后的右面
		Update(cur);//递归更新
	}
	void print()// bfs输出
	{
		queue<B_Node*> q;
		q.push(root);
		while (!q.empty())
		{
			B_Node* cur = q.front();
			q.pop();
			if (cur == NULL) continue;
			Node* p = cur->list->nxt;
			for (int i = 1; i <= cur->size; i++)
			{
				if (i < cur->size)
				{
					if (i != 1) cout << ':';
					cout << p->v;
				}
				q.push(p->ptr);
				p = p->nxt;
			}
			cout << ' ';
		}
		cout << '\n';
	}
	void Search(int v) //查找
	{
		B_Node* cur = root;
		while (1)
		{
			if (cur == NULL)// 没找到
			{
				cout << "-1" << endl;
				return;
			}
			Node* p = cur->list->nxt;
			for (int i = 1; i <= cur->size; i++)//遍历节点
			{
				if (p->v == v)//如果找到了就原地输出
				{
					p = cur->list->nxt;
					for (int j = 1; j < cur->size; j++)
					{
						if (j != 1) cout << ':';
						cout << p->v;
						p = p->nxt;
					}
					cout << ' ' << i << endl;
					return;//看我成功开溜！
				}
				if (p->v > v)//向深处搜索
				{
					cur = p->ptr;
					break;
				}
				p = p->nxt;
			}
		}
	}
	~B_Tree()
	{
		queue<B_Node*> q;
		q.push(root);
		while (!q.empty())
		{
			B_Node* cur = q.front();
			q.pop();
			if (cur == NULL) continue;
			Node* p = cur->list->nxt;
			for (int i = 1; i < cur->size; i++)
			{
				q.push(p->ptr);
				p = p->nxt;
			}
			delete cur;
		}
	}
};

int main()
{
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int m, n;
		cin >> m >> n;
		B_Tree bt = B_Tree(m);
		for (int i = 1; i <= n; i++)
		{
			int num;
			cin >> num;
			bt.Insert(num);
		}
		bt.print();
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int num;
			cin >> num;
			bt.Search(num);
		}
	}
	return 0;
}