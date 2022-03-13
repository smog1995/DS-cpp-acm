#include <iostream>
using namespace std;
class TNode
{
public:
	int data;
	TNode* lc, *rc;
	TNode() {
		lc = rc = NULL;
	}
	TNode(int x)
	{
		data = x;
		lc = rc = NULL;
	}
};
class Tree
{
private:
	TNode* root;
	int count;
	public:
		bool search(TNode* &p, TNode* f, int key,TNode* r)
		{
			if (!r) { p = f; return false; }
			if (r->data > key)
				return search(p, r, key,r->lc);
			else if (r->data < key)
				return search(p, r, key,r->rc);
			else return true;
		}
		int search(TNode* r, int key)
		{
			if (!r) return -1;
			if (r->data == key) return 1;
			int c = 0;
			if (r->data > key)
				c = search(r->lc, key);
			if (c == -1) return -1;
			else if (r->data < key)
				c = search(r->rc, key);
			if (c == -1) return -1;
			return c+1;
		}
		void DeleteN(int x)
		{
			TNode* p=root,*f=NULL;
			while (p)
			{
				if (p->data==x) break;
				f = p;
				 if (p->data > x) p = p->lc;
				else if (p->data < x) p = p->rc;
				
				
			}
			if (!p) return;
			if (p->lc&&p->rc)
			{
				TNode* s=p->lc, *q = p;
				while (s->rc) {
					q = s;
					s = s->rc;
				}
				p->data = s->data;
				if (q == p)
					q->lc=s->lc;
				else q->rc=s->lc;
				delete s;
			}
			else if (p->lc)
			{
				if (f->lc == p) f->lc = p->lc;
				else f->rc = p->lc;
				delete p;
			}
			else if (p->rc)
			{
				if (f->lc == p) f->lc = p->rc;
				else f->rc = p->rc;
				delete p;
			}
			else if(!p->lc&&!p->rc)
			{
				if (f->lc == p) f->lc = NULL;
				else f->rc = NULL;
				delete p;
			}
		}
		void InsertN(int x)
		{
			TNode* p ;
			if (!search(p, NULL, x,root))
			{
				TNode* s = new TNode(x);
				if (!p) root = s;
				
				else if (p->data > x) p->lc = s;
				else p->rc = s;
			}

		}
		void Inorder(TNode* p)
		{
			if (!p) return;
			Inorder(p->lc);
			cout << p->data << " ";
			Inorder(p->rc);
		}
		void CreateT()
		{
			root = NULL;
			int n;
			cin >> n;
			int x;
			for (int i = 0; i < n; i++)
			{

				cin >> x;
				InsertN(x);
			}
			Inorder(root);
			cout << endl;
			/*
			//进行查找操作
			int c;
			cin >> c;
			while (c--)
			{
				cin >> x;
				count =search(root,x);
				cout <<count<< endl;
			}
			*/
			//进行删除操作
			int c;
			cin >> c;
			while (c--)
			{
				cin >> x;
				DeleteN(x);
				Inorder(root);
				cout << endl;
			}
		}
};
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Tree T;
		T.CreateT();
	}
}