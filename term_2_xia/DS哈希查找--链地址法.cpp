#include <iostream>
using namespace std;
class Node
{
public:
	Node* next;
	int val;
	Node()
	{
		next = NULL;
	}
	Node(int x)
	{
		next = NULL;
		val = x;
	}
};
//±íÍ·²åÈë
int main()
{
	int n;
	cin >> n;
	Node **A = new Node*[11];
	for (int i = 0; i < 11; i++)
		A[i] = new Node();
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		int y = x % 11;
		Node* s = new Node(x);
		s->next = A[y]->next;
		A[y]->next = s;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		int y = x % 11;
		Node* p = A[y];
		int count = 0;
		while (p)
		{
			
			if (p->val == x)
			{
				cout << y << " " << count << endl;
				break;
			}
			p = p->next;
			count++;
		}
		if (!p)
		{
			Node* s = new Node(x);
			s->next = A[y]->next;
			A[y]->next = s;
			cout << "error" << endl;
		}
	}


}