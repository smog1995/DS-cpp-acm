#include <iostream>
#include <string>
#include <cmath>
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
	int pos;//先序串创建树时strTree的移动下标
	int max;//树两个节点之间的最大距离
	BiTreeNode *target;//找到两个距离最大的结点对应的根
	BiTreeNode *targetLeft, *targetRight;//两个距离最大的结点
	string strTree;//用来创建树节点的字符串
	BiTreeNode* CreateBiTree();
	int depth(BiTreeNode* p);
	void searchL(BiTreeNode* p);
	void searchR(BiTreeNode* p);
public:
	BiTree() {
		pos = 0;
		max = 0;
	};
	~BiTree() {
		pos = 0;
		max = 0;

	};
	void CreateTree(string TreeArray);
	void search();//查找两个距离最大的结点并打印
};
int BiTree::depth(BiTreeNode* p)//算出树的深度的同时，将找到最大距离的两节点对应的根以及算出距离max
{
	if (!p) return 0;
	int ld = depth(p->lc);
	int rd = depth(p->rc);
	if (ld + rd > max)
	{
		max = ld + rd;
		target = p;
	}
	return (ld > rd) ? ld + 1 : rd + 1;
}
void BiTree::searchL(BiTreeNode* p)//找出左节点
{
	if (!p) return;
	if (!p->lc && !p->rc) {
		targetLeft = p;
	}
	searchL(p->lc);
	searchL(p->rc);
}
void BiTree::searchR(BiTreeNode* p)//找出右节点
{
	if (!p) return;
	if (!p->lc && !p->rc) targetRight = p;
	searchR(p->lc);
	searchR(p->rc);
}
void BiTree::search()
{
	depth(Root);
	if (!target) {
		cout << "0:" << endl;
		return;
	}
	searchL(target->lc);
	searchR(target->rc);
	cout << max << ":";
	if (targetLeft) cout << targetLeft->data << " ";
	else cout << target->data << " ";
	if (targetRight) cout << targetRight->data;
	else cout << target->data;
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
	if (pos >= strTree.length()) return NULL;
	char c = strTree[pos++];
	if ( c == '#')return NULL;
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
		T.search();
	}
}