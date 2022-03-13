#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Node {
public:
	char c;
	Node** child;
	Node()
	{
		child = new Node*[26];
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
	}
	Node(char c)
	{
		this->c = c;
		child = new Node*[26];
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
	}
};
int search(Node* r)
{
	if (!r) return 1;
	int sum = 0,flag=0;
	for (int i = 0; i < 26; i++)
	{
		if (r->child[i] != NULL) {
			sum += search(r->child[i]);
			flag = 1;
		}
	}
	if (!flag) sum++;
	return sum;
}
int main()
{
	string s;
	Node *root = new Node();
	cin >> s;
	char x;
	while (true)
	{
		Node* p = root;
		if (root->child[s[0] - 'a'] == NULL) root->child[s[0] - 'a'] = new Node(s[0]);
		p = root->child[s[0] - 'a'];
		for (int i = 1; i < s.length(); i++)
		{
			int y = s[i] - 'a';
			if (p->child[y] == NULL) p->child[y] = new Node(s[i]);
			p = p->child[y];
		}
		x = getchar();
		if (x == '\n') break;
		cin >> s;
	}
	queue<Node*> q;
	Node* p = root;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		q.pop();

		for (int i = 0; i < 26; i++)
			if (p->child[i] != NULL)
			{
				q.push(p->child[i]);
				cout << p->child[i]->c;
			}
	}cout << endl;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		Node* p = root;
		int flag = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (!p) {
				break;
			}
			p = p->child[s[i] - 'a'];
		}
		if (!p) {
			cout << 0 << endl;
			break;
		}
		int count = search(p);
		
		cout << count << endl;
	}
}