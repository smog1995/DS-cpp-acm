#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

	string serialize(TreeNode* root) {
		if (root == NULL) return "";
		queue<TreeNode*> Q;
		Q.push(root);
		TreeNode* p;
		string s;
		s += "[";
		while (!Q.empty())
		{
			p = Q.front();
			Q.pop();
			if (p) {
				int x = p->val;
				s += to_string(p->val);
				s += ',';
				Q.push(p->left);
				Q.push(p->right);
			}
			else {
				s += "null,";
			}
		}
		s[s.length() - 1] = ']';//把最后一个逗号换成]
		return s;
	}
	TreeNode* bfs(int c[], int len)
	{
		TreeNode* root = new TreeNode(c[0]);
		int i = 1;
		queue<TreeNode*> Q;
		Q.push(root);
		while (!Q.empty() && i < len)
		{
			TreeNode* p = Q.front();
			Q.pop();
			if (c[i] != 999999)
			{
				p->left = new TreeNode(c[i++]);
				Q.push(p->left);
			}
			else i++;
			if (i >= len) break;
			if (c[i] != 999999)
			{
				p->right = new TreeNode(c[i++]);
				Q.push(p->right);
			}
			else i++;
		}
		return root;
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "") return NULL;
		int i = 1, len = 0;
		int *c = new int[data.length()];
		for (int j = 1; i <= data.length() - 1; i++)
		{
			if (data[i] != ',' && data[i] != ']') continue;
			else
			{
				if (data[j] == 'n') {
					c[len] = 999999;
				}
				else c[len] = stoi(data.substr(j, i - j));
				len++;
				j = i + 1;
			}
		}

		TreeNode* root = bfs(c, len);
		return root;
	}


};

int main()
{
	Codec C;
	TreeNode* T = C.deserialize("[-1,0,1]");
	cout << C.serialize(T);
}