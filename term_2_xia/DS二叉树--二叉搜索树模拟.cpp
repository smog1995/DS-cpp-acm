#include <iostream>
using namespace std;
class TNode {
public:
	int val;

	TNode* left, *right;
	TNode(int v) :val(v) { left = right = NULL; }
};
class BST {
public:
	TNode* Root;
	int n;
	BST() { Root = NULL; n = 0; }
	TNode* Insert(TNode* &root, int data)
	{
		if (!root) { root = new TNode(data); n++; }
		else if (data < root->val) root->left=Insert(root->left, data);
		else if (data >= root->val) root->right=Insert(root->right, data);
		return root;
	}
	void pre(TNode* r)
	{
		if (!r) return;
		cout << r->val;

		if (n!=1)cout << " ";
		n--;
		pre(r->left);
		pre(r->right);
	}
	void in(TNode* r)
	{
		if (!r) return;
		in(r->left);
		cout << r->val;
		n--;
		if (n!=1)cout << " ";
		in(r->right);
	}
	void post(TNode* r)
	{
		if (!r) return;
		post(r->left);
		post(r->right);
		cout << r->val;
		n--;
		if (n!=1)cout << " ";
	}
	void build()
	{
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			int data;
			cin >> data;
			Root=Insert(Root, data);
		}
		pre(Root);
		cout << endl;
		in(Root);
		cout << endl;
		post(Root);
		cout << endl;

	}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		BST bst;
		bst.build();
		cout << endl;
	}
}