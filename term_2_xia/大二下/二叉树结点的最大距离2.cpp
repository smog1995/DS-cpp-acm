#include <iostream>
#include <string>
#include <stack>
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
	int M[100];
	char L[100];
	char R[100];
	int pos;
	int I;
	int deep;
	int depth(BiTreeNode* r);
	string strTree;
	BiTreeNode* target;
	int max;
	BiTreeNode* CreateBiTree();
	void countdeep(BiTreeNode *p, int i,char &c);
	void GetMLR(BiTreeNode* t);
	void PostOrder(BiTreeNode* root, char &targetN, int &maxc);
public:
	BiTree() {
		pos = 0;
		deep = 0;
		max = 0;
	};
	~BiTree() {
		pos = 0;
		deep = 0;
		max = 0;
		I = 0;
		delete Root;
		delete target;


	};

	void CreateTree(string TreeArray);
	void Post();
};
void BiTree::countdeep(BiTreeNode *p, int  i,char& c)
{
	if (p)
	{
		i++;
		if (p->lc == NULL && p->rc== NULL)
		{
			if (deep < i)
			{
				deep = i;
				c = p->data;
			}
		}
		countdeep(p->lc, i,c);
		countdeep(p->rc, i,c);
	}
}
int BiTree::depth(BiTreeNode* r)
{
	if (!r) return 0;
	int ld = depth(r->lc);
	int rd = depth(r->rc);
	if (ld + rd > max)
	{
		max = ld + rd;
		GetMLR(r);
	}
	return (ld > rd) ? ld + 1 : rd + 1;
}
void BiTree::GetMLR(BiTreeNode* target)
{
	int left = 0, right = 0;
	char r = '0', l = '0';
	countdeep(target->lc, 0, l);
	left = deep;
	deep = 0;
	countdeep(target->rc, 0, r);
	right = deep;
	M[I] = left + right;
	if(l!='0')
	L[I] = l;
	else L[I] = target->data;
	if(r!='0')
	R[I] = r;
	else R[I] = target->data;
	I++;
}
void BiTree::Post()
{
	depth(Root);
	int Max = 0;
	for (int i = 0; i < I; i++)
	{
		if (M[Max] < M[i]) Max = i;
	}
	cout << M[Max] << ":";
	if (M[Max])
		cout << L[Max] << " " << R[Max] ;
	cout << endl;
	
}

void BiTree::CreateTree(string TreeArray)
{
	strTree.assign(TreeArray);
	Root = CreateBiTree();
}
BiTreeNode* BiTree::CreateBiTree()
{
	BiTreeNode* T;
	char c = strTree[pos];
	pos++;
	if (c == '#') return NULL;
	T = new BiTreeNode();
	T->data = c;
	T->lc = CreateBiTree();
	T->rc = CreateBiTree();
	return T;
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
		T.Post();

	}
}