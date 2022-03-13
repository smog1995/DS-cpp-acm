#include <iostream>
using namespace std;
class Node
{
public:
	int x;
	Node* next;
	Node() {
		next = NULL;
	}
};
class List
{
public:
	Node* head;
	List() {
		head = NULL;
	}
	void InitL(int n) {
		head = new Node();
		Node* r = head;
		for (int i = 0; i < n; i++)
		{
			Node* s = new Node();
			s->x=i+1;
			r->next = s;
			r = s;
		}
		r->next = head;
	}
};
int main()
{
	int N,K,S;
	cin>>N>>K>>S;
	List *L=new List();
	L->InitL(N);
	Node* p=L->head;//注意这里不能是为next！因为删除的为第一个节点时，需要指向head节点而不是第一个节点 
	for(int i=0;i<S-1;i++)//到达第S位的前一个节点 
	p=p->next;
	while(p->next!=p)
	{
		if(p->next==L->head) p=p->next;
		for(int i=0;i<K-1;i++)//因为是从第S位的前一位开始数，或者上一轮的前一位，所以是是从0开始，到达第K位的前一个节点
		{
			p=p->next;
			if(p->next==L->head)p=p->next;
		}
			Node* s=p->next;
			cout<<s->x<<" ";
			p->next=s->next; 	
			delete s;
	}
	
 } 
