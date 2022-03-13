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

	string res_str = "";

    void dfs1(TreeNode * rt)
    {
        if (rt == NULL)
        {
            res_str += "NULL,";
            return;
        }
        res_str += to_string(rt->val);
        res_str += ',';
        dfs1(rt->left);
        dfs1(rt->right);   
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        dfs1(root);
        return res_str;
    }


    queue<string> Q;

    TreeNode* dfs2()
    {
        if(Q.size() > 0)
        {
            string cur = Q.front();     Q.pop();
            if (cur == "NULL")
                return NULL;
            TreeNode* root = new TreeNode(stoi(cur));
            TreeNode* L = dfs2();
            TreeNode* R = dfs2();
            root->left = L;
            root->right = R;
            return root;
        }
        return NULL;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        int i = 0, j = 0;
        while(i <= data.size())
        {
            if(data[i] != ',')
                ++ i;
            else
            {
                string tmp = data.substr(j, i-j);
                Q.push(tmp);
                ++ i;
                j = i;
            }
        }
        if (j != i)
        {
            string tmp = data.substr(j, i-j);
            Q.push(tmp);
        }    
        return dfs2();         
    }


};

int main()
{
	Codec C;
	TreeNode* T = C.deserialize("[-1,0,1]");
	cout << C.serialize(T);
}
