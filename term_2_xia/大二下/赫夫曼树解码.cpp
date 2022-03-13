#include <iostream>
#include <string>
#include <cstring>
#define ok 1 
#define error -1
using namespace std;
const int MaxW = 9999;
class HuffNode {
public:
	int weight;
	int parent;
	int lc;
	int rc;
};
class HuffMan {
private:
	void MakeTree();
	void SelectMin(int pos, int *s1, int *s2);
public:
	int len;//结点数
	int lnum;//叶子数量
	HuffNode *huffTree;
	string *huffCode;
	void MakeTree(int n, int wt[]);
	void Coding();
	void Destroy();
	int Decode(const string codestr, char txtstr[]);
};
void HuffMan::MakeTree(int n, int wt[])
{
	int i;
	lnum = n;
	len = 2 * n - 1;
	huffTree = new HuffNode[2 * n];
	huffCode = new string[lnum + 1];//位置从1开始算

	for (i = 1; i <= n; i++)
		huffTree[i].weight = wt[i - 1];
	for (i = 1; i <= len; i++)
	{
		if (i > n) huffTree[i].weight = 0;
		huffTree[i].parent = 0;
		huffTree[i].lc = 0;
		huffTree[i].rc = 0;
	}
	MakeTree();
}
void HuffMan::SelectMin(int pos, int *s1, int *s2)
{
	int w1, w2, i;
	w1 = w2 = MaxW;
	*s1 = *s2 = 0;
	for (i = 1; i <= pos; i++)
	{
		if (huffTree[i].parent == 0)
		{
			if (huffTree[i].weight < w1)
			{
				*s2 = *s1;
				w2 = w1;
				*s1 = i;
				w1 = huffTree[i].weight;
			}
			else if (huffTree[i].weight < w2)
			{
				*s2 = i;
				w2 = huffTree[i].weight;
			}
		}
	}
}
void HuffMan::MakeTree()
{
	int i, s1, s2;
	for (i = lnum + 1; i <= len; i++)
	{
		SelectMin(i - 1, &s1, &s2);
		huffTree[s1].parent = huffTree[s2].parent = i;
		huffTree[i].lc = s1;
		huffTree[i].rc = s2;
		huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
	}
}
void HuffMan::Destroy()
{
	len = 0;
	lnum = 0;
	delete[] huffTree;
	delete[] huffCode;

}
void HuffMan::Coding()
{
	char* cd;
	int i, c, f, start;
	cd = new char[lnum];
	cd[lnum - 1] = '\0';
	for (i = 1; i <= lnum; ++i)
	{
		start = lnum - 1;//最坏情况就是该结点对应的编码串长度为所有结点数-1，
		//即此时树的结点全在同一边,高度最高时
		for (c = i, f = huffTree[i].parent; f; c = f, f = huffTree[f].parent)
		{
			if (huffTree[f].lc == c)cd[--start] = '0';
			else cd[--start] = '1';

		}
		huffCode[i].assign(&cd[start]);//从start下标开始
	}
	delete[]cd;
}
char wtc[800];
int HuffMan::Decode(const string codestr, char txtstr[])
{
	int i, k, c;
	char ch;
	c = len;
	k = 0;
	for (i = 0; i < codestr.length(); i++)
	{
		ch = codestr[i];
		if (ch == '0') c = huffTree[c].lc;
		else if (ch == '1') c = huffTree[c].rc;
		else return error;
		if (c <= lnum)
		{
			txtstr[k++] = wtc[c-1];
			c = len;
		}
		else {
			ch = '\0';
		}

	}
	if (ch == '\0') return error;
	else txtstr[k] = '\0';
	return ok;
}
int main()
{
	int t, n, i, j;
	int wt[800];

	HuffMan myHuff;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (j = 0; j < n; j++)
			cin >> wt[j];
		for (j = 0; j < n; j++)
			cin >> wtc[j];
		myHuff.MakeTree(n, wt);
		int num;
		cin >> num;
		while (num--)
		{
			string codestr;
			char *txtstr = new char[n];
			cin >> codestr;
			int x=myHuff.Decode(codestr,txtstr);
			if (x == -1) cout << "error" << endl;
			else cout << txtstr << endl;
			
		}
		
		
		myHuff.Destroy();
	}
}
