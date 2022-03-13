#include <iostream>
using namespace std;
class pNode{
public:
	int xs;
	int e;
	pNode* next;
	pNode(){next=NULL;
	}
	pNode(int xs1,int e1):xs(xs1),e(e1){
		next=NULL;
	}
};
pNode* createL()
{
	pNode* L=new pNode();
	 L->next=NULL;
	 pNode* r=L;
	int n;
	cin>>n;
	while(n--)
	{
		int x,e;
		cin>>x>>e;
		pNode* s=new pNode(x,e);
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return L;
}
pNode* del(pNode* p,pNode* q)
{
	pNode* s=q;
	p->next=q->next;
	q=q->next;
	delete s;
}
pNode* add(pNode* L1,pNode* L2)
{
	pNode* L3=new pNode();
	pNode* p3=L3;
	pNode* h1=L1,*p1=h1->next;
	pNode* h2=L2,*p2=h2->next;
	pNode* s;
	while(p1&&p2)
	{
		if((p1->e)<(p2->e))
		{
			p3->next=p1;p3=p1;h1=p1;p1=p1->next;
		}
		else if((p1->e)==(p2->e))
		{
			if((p1->xs)==-(p2->xs)) 
			{
				h1=p1;p1=p1->next;
				h2=p2;p2=p2->next;
			}
			else 
			{
				p1->xs+=p2->xs;
				p3->next=p1;
				p3=p1;
				h1=p1;
				p1=p1->next;
				h2=p2;
				p2=p2->next;
//				s=p2;
//				h2->next=p2->next;
//				delete s; 
			}
		}
		else 
		{
			p3->next=p2;p3=p2;
			h2=p2;
			p2=p2->next;
		}
	}
	p3->next=(!p1)?p1:p2;
}
void display(pNode* L)
{
	pNode* p=L->next;
	while(p)
	{
		//不考虑系数为0 
		
		if(p->xs>0)cout<<(p->xs);
		else cout<<"("<<(p->xs)<<")";
		if(p->e>0) cout<<"x^"<<p->e;
		else if(p->e<0) cout<<"x^"<<"("<<(p->e)<<")";
		if(p->next)cout<<"+"; 
		p=p->next;
	}
	cout<<endl;
 } 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		pNode* L1=createL(),*L2=createL();
		display(L1);
		display(L2);
		add(L1,L2);
		display(L1);
		
	}
	 
}
 
