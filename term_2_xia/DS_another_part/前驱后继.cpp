#include <iostream>
using namespace std;
class Node
{
	public:
		int key;
		Node* next, *prior;
		Node(){
			prior=next=NULL;
			
		}
};
class ListNode
{
	public:
		Node* head;
		int length;
		ListNode(){
			length=0;
			head=NULL;
		} 
		~ListNode()
		{
			Node* p=head;
			while(p)
			{
				Node* s=p->next;
				p->next=s->next;
				delete p;
			}
			delete head;
		}
	void createL(int n)
	{
		length=n;
		head=new Node();
		Node* r=head;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			Node* s=new Node();
			s->key=x;
			r->next=s;
			s->prior=r;
			r=s;
		}
	}
	
	void search(int key)
	{
		
    Node* p=head->next;
    while(p&&p->key!=key)
		{
			p=p->next;
		}
		if(p)
		{
			if(p->prior&&p->prior!=head) 
			{
				cout<<p->prior->key;
				if(p->next)
				cout<<" "<<p->next->key;
				cout<<endl; 
			}
			else if(p->next)cout<<p->next->key<<endl;
			
		}
/*
		Node* p=head->next;
		while(p!=NULL)
    {
        if(p->key==key)
        {
            if(p->prior!=head&&p->next!=NULL)
                printf("%d %d\n",p->prior->key,p->next->key);
            else if(p->prior==head)
                printf("%d\n",p->next->key);
            else if(p->next==NULL)
                printf("%d\n",p->prior->key);
        }
        p=p->next;
        
    }
    ---------------------------------------------------------------
    
		while(p&&p->key!=key)
		{
			p=p->next;
		}
		if(p)
		{
			if(p->prior&&p->prior!=head) 
			{
				cout<<p->prior->key;
				if(p->next)
				cout<<" "<<p->next->key;
				cout<<endl; 
			}
			else if(p->next)cout<<p->next->key<<endl;
			
		}
		*/
	}
} ;

	
	
int main()
{
	ListNode *L=new ListNode();
	int n,m;
	cin>>n>>m;
	L->createL(n);
	while(m--)
	{
		int key;
		cin>>key;
		L->search(key);
	}
}
