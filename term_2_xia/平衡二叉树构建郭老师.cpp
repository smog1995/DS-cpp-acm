#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
struct Node
{
	int key;
	int data;
	int left;
	int right;
	int height;
	void Init() { data = key = left = right = height = -1; }
	void Init(int k_, int d_ = 0) { Init(); key = k_; data = d_; }
	Node() { Init(); }
	Node(int k_, int d_ = 0) { Init(k_, d_); }
};
Node tr[maxn];
int root, tp;  // root 为可变的根，tp全局内存指针，都初始化为-1
inline int UpdateHeight(int now)
{
	int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
	return tr[now].height = (lh > rh ? lh : rh) + 1;
}
inline int HeightDiff(int now)
{
	int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
	int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
	return lh - rh;
}
int LL(int an)
{
    int bn = tr[an].left;
    int dn = tr[bn].right;
    tr[bn].right = an;
    tr[an].left = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}
int RR(int an)
{
    int bn = tr[an].right;
    int dn = tr[bn].left;
    tr[bn].left = an;
    tr[an].right = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
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
void Insert(int &now, int key, int data=0)
{
    if(now == -1)
    {
        now = ++ tp;
        tr[now].Init(key, data);
    }
    else if(key < tr[now].key)
    {
        Insert(tr[now].left, key, data);
        if(HeightDiff(now) == 2)
            now = key < tr[tr[now].left].key ? 
                LL(now) : LR(now);
    }
    else if(key > tr[now].key)
    {
        Insert(tr[now].right, key, data);
        if(HeightDiff(now) == -2)
            now = key > tr[tr[now].right].key ? 
                RR(now) : RL(now);
    }
    UpdateHeight(now);
}
void Delete(int &now, int key)
{
    if(now == -1) return;
    else if(key < tr[now].key) Delete(tr[now].left, key);
    else if(key > tr[now].key) Delete(tr[now].right, key);
    else
    {
        if(tr[now].left == -1) now = tr[now].right;//左子树为空，则只需将该结点变为右子树
        else if(tr[now].right == -1) now = tr[now].left;//右子树为空
        else
        {
            int nd;
            for(nd = tr[now].left; ; nd = tr[nd].right)//左右子树均不为空，找到左子树最右下结点与之交换，然后删除最右下结点
                if(tr[nd].right == -1) break;
            tr[now].key = tr[nd].key;
            tr[now].data = tr[nd].data;
            Delete(tr[now].left, tr[nd].key);//最右结点实际上一定没有右子树，所以只有两种删除情况，一种是无左右孩子，一种是只有左孩子，两种都会使得其结点值now变为-1
        }
    }
    if(now == -1) return;
    UpdateHeight(now);
    if(HeightDiff(now) == 2)
        now = HeightDiff(tr[now].left) >= 0 ? 
            LL(now) : LR(now);
    else if(HeightDiff(now) == -2)
        now = HeightDiff(tr[now].right) <= 0 ? 
            RR(now) : RL(now);
}





