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
	int pos;//���򴮴�����ʱstrTree���ƶ��±�
	int max;//�������ڵ�֮���������
	BiTreeNode *target;//�ҵ������������Ľ���Ӧ�ĸ�
	BiTreeNode *targetLeft, *targetRight;//�����������Ľ��
	string strTree;//�����������ڵ���ַ���
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
	void search();//���������������Ľ�㲢��ӡ
};
int BiTree::depth(BiTreeNode* p)//���������ȵ�ͬʱ�����ҵ�����������ڵ��Ӧ�ĸ��Լ��������max
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
void BiTree::searchL(BiTreeNode* p)//�ҳ���ڵ�
{
	if (!p) return;
	if (!p->lc && !p->rc) {
		targetLeft = p;
	}
	searchL(p->lc);
	searchL(p->rc);
}
void BiTree::searchR(BiTreeNode* p)//�ҳ��ҽڵ�
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