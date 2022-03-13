#include <iostream>
#include <string>
class TNode{
	public:
	char val;
	TNode* lc,*rc;
	TNode()
	{
		lc=rc=NULL;
	}
};
int i=0;
string str;
TNode* precreate()
{
	if(str[i++]=='#'||i>=str.length()) return NULL;
	TNode* T=new TNode();
	T->val=str[i];
	T->lc=precreate();
	T->rc=precreate();
	return T;
}
int max=0;
char x,y;
int depth(TNode* r)
{
	if(!r) return 0;
	int ld=depth(r->lc);
	int rd=depth(r->rc);
	if(ld+rd>max)
	{
		x=r->lc
	}
	return (ld>rd)?ld+1:rd+1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{

		cin>>str;
		TNode* T=precreate();
		
	}
}
