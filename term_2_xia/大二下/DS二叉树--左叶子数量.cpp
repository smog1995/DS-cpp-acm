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
/*
queue<TNode*> Q;
void createTree(TNode* T,int &n)
{
	int x;
	cin >> x; n--;
	T->data = x;
	Q.push(T);
	TNode* p;
	while (T && !Q.empty()&&n)
	{
		p = Q.front();
		Q.pop();
		cin >> x; n--;
		if (x ) {
			T->lc = new TNode();
			T->lc->data = x;
			Q.push(T->lc);
		}
		else if (x == 0) T->lc = NULL;

		if (!n) break;
		cin >> x; n--;
		if (x) {
			T->rc = new TNode();
			T->rc->data = x;
			Q.push(T->rc);
		}
		else if (x == 0) T->rc = NULL;

	}
}*/
queue<char> Q1;
int num = 0;
void searchp(TNode* T, char data)
{
	if (T->lc->data == data)
	{
		num++;
	}
}
void preorderp(TNode* T, char data)
{
	if (!T || T->data == '0') return;
	searchp(T, data);
	preorderp(T->lc, data);
	preorderp(T->rc, data);
}
void searchc(TNode* T)
{
	if (T->lc->data == '0' && T->rc->data == '0')
	{
		//cout << T->data << " ";
		Q1.push(T->data);
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
		while (!Q1.empty())
		{
			preorderp(T, Q1.front());
			Q1.pop();
		}
		
		cout <<num<< endl;
		num = 0;
	}
}
