#include <iostream>
using namespace std;
class TNode {
public:
	int data;
	TNode* lc, *rc;
	TNode() {
		lc = rc = NULL;
	}

};
class Tree {
public:
	TNode* root;
	int Search(TNode* r,int key)
	{
		if (!T) return -1;
		if (key > r->data) Search(r->rc, key);
		else if (key < r->data)Search(r->lc, key);
		else return 1;
	}
	bool Insert(Tnode* r, int k)
	{
		if (!r) {
			r = new TNode();
			r->data = k;
			return treu;
		}
		else if (r->data > k)
			Insert(r->lc, k);
		else if (r->data < k)
			Insert(r->rc, k);
		
	}
	bool DeleteT(TNode* r,int k,TNode* f)
	{
		TNode* p = r;
		while (p)
		{
			if (p->data == k)
				break;
			f = p;
			if (p->data > k)
				p = p->lc;
			else p = p->rc;
		}
		if (!p)return;
		if (p->lc&&p->rc)
		{
			TNode* x=p->lc;
			TNode* xf=p;
			while (x->rc)
			{
				xf = x;
				x = x->rc;
			}
			p->data = x->data;
			if (xf == p)//p��������������ǰ��
				p->lc = x->lc;//������������������Ҳ����Ϊ�գ�����������
			else xf->rc = x->lc;//��ǰ�����������ŵ��丸�ڵ��������
		}
		else if (p->lc)
		{
			xf->lc = p->lc;
		}
	}
};