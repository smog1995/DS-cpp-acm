#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class BiTreeNode {
public:
	char data;
	int depth;
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
	int target;//�ҵ������������Ľ���Ӧ�ĸ�
	int targetLeft, targetRight;//�����������Ľ��
	int ldeep, rdeep;
	string strTree;//�����������ڵ���ַ���
	string Array;//��������洢
	BiTreeNode* CreateBiTree();
	void pre(BiTreeNode* p);
	int depth(int i);
	void pre1(int len, int i, BiTreeNode* p);
	void searchL(int i);
	void searchR(int i);
public:
	BiTree() {
		pos = 0;
		max = 0;
		ldeep = 0;
		rdeep = 0;

	};
	~BiTree() {
		pos = 0;
		max = 0;
		ldeep = 0;
		rdeep = 0;
		delete Root;
	};
	void Height(BiTreeNode* r, int root)
	{
		if (!r) return;
		r->depth = log(root + 1) / log(2);
		Height(r->lc, root * 2 + 1);
		Height(r->rc, root * 2 + 2);

	}
	void pre()
	{
		pre(Root);
	}
	int depth1(BiTreeNode* p);
	void ArrayStore();//��������洢��
	void CreateTree(string TreeArray);
	void search();//���������������Ľ�㲢��ӡ
};
void BiTree::ArrayStore()
{
	int len = pow(2, depth1(Root));
	Array.assign(len, '0');
	pre1(len, 0, Root);
	//cout << Array << endl;
}
void BiTree::pre1(int len, int i, BiTreeNode* p)//����������������洢����
{
	if (i >= len) return;
	if (p)
	{
		Array[i] = p->data;
		pre1(len, 2 * i + 1, p->lc);
		pre1(len, 2 * i + 2, p->rc);
	}
}
int BiTree::depth1(BiTreeNode* p)
{
	if (!p) return 0;
	int ld = depth1(p->lc);
	int rd = depth1(p->rc);
	return (ld > rd) ? ld + 1 : rd + 1;
}
int BiTree::depth(int i)//���������ȵ�ͬʱ�����ҵ�����������ڵ��Ӧ�ĸ��Լ��������max
{
	if (i >= Array.length() || Array[i] == '0') return 0;
	int ld = depth(2 * i + 1);
	int rd = depth(2 * i + 2);
	if (ld + rd > max)
	{
		max = ld + rd;
		target = i;
	}
	return (ld > rd) ? ld + 1 : rd + 1;
}
void BiTree::searchL(int i)//�ҳ���ڵ�
{
	if (i >= Array.length() || Array[i] == '0') return;
	if (((2 * i + 2) >= Array.length() || (Array[2 * i + 1] == '0'&&Array[2 * i + 2] == '0')) && (log(i + 1) / log(2) > ldeep))
	{
		targetLeft = i;
		ldeep = log(i + 1) / log(2);
	}
	searchL(2 * i + 1);
	searchL(2 * i + 2);
}
void BiTree::searchR(int i)//�ҳ��ҽڵ�
{
	if (i >= Array.length() || Array[i] == '0') return;

	if (((2 * i + 2) >= Array.length() || (Array[2 * i + 1] == '0'&&Array[2 * i + 2] == '0')) && (log(i + 1) / log(2) > rdeep)) {
		targetRight = i;
		rdeep = log(i + 1) / log(2);
	}
	searchR(2 * i + 1);
	searchR(2 * i + 2);
}
void BiTree::search()
{
	depth(0);
	Height(Root, 0);
	searchL(2 * target + 1);
	searchR(2 * target + 2);
	if (!target && !max) {
		cout << "0:" << endl;
		return;
	}
	cout << max << ":";
	if (targetLeft) cout << Array[targetLeft] << " ";
	else cout << Array[target] << " ";
	if (targetRight) cout << Array[targetRight];
	else cout << Array[target];
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
	if (c == '#')return NULL;
	T = new BiTreeNode();
	T->data = c;
	T->lc = CreateBiTree();
	T->rc = CreateBiTree();
	return T;
}
//���������
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
		T.ArrayStore();
		//T.pre();
		//cout << endl;
		T.search();
	}
}