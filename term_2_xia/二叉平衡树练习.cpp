#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
	int data;
	int height;
	int left, right;
	int key;
	void Init() {
		data = key = left = right = height = -1;
	}
	void Init(int k_, int d_ = 0) {
		Init(); key = k_; data = d_;
	}

};
Node tr[maxn];
int root, tp, flag;
inline int UpdateHeight(int now)
{
	int lh = tr[tr[now].left].height == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[tr[now].right].height == -1 ? 0 : tr[tr[now].right].height;
	return (lh > rh ? lh : rh) + 1;
}
inline int HeightDiff(int now)
{
	int lh = tr[tr[now].left].height == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[tr[now].right].height == -1 ? 0 : tr[tr[now].right].height;
	return lh - rh;
}
int LL(int an)
{
	int lc = tr[an].left;
	tr[an].left = tr[lc].right;
	tr[lc].right = an;
	tr[an].height = UpdateHeight(an);
	tr[lc].height = UpdateHeight(lc);
	return lc;
}
int RR(int an)
{
	int rc = tr[an].right;
	tr[an].right = tr[rc].left;
	tr[rc].left = an;
	tr[an].height = UpdateHeight(an);
	tr[rc].height = UpdateHeight(rc);
	return rc;
}
int LR(int an)
{
	tr[an].left = RR(tr[an].left);
	return LL(an);
}
int RL(int an)
{
	tr[an].right = LL(tr[an].right);
	return RR(an);
}
void Insert(int &now, int key, int data = 0)
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
				if (key < tr[tr[now].left].key)
					now = LL(now);
				else now = LR(now);
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
		UpdateHeight(now);
	}
}
void Delete(int &now, int key)
{
	if (now == -1) {
		return;
	}
	else if (key < tr[now].key) Delete(tr[now].left, key);
	else if (key > tr[now].key) Delete(tr[now].right, key);
	else
	{
		// 删除当前结点
		if (tr[now].left == -1) {
			now = tr[now].right;
		}
		else if (tr[now].right == -1) {
			now = tr[now].left;
		}
		else {
			int nd = tr[now].left;
			while (tr[nd].right != -1)
				nd = tr[nd].right;
			int temp = tr[now].key;
			tr[now].data = tr[nd].data;
			tr[now].key = tr[nd].key;
			tr[nd].key = temp;
			Delete(tr[now].left, tr[nd].key);
		}
	}
	// 处理树平衡
	if (now == -1) 	return;//删除该节点后，本节点就不需要更新高度了 
	UpdateHeight(now);
	if (HeightDiff(now) == 2)
		now = HeightDiff(tr[now].left) >= 0 ?
		LL(now) : LR(now);
	else if (HeightDiff(now) == -2)
		now = HeightDiff(tr[now].right) <= 0 ?
		RR(now) : RL(now);
}
int findk(int r, int k)
{
	if (r == -1) return -1;
	int now = r;
	while (tr[now].key != k && now != -1)
	{
		if (k < tr[now].key) now = tr[now].left;
		else if (k > tr[now].key) now = tr[now].right;
	}
	return now;
}
int findmin(int r)
{
	if (r == -1) return -1;
	int nd = r;
	while (tr[nd].left != -1) nd = tr[nd].left;
	return nd;
}
int findmax(int r)
{
	if (r == -1) return -1;
	int nd = r;
	while (tr[nd].right != -1) nd = tr[nd].right;
	return nd;
}
int main()
{
	ofstream of;
	of.open("1.txt");

	int n, op, key, data;
	while (scanf("%d", &n) != EOF)
	{
		for (root = tp = -1; n--; )  // 初始化根结点和“内存指针”
		{
			flag = 0;
			scanf("%d", &op);
			if (op == 1)
			{
				cin >> data >> key;
				Insert(root, key, data);

			}
			else if (op == 2)
			{
				int maxk = findmax(root);
				if (maxk != -1)
				{
					Delete(root, tr[maxk].key);
					of << tr[maxk].data << endl;
				}
				else of << 0 << endl;
			}
			else if (op == 3)
			{
				int mink = findmin(root);
				if (mink != -1)
				{
					Delete(root, tr[mink].key);
					of << tr[mink].data << endl;
				}
				else of << 0 << endl;
			}
			else if (op == 4)
			{
				cin >> key;
				int x = findk(root, key);
				if (x != -1)
				{
					Delete(root, tr[x].key);
					of << tr[x].data << endl;
				}
				else of << 0 << endl;
			}
		}
		return 0;
	}
	of.close();
}
