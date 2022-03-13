#include <iostream>
#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
	int key;        // 关键值
	int data;       // 携带的数据
	int left;       // 左子树地址（数组下标）
	int right;      // 右子树地址（数组下标）
	int height;     // 当前结点为根的子树高度
	void Init() { data = key = left = right = height = -1; }
	void Init(int k_, int d_ = 0) { Init(); key = k_; data = d_; }
	Node() { Init(); }
	Node(int k_, int d_ = 0) { Init(k_, d_); }
};
Node tr[maxn];
int root, tp, flag;
int max(int x, int y)
{
	return x > y ? x : y;
}
inline int UpdateHeight(int now)
{
	int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
	return tr[now].height = (lh > rh ? lh : rh) + 1;
}
inline int HeightDiff(int now)
{
	int lh = tr[tr[now].left].height == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[tr[now].right].height == -1 ? 0 : tr[tr[now].right].height;
	return lh - rh;
}
int LL(int k1)
{
	int k2 = tr[k1].left;
	tr[k1].left = tr[k2].right;
	tr[k2].right = k1;
	UpdateHeight(k1);
	UpdateHeight(k2);
	return k2;
}
int RR(int k2)
{
	int k1 = tr[k2].right;
	tr[k2].right = tr[k1].left;
	tr[k1].left = k2;
	UpdateHeight(k2);
	UpdateHeight(k1);
	return k1;
}
int LR(int k3)
{
	tr[k3].left = RR(tr[k3].left);
	return LL(k3);
}
int RL(int k4)
{
	tr[k4].right = LL(tr[k4].right);
	return RR(k4);
}

void Insert(int &now, int key, int data )
{
	if (now == -1)
	{
		// 传入指针为空，新建结点保存数据
		now = ++tp;
		tr[now].Init(key, data);
	}
	// 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
	else {
		if (key < tr[now].key)
		{
			Insert(tr[now].left, key, data);
			if (HeightDiff(now) == 2)
			{
				if (key > tr[tr[now].left].key)
					now = LR(now);
				else now = LL(now);
			}

		}
		else if (key > tr[now].key)
		{
			Insert(tr[now].right, key, data);
			if (HeightDiff(now) == -2)
			{
				if (key > tr[tr[now].right].key)
					now = RR(now);
				else now = RL(now);
			}

		}
	

	}
		UpdateHeight(now);
}
void  Delete(int &now, int key)
{
	if (now == -1) return;
	else if (key < tr[now].key) Delete(tr[now].left, key);
	else if (key > tr[now].key) Delete(tr[now].right, key);
	else
	{
		// 删除当前结点
		flag = 1;
		if (tr[now].left == -1) {
			cout << tr[now].data << endl;
			now = tr[now].right;
		}
		else if (tr[now].right == -1) {
			cout << tr[now].data << endl;
			now = tr[now].left;
		}
		else {
			int temp = tr[now].data;
			int nd = tr[now].left;
			while (tr[nd].right != -1)
				nd = tr[nd].right;
			tr[now].data = tr[nd].data;
			tr[now].key = tr[nd].key;
			tr[nd].data = temp;
			Delete(tr[now].left, tr[nd].key);
		}

	}
	// 处理树平衡
	if (now == -1) return;
	else {
		UpdateHeight(now);
		if (HeightDiff(now) == 2)
		{
			tr[tr[now].left].left >= 0 ? LL(now) : LR(now);
		}
		else if (HeightDiff(now) == -2)
			tr[tr[now].right].right >= 0 ? RR(now) : RL(now);
		
	}
}

int findmin()
{
	if (root == -1) return 0;
	int nd = root;
	while (tr[nd].left != -1) nd = tr[nd].left;
	return tr[nd].key;
}
int findmax()
{
	if (root == -1) return 0;
	int nd = root;
	while (tr[nd].right != -1) nd = tr[nd].right;
	return tr[nd].key;
}
int main()
{
	int n, op, key, data;
	while (scanf("%d", &n) != EOF)
	{
		for (root = tp = -1; n--; )  // 初始化根结点和“内存指针”
		{

			scanf("%d", &op);
			if (op == 1)
			{
				cin >> data >> key;
				Insert(root, key, data);
			}
			else if (op == 2)
			{
				int maxk = findmax();
				if (!maxk) cout << 0 << endl;
				else Delete(root, maxk);
			}
			else if (op == 3)
			{
				int mink = findmin();
				if (!mink) cout << 0 << endl;
				else Delete(root, mink);
			}
			else if (op == 4)
			{
				cin >> key;
				flag = 0;
				Delete(root, key);
				if (!flag) cout << 0 << endl;

			}
		}
		return 0;
	}
}
