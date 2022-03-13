#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
	int key;        // 关键值 
	int left;       // 左子树地址（数组下标）
	int right;      // 右子树地址（数组下标）
	int height;     // 当前结点为根的子树高度
	void Init() { key = left = right = height = -1; }
	void Init(int k_) { Init(); key = k_; }
	Node() { Init(); }
	Node(int k_) { Init(k_); }
};
Node tr[maxn];
int root, tp, flag;

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

void Insert(int &now, int key)
{
	if (now == -1)
	{
		// 传入指针为空，新建结点保存数据
		now = ++tp;
		tr[now].Init(key);
	}
	// 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
	else {
		if (key < tr[now].key)
		{
			Insert(tr[now].left, key);
			if (HeightDiff(now) == 2)
			{
				if (key > tr[tr[now].left].key)
					now = LR(now);
				else now = LL(now);
			}

		}
		else if (key > tr[now].key)
		{
			Insert(tr[now].right, key);
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
int inorder(int r, int &k)
{
	int f;
	if (r == -1) return -1;
	f = inorder(tr[r].left, k);
	if (f != -1) return f;//已经得到结果，提前返回 
	k--;
	if (k == 0) {
		return tr[r].key;
	}
	f = inorder(tr[r].right, k);
	return f;
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
			cout << tr[now].key << endl;
			now = tr[now].right;
		}
		else if (tr[now].right == -1) {
			cout << tr[now].key << endl;
			now = tr[now].left;
		}
		else {
			int temp = tr[now].key;
			int nd = tr[now].left;
			while (tr[nd].right != -1)
				nd = tr[nd].right;
			tr[now].key = tr[nd].key;
			tr[nd].key = temp;
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
void in(int r)
{
	if (r == -1) return;
	in(tr[r].left);
	cout << tr[r].key << ":" << tr[r].height << " ";
	in(tr[r].right);

}
int main()
{
	int n, op, key, k;
	cin >> n;
	tp = root = -1;
	while (n--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> key;
			Insert(root, key);
			//in(0);
		}
		else {
			flag = 0;
			cin >> k;
			int ke = inorder(root, k);
			Delete(root, ke);
			if (!flag) cout << -1 << endl;
		}
		//in(root);
		//cout << endl;
	}
}