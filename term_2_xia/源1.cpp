#include <iostream>
#include <stack>
using namespace std;
class Node {
public:
	Node* lc, *rc;
	int data;
};
class Tree {
public:
	postOrder(Node* r)
	{
		stack<Node*> s;
		Node* p = r;
		Node* re = NULL;
		while (p || !s.empty())
		{
			if (p)
			{
				s.push(p);
				p = p->lc;
			}
			else {
				Node* p = s.top();
				if (p->rc&&p->rc != re)
				{
					p = p->rc;
					s.push(p);
					
				}
				else {
					cout << p->data << " ";
					s.pop();
					re = p;
					p = NULL;
				}
			}
		}
		int pos;
		Node* CreateT(string str)
		{
			Node* root = NULL;
			char c = str[pos++];
			if (pos >= str.length()||c=='#') return NULL;
			else {
				root = new Node();
				root->data = c;
				root->lc = CreateT(str);
				root->rc = CreaterT(str);
			}
			return root;
		}
	}
	
	
};
int main()
{

}