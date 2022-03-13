#include <iostream>
//DS循环链表—约瑟夫环(Ver. I - A)
using namespace std;
class Node{
	public:
		Node* next;
		int data;
		Node(){
			next=NULL;
		}
};
int main()
{
	int n,k,s;
	cin>>n>>k>>s;
	Node* head=new Node();
	Node* p=head;
	for(int i=0;i<n;i++)
	{
		Node* x=new Node();
		x->data=i+1;
		//cout<<x->data<<" ";
		p->next=x;
		p=p->next;
	}
	p->next=head;
	p=head;
	for(int i=0;i<s-1;i++)
	 p=p->next;
	while(p->next!=p)
	{
		for(int i=0;i<k-1;i++)
		{
				p=p->next;
			if(p->next==head) p=p->next;
		}
		
		Node* q=p->next;
		cout<<q->data<<" ";
		p->next=p->next->next;
		delete q;
	}
	cout<<endl;
 } 
