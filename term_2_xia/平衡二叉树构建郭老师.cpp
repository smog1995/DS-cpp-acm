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
int root, tp;  // root Ϊ�ɱ�ĸ���tpȫ���ڴ�ָ�룬����ʼ��Ϊ-1
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
        if(tr[now].left == -1) now = tr[now].right;//������Ϊ�գ���ֻ�轫�ý���Ϊ������
        else if(tr[now].right == -1) now = tr[now].left;//������Ϊ��
        else
        {
            int nd;
            for(nd = tr[now].left; ; nd = tr[nd].right)//������������Ϊ�գ��ҵ������������½����֮������Ȼ��ɾ�������½��
                if(tr[nd].right == -1) break;
            tr[now].key = tr[nd].key;
            tr[now].data = tr[nd].data;
            Delete(tr[now].left, tr[nd].key);//���ҽ��ʵ����һ��û��������������ֻ������ɾ�������һ���������Һ��ӣ�һ����ֻ�����ӣ����ֶ���ʹ������ֵnow��Ϊ-1
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





