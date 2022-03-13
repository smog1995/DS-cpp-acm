#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next,*prior;
		Node(int data1):data(data1){
		next=prior=NULL;
		}
		Node(){
			next=prior=NULL;
		}
}; 
class LinkList
{
	public:
		Node* head;
		int len;
		LinkList(int l){
			head=new Node(99999);
			len=l;
			Node* p=head;
			for(int i=0;i<len;i++)
			{
				Node* x=new Node();
				cin>>x->data;
				p->next=x;
				x->prior=p;
				p=p->next;
			}
			
			
		}
		void search(int k)
		{
			Node* p=head->next;
			while(p)
			{
				if(p->data==k) {
					if(p->prior&&p->prior!=head)cout<<p->prior->data<<" ";
					if(p->next)cout<<p->next->data<<" ";
					cout<<endl;
					break;
				}
				p=p->next;	
			}
		}
};
int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	LinkList L(n);
	while(m--)
	{
		int x;
		cin>>x; 
		L.search(x);
	} 
}
