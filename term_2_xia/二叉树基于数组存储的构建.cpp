#include <iostream>
#include <string>
using namespace std;
class BiTreeNode {
public:
	char data;
	BiTreeNode *lc;
	BiTreeNode *rc;
	BiTreeNode() :lc(NULL), rc(NULL) {

	}
	~BiTreeNode() {
		delete lc;
		delete rc;
	}
};
class BiTree {
private:
	BiTreeNode *Root;
	int pos;
	string strTree;
	BiTreeNode* CreateBiTree(int i);
	void pre(BiTreeNode* p);
public:
	BiTree() {
		pos = 0;
	};
	~BiTree() {
	};
	void pre()
	{
		pre(Root);
	}
	void CreateTree(string TreeArray);
};
void BiTree::CreateTree(string TreeArray)
{
	strTree.assign(TreeArray);
	Root = CreateBiTree(0);
}
BiTreeNode* BiTree::CreateBiTree(int i)
{
	BiTreeNode* T;
	if ( i>= strTree.length()||strTree[i] == '0' )T = NULL;
	else {
		T = new BiTreeNode();
		T->data = strTree[i];
		T->lc = CreateBiTree(2 * i + 1);
		T->rc = CreateBiTree(2 * i + 2);
	}
	return T;
}
void BiTree::pre(BiTreeNode* p)
{
	if (!p) return;
	cout << p->data;
	pre(p->lc);
	pre(p->rc);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		BiTree T;
		string str;
		cin >> str;
		T.CreateTree(str);
		T.pre();
		cout << endl;
	}
}