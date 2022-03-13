#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(){next=NULL;
		}
};
class LinkList{
	public:
		Node* head;
		int len;
		LinkList();
		~LinkList()
		{
			while(head)
			{
				Node* x=head->next;
				delete head;
				head=x;
			}
		}
		Node* LL_index(int i)
		{
			if(i<0||i>len) return NULL;
			Node* p=head;
			for(int j=0;j<i;j++)
			p=p->next;
			return p;
		}
		int LL_get(int i)
		{
			if(i<1||i>len) return -1;
			Node* p=head;
			for(int j=0;j<i;j++)
			p=p->next;
			return p->data;			
		}
		int LL_insert(int i,int item)
		{
			if(i<0||i>len) return -1;
			Node* p=LL_index(i-1);
			Node* x=new Node();
			x->data=item;
			x->next=p->next;
			p->next=x;
			len++;
			return 1;
		}
		int LL_del(int i)
		{
			if(i<0||i>len) return -1;
			Node* p=LL_index(i-1);
			Node* x=p->next;
			p->next=x->next;
			len--;
			delete x; 
			return 1;
		}
		int  swap(int pa,int pb)
		{
			if(pa<1||pa>len||pb<1||pb>len) {
				cout<<"error"<<endl;
				return -1;
			}
			Node* p1=LL_index(pa-1);
			Node* p2=LL_index(pb-1);
			
			Node* x=p1->next ;
			p1->next=p2->next;
			p2->next=x;
			x=p1->next->next;
			p1->next->next=p2->next->next;
			p2->next->next=x;
			return 1;
		}
		void LL_display()
		{
			Node* p=head->next;
			while(p)
			{
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<endl;
		}
}; 
LinkList::LinkList()
{
	int n;
	cin>>n;
	len=n;
	head=new Node();
	Node* p=head;
	for(int i=0;i<n;i++)
	{
		Node* x=new Node();
		cin>>x->data;
		p->next=x;
		p=p->next;	
	}
	
}
using namespace std;
int main()
{
	LinkList L;
	int x,y;
	cin>>x>>y;
	int p=L.swap(x,y);
	if(p==1)L.LL_display();
}
