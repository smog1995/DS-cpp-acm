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
	Node* p=L->head;//ע�����ﲻ����Ϊnext����Ϊɾ����Ϊ��һ���ڵ�ʱ����Ҫָ��head�ڵ�����ǵ�һ���ڵ� 
	for(int i=0;i<S-1;i++)//�����Sλ��ǰһ���ڵ� 
	p=p->next;
	while(p->next!=p)
	{
		if(p->next==L->head) p=p->next;
		for(int i=0;i<K-1;i++)//��Ϊ�Ǵӵ�Sλ��ǰһλ��ʼ����������һ�ֵ�ǰһλ���������Ǵ�0��ʼ�������Kλ��ǰһ���ڵ�
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
