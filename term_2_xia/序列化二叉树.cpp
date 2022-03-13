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

	// Encodes a tree to a single string.
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
				int flag = 0;
				stack<char> s1;
				if (x < 0)
				{
					flag = 1;
					x = -x;
				}
				if (!x) s1.push('0');
				else
				while (x)
				{
					s1.push(x % 10 + '0');
					x /= 10;
				}
				if (flag == 1) s1.push('-');
				while (!s1.empty())
				{
					s += s1.top();
					s1.pop();
				}
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
			if (c[i])
			{
				p->left = new TreeNode(c[i++]);
				Q.push(p->left);
			}
			else i++;
			if (i >= len) break;
			if (c[i])
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
		int i = 1, i1 = 0;
		int *c = new int[data.length()];
		for (; data[i] != ']'; i++)
		{
			if (data[i] == ',') continue;
			if (data[i] == 'n') {
				c[i1++] = 0;
				i += 3;
			}
			if ((data[i] >= '0'&&data[i] <= '9') || data[i] == '-') {
				int x = 0, flag = 0;
				if (data[i] == '-')
				{
					flag = 1; i++;
				}
				for (; data[i] >= '0'&&data[i] <= '9'; i++)
				{
					x = x * 10 + (data[i] - '0');
				}i--;

				if (flag == 1) x = -x;
				cout << x << endl;
				c[i1++] = x;

			}
		}
		for (int i = 0; i < i1; i++)
			cout << c[i] << " ";
		cout << endl;
		TreeNode* root = bfs(c, i1);
		return root;
	}
};

int main()
{
	Codec C;
	TreeNode* T = C.deserialize("[-1,0,1]");
	cout << C.serialize(T);
}