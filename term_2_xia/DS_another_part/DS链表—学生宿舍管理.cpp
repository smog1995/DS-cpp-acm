#include <iostream>
#include <string>
using namespace std;
int count=0;//记录已用宿舍数量 
class ListNode
{
	public:
	int data;
	int cur;

	ListNode()
	{
		cur=0;
		data=-1;
	}
};
void InitL(ListNode *L)
{
	for(int i=0;i<22;i++)
	L[i].cur=i+1;
	L[21].cur=0;
}
int Malloc(ListNode *L)
{
	int i=L[0].cur;
	if(i) L[0].cur=L[i].cur;
	return i;
 }
void Free(ListNode *L,int x)
{
	L[x].data=-1;
	L[x].cur=L[0].cur;L[0].cur=x;
}

void display_free(ListNode *L,int S)
{
	int k=L[S].cur;
	while(k)
	{
		cout<<L[k].data;
		k=L[k].cur;
		if(k) cout<<"-";
	}
	cout<<endl;
}
void display_used(string *s)
{
	for(int i=1;i<21;i++)
	if(s[i]!="null") 
	{
		cout<<s[i]<<"("<<i+100<<")";
		count--;
		if(count)cout<<"-";
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	string Stu[21];
	ListNode L[22];
	InitL(L);
	int S=Malloc(L);
	int r=S;
	for(int i=1;i<=20;i++)//添加20个宿舍于静态链表中 
	{
		int i1=Malloc(L);
		L[i1].data=i+100;
		L[r].cur=i1;
		r=i1;
	}
	
	for(int i=0;i<21;i++)//初始化已用宿舍 
	Stu[i]="null";
	
	
	
	string name;
	int num;
	while(n--)
	{
		
		cin>>name>>num;
		Stu[num-100]=name;
		count++;
		int k=L[S].cur,p=S;
		while(num!=L[k].data&&k)
		{
			p=k;
			k=L[k].cur;
		}
		L[p].cur=L[k].cur;
		Free(L,k);
	}
	cin>>n;
	while(n--)
	{
		string oper;
		cin>>oper;
		if(oper=="assign")
		{
			cin>>name;
			int i=L[S].cur;
			Stu[L[i].data-100]=name;
			L[S].cur=L[i].cur;
			Free(L,i);			
		 	count++;
		 } 
		 
		 else if(oper=="return")
		 {
		 	cin>>num;
		 	Stu[num-100]="null";
		 	int i=Malloc(L);
		 	L[i].cur=0;L[i].data=num;
		 	L[r].cur=i;
		 	r=i;
		 	count--;
		 }
		 else if(oper=="display_free")
			display_free(L,S);
		 else if(oper=="display_used")
			display_used(Stu);
	 } 
	
}

 
