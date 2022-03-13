#include <iostream>
using namespace std;
class Node{
	public:
		int x;
		Node* next;
	Node(){next=NULL;
	}
}; 
class List{
	public:
		Node* head;
		List(){
			head=NULL;
		}
		void InitL(int n)
		{
			int x;
			Node* r=head;
			for(int i=0;i<n;i++)
			{
				cin>>x;
				Node* s=new Node();
				s->x=x;
				r->next=s;
				r=s;
			}
			r->next=NULL;
		}
};
int main()
{
	int n1;int n2;
	cin>>n1;
	List *L1=new List(),*L2=new List();
	L1->InitL(n1);
	cin>>n2;
	L2->InitL(n2);
	
	//merge 
	List *L3=new List();
	Node* p3;
	L3->head=p3=L1->head;
	Node* p1=L1->head->next;
	Node* p2=L2->head->next;
	whlie(p1&&p2)
	{
		if(p1->x<p2->x){
			
			p3->next=p1;//因为如果之前结点是p2x小，则pc此时等于p2，next结点指向的是p2的下一个结点 
			p3=p1;
			p1=p1->next;
			
		} 
		else 
		{
			p3->next=p2;
			p3=p2;
			p2=p2->next; 
		}
	}
	p3->next=(p1)?p1:p2;
	 delete L2->head;
		
}
