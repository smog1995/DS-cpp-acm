#include <iostream>
using namespace std;
int MaxSize=1000;
class LinkList
{
	int data;
	int cur;
	LinkList(){
		
	}
 } 
 LinkList L[MaxSize];
 void Free(LinkList& L,int k)
 {
 	L[k].cur=L[0].cur;L[0].cur=k; 
  } 
int Malloc(LinkList& L)
{
	int i=L[0].cur;
	if(i) L[0].cur=L[i].cur;//�����ÿռ�����ǿ��򷵻ؽ���±꣬����Ϊ0 
	return i;
}
void InitSpace(LinkList& L)
{
	for(int i=0;i<MaxSize-1;i++)
	L[i].cur=i+1;//���һλ��Ϊ-1 
	L[MaxSize-1].cur=0;
}
int LocateElem(LinkList& L,int e)
{
	int i=L[0].cur;
	while(i&&e!=L[i].data)//���iΪ0˵����β���ˣ�β��ָ��ָ��0����ֱ�ӷ��� 
	{
		i=L[i].cur;
	}
	return i;
}
void difference(LinkList& L,int &S )
{
	InitSpace(L);
	S=Malloc_SL(L);
	r=S;
	int m,n;
	cin>>m>>n;
	int x;
	while(m--)
	{
		
		cin>>x;
		int i=Malloc(L);
		if(i) L[i].data=x;
		L[r].cur=i;r=i;
	}
	L[r].cur=0;
	whlie(n--)
	{
		cin>>x;p=S;k=L[S].cur;
		while(L[k].data!=x&&k) 
		{
			p=k;
			k=L[k].cur;
		}
		if(!k)
		{
			int i=Malloc(L);
			L[i].data=x;
			L[r].cur=i;r=i;
		}
		else
		{
			L[p].cur=L[k].cur;
			Free(k);
			if(r==k) r=p;
		}
	}
}
