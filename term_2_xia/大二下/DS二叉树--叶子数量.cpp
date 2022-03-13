#include <iostream>
#include <queue>

using namespace std;


class TNode {
public:
	char data;
	TNode* lc, *rc;
	TNode() {
		lc = rc = NULL;
		data = '0';
	}
};
void createTree(TNode* T)
{
	char x;
	cin >> x;
	if (x == '\n') return;
	if (x == '0') {
		T = NULL;//这里为什么没变化
	}
	else {
		if (!T)
			T = new TNode();
		T->data = x;
		T->lc = new TNode();
		createTree(T->lc);
		T->rc = new TNode();
		createTree(T->rc);
	}

}

int num = 0;

void searchc(TNode* T)
{
	if (T->lc->data == '0' && T->rc->data == '0')
	{
		num++;
	}
}
void preorderc(TNode* T)
{
	if (!T || T->data == '0') return;
	searchc(T);

	preorderc(T->lc);
	preorderc(T->rc);
}


int main() {
	int t;
	cin >> t;
	while (t--)
	{
		TNode* T = new TNode();
		createTree(T);
		preorderc(T);
		cout << num << endl;
		num = 0;
	}
}
