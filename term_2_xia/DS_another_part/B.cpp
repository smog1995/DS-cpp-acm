#include <iostream>
#include <fstream>
using namespace std;
const int maxn= 1e5+10;
struct Node
{
	int data;
	int height;
	int left,right;
	int key;
	void Init(){data=key=left=right=height=-1;
	}
	void Init(int k_,int d_=0){
		Init();key=k_;data=d_;
	}
	
};
Node tr[maxn];

int GetLast(int now)
{
    if (now == -1 || tr[now].right == -1)return now;
    return GetLast(tr[now].right);
}
int root,tp,flag;
inline int UpdateHeight(int now)
{
    int lh=tr[tr[now].left].height==-1?0:tr[tr[now].left].height;
    int rh=tr[tr[now].right].height==-1?0:tr[tr[now].right].height;
    return (lh>rh?lh:rh)+1;
}
inline int HeightDiff(int now)
{
    int lh=tr[tr[now].left].height==-1?0:tr[tr[now].left].height;
    int rh=tr[tr[now].right].height==-1?0:tr[tr[now].right].height;
    return lh-rh;
}
int LL(int an)
{
	int lc=tr[an].left;
	tr[an].left=tr[lc].right;
	tr[lc].right=an;
	tr[an].height=UpdateHeight(an);
	tr[lc].height=UpdateHeight(lc);
	return lc;
}
int RR(int an)
{
	int rc=tr[an].right;
	tr[an].right=tr[rc].left;
	tr[rc].left=an;
	tr[an].height=UpdateHeight(an);
	tr[rc].height=UpdateHeight(rc);
	return rc;
}
int LR(int an)
{
	tr[an].left=RR(tr[an].left);
	return LL(an);
}
int RL(int an)
{
	tr[an].right=LL(tr[an].right);
	return RR(an);
}
void Insert(int &now, int key, int data=0)
{
    if(now == -1)
    {
        // 传入指针为空，新建结点保存数据
        now = ++ tp;
        tr[now].Init(key, data);
    }
    // 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
	else{
		if(key<tr[now].key)
		{
			Insert(tr[now].left,key,data);
			int t=HeightDiff(now);
			if(t==2)
			{
				if(key<tr[tr[now].left].key)
					now=LL(now);
				else now=LR(now);
			}
			
		}
		else if(key>tr[now].key)
		{
			Insert(tr[now].right,key,data);
			int t=HeightDiff(now);
			if(t==-2)
			{
				if(key>tr[tr[now].right].key)
					now=RR(now);
				else now=RL(now);
			}
		}
		UpdateHeight(now);
	}
}
void Delete(int &now, int key)
{
    if(now == -1){
    	return;
	}
    else if(key < tr[now].key) Delete(tr[now].left, key);
    else if(key > tr[now].key) Delete(tr[now].right, key);
    else
    {
        // 删除当前结点
        if(tr[now].left==-1) {
        	now=tr[now].right;
		}
        else if(tr[now].right==-1){
			now=tr[now].left;
		}
        else {
        	int t = GetLast(tr[now].left);
            tr[now].data = tr[t].data;
            tr[now].key = tr[t].key;
        	Delete(tr[now].left,tr[now].key);
		}
    }
    // 处理树平衡
    if(now==-1) 	return ;//删除该节点后，本节点就不需要更新高度了 
    UpdateHeight(now);
     if(HeightDiff(now) == 2)
        now = HeightDiff(tr[now].left) >= 0 ? 
            LL(now) : LR(now);
    else if(HeightDiff(now) == -2)
        now = HeightDiff(tr[now].right) <= 0 ? 
            RR(now) : RL(now);		
}
int findk(int r,int k)
{
	if(r==-1) return -1;
	int now=r;
	while(tr[now].key!=k&&now!=-1)
	{
		if(k<tr[now].key) now=tr[now].left;
		else if(k>tr[now].key) now=tr[now].right;
	}
	return now;
}
int GetFirst(int now)
{
    if (now == -1 || tr[now].left == -1) return now;
    return GetFirst(tr[now].left);
}
int find(int now, int key)
{
    while (now != -1 && tr[now].key != key)
    {
        if (key > tr[now].key)
        {
            now = tr[now].right;
        }
        else if (key < tr[now].key)
        {
            now = tr[now].left;
        }
    }
    return now;
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
                scanf("%d%d", &data, &key);
                Insert(root, key, data);
            }
            else if (op == 2)
            {
                int ith = GetLast(root);
                printf("%d\n", ith == -1 ? 0 : tr[ith].data);
                if (ith != -1)Delete(root, tr[ith].key);
            }
            else if (op == 3)
            {
                int ith = GetFirst(root);
                printf("%d\n", ith == -1 ? 0 : tr[ith].data);
                if (ith != -1) Delete(root, tr[ith].key);
            }
            else if (op == 4)
            {
                scanf("%d", &key);
                int ith = find(root, key);
                printf("%d\n", ith == -1 ? 0 : tr[ith].data);
                if (ith != -1) Delete(root, tr[ith].key);
            }
		}
		return 0;
	}
	of.close();
}
 
