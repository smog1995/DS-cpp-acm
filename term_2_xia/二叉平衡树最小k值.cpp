#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class TNode {
public:
	int data;
	TNode* left, *right;
	int height;
	TNode(int d) :data(d), left(NULL), right(NULL) { height = 0; }

};
int max(int x, int y)
{
	return x > y ? x : y;
}
class AVLTree {
public:
	TNode* Root;
	int getHeight(TNode* root)
	{
		return !root ? 0 : root->height;
	}
	TNode* LL(TNode* k1)
	{
		TNode* k2 = k1->left;
		k1->left = k2->right;
		k2->right = k1;
		k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
		k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
		return k2;
	}
	TNode* RR(TNode* k2)
	{
		TNode* k1 = k2->right;
		k2->right = k1->left;
		k1->left = k2;
		k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
		k1->height = max(getHeight(k1->left), getHeight(k2->right)) + 1;

		return k1;
	}
	TNode* LR(TNode* k3)
	{
		k3->left = RR(k3->left);
		return LL(k3);
	}
	TNode* RL(TNode* k4)
	{
		k4->right = LL(k4->right);
		return RR(k4);
	}
	TNode* insertAVL(TNode* &root, int data)
	{
		if (!root)  root = new TNode(data);
		else {
			if (data < root->data)
			{
				root->left = insertAVL(root->left, data);
				if (getHeight(root->left) - getHeight(root->right) == 2)
				{
					if (data < root->left->data)
						root = LL(root);
					else
						root = LR(root);
				}

			}
			else if (data > root->data)
			{
				root->right = insertAVL(root->right, data);
				if (getHeight(root->right) - getHeight(root->left) == 2)
				{
					if (data > root->right->data)
						root = RR(root);
					else root = RL(root);
				}
			}
			//else cout << "fail" << endl;
			//上面没有调整过的结点也需要进行高度更新


		}
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
		return root;
	}
	AVLTree() { Root = NULL; }
	void build()
	{
		int n;
		cin >> n;
		int op,data;
		while (n--)
		{
			cin >> op >> data;
			if (op == 1) insertAVL(Root, data);
			else {
				vector<int> v;
				inorder(Root, v);
				
				}
			}
		}
	}

	void inorder(TNode* root,vector<int> &v)
	{
		if (!root) return;
		inorder(root->left,v);
		v.push_back(root->data);

		inorder(root->right,v);
	}
};
int main()
{

		AVLTree avl;
		avl.build();
}