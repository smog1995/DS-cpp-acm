
#include <iostream>
#include <queue>
using namespace std;

struct B_Node;

struct Node //ÿ�����нڵ��е�����������ʵ�֣������������С��Ԫ
{
	int v;// ÿ��λ�ö�Ӧ��Ȩֵ
	B_Node* ptr;// ÿ��λ�ö�Ӧ����һ��ڵ�
	Node* nxt;
	Node() { ptr = NULL; nxt = NULL; v = 0; }
	Node(int v_) { ptr = NULL; nxt = NULL; v = v_; };
	void add(int v_)
	{
		Node* box = nxt;
		nxt = new Node(v_);
		nxt->nxt = box;
	}
};

struct B_Node //B���Ľڵ�
{
	int size; //�ڵ�Ĵ�С
	B_Node* parent;//���ڵ�
	Node* list;//������ʵ�ֵ�����
	B_Node()
	{
		size = 1;
		parent = NULL;
		list = new Node();
		list->nxt = new Node(2147483647); //��Ϊԭ������ָ����һ���ָ���Ȩֵ�ǽ���ģ���̫�ô�������������һ������ֵ�������һ��Ȩֵ
										  //����Node�е� v �� ptr �Ĺ�ϵ�Ϳ������Ϊ��ptrָ��Ľڵ������е�Ȩֵ��С�� v
	}
	B_Node(Node* l, int s)//���ڲ�ֺ���ͬ�������½ڵ�
	{
		parent = NULL;
		list = new Node();
		size = s;
		list->nxt = l;
	}
	Node* find(int v_)//�ڽڵ����ҵ����һ��С�� v ��Ȩֵ��λ��
	{
		Node* cur = list;
		for (; cur->nxt != NULL && cur->nxt->v < v_; cur = cur->nxt);
		return cur;
	}
	~B_Node()
	{
		Node* cur = list;
		Node* net;
		while (cur != NULL)
		{
			net = cur->nxt;
			delete cur;
			cur = net;
		}
	}
};

struct B_Tree
{
	B_Node* root;
	int m;
	B_Tree() { root = NULL; m = 0; }
	B_Tree(int m_) { B_Tree(); m = m_; root = new B_Node(); }
	void Insert(int v) //����һ����ֵ
	{
		B_Node* cur = root;//�Ӹ��ڵ㿪ʼ��
		Node* pre=NULL;
		bool flag = 1;
		while (flag)//��ͣ����ֱ���ҵ�Ҷ�ӽڵ�
		{
			pre = cur->find(v);
			if (pre->nxt->ptr == NULL) flag = 0;//��һ��û�нڵ� ˵���ҵ���Ҷ�ӽڵ㣬��ʱpre���Ǵ������λ��
			else cur = pre->nxt->ptr;
		}
		pre->add(v);
		cur->size++;
		Update(cur);//ά��
	}
	void Update(B_Node* cur)
	{
		if (cur->size <= m) return;// �ò�Ϸ�
		int mid = (cur->size + 1) / 2; //ȷ��׼������ȥ�Ľڵ��λ��
		Node* p = cur->list;//��ʱp׼�������Ҫ����ȥ�Ľڵ��λ��
		for (int i = 1; i <= mid; i++)//�ҵ�Ҫ����ȥ��Ȩֵ
		{
			p = p->nxt;
		}
		int curv = p->v;//��¼Ȩֵ
		B_Node* now = new B_Node(p->nxt, cur->size - mid);//���Ұ벿������Ϊһ���½ڵ�
		cur->size = mid;//�޸���벿�ֵĴ�С
		p->nxt = NULL;
		if (cur->parent == NULL)//���û�и��ڵ� ���½�һ��
		{
			cur->parent = new B_Node();
			root = cur->parent;//���¸��ڵ�
			cur->parent->list->nxt->ptr = cur; //cur�ĸ��ڵ�ĵ�һ���ӽڵ���cur
		}
		now->parent = cur->parent; //���������ɵĽڵ���һ�µ�
		cur = cur->parent;//����cur�ĺ������˸ոյĸ��ڵ㣨Ϊ������һ��������
		p = cur->find(curv);//����p�ĺ�������׼������ȥ��Ȩֵ�������λ��
		p->add(curv);
		cur->size++;
		p->nxt->ptr = p->nxt->nxt->ptr; //����ȥ��Ȩֵָ���ѿ��������
		p->nxt->nxt->ptr = now;//����ȥ��Ȩֵ�����Ȩֵָ���ѿ��������
		Update(cur);//�ݹ����
	}
	void print()// bfs���
	{
		queue<B_Node*> q;
		q.push(root);
		while (!q.empty())
		{
			B_Node* cur = q.front();
			q.pop();
			if (cur == NULL) continue;
			Node* p = cur->list->nxt;
			for (int i = 1; i <= cur->size; i++)
			{
				if (i < cur->size)
				{
					if (i != 1) cout << ':';
					cout << p->v;
				}
				q.push(p->ptr);
				p = p->nxt;
			}
			cout << ' ';
		}
		cout << '\n';
	}
	void Search(int v) //����
	{
		B_Node* cur = root;
		while (1)
		{
			if (cur == NULL)// û�ҵ�
			{
				cout << "-1" << endl;
				return;
			}
			Node* p = cur->list->nxt;
			for (int i = 1; i <= cur->size; i++)//�����ڵ�
			{
				if (p->v == v)//����ҵ��˾�ԭ�����
				{
					p = cur->list->nxt;
					for (int j = 1; j < cur->size; j++)
					{
						if (j != 1) cout << ':';
						cout << p->v;
						p = p->nxt;
					}
					cout << ' ' << i << endl;
					return;//���ҳɹ����
				}
				if (p->v > v)//�������
				{
					cur = p->ptr;
					break;
				}
				p = p->nxt;
			}
		}
	}
	~B_Tree()
	{
		queue<B_Node*> q;
		q.push(root);
		while (!q.empty())
		{
			B_Node* cur = q.front();
			q.pop();
			if (cur == NULL) continue;
			Node* p = cur->list->nxt;
			for (int i = 1; i < cur->size; i++)
			{
				q.push(p->ptr);
				p = p->nxt;
			}
			delete cur;
		}
	}
};

int main()
{
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int m, n;
		cin >> m >> n;
		B_Tree bt = B_Tree(m);
		for (int i = 1; i <= n; i++)
		{
			int num;
			cin >> num;
			bt.Insert(num);
		}
		bt.print();
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			int num;
			cin >> num;
			bt.Search(num);
		}
	}
	return 0;
}