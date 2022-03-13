#include <iostream>
#include <queue>

using namespace std;


class TNode {
public:
	char data;
	TNode* lc, *rc;
	TNode() {
		lc = rc = NULL;
		data = '0';
	}
};
TNode* createTree()
{
	TNode* T;
	char x;
	cin >> x;
	if (x == '\n') return NULL;
	if (x == '0') {
		T = NULL;
	}
	else {
			T = new TNode();
		T->data = x;
		T->lc=createTree();
		T->rc=createTree();
	}
	return T;
}


void preorder(TNode* T)
{
	if (!T || T->data == '0') return;
	cout << T->data ;

	preorder(T->lc);
	preorder(T->rc);
}
void inorder(TNode* T)
{
	if (!T || T->data == '0') return;
	inorder(T->lc);
	cout << T->data ;
	inorder(T->rc);
}
void laorder(TNode* T)
{
	if (!T || T->data == '0') return;
	laorder(T->lc);

	laorder(T->rc);
	cout << T->data ;
}
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		TNode* T = createTree();
		preorder(T);
		cout << endl;
		inorder(T);
		cout << endl;
		laorder(T);
		cout << endl;
	}
}
