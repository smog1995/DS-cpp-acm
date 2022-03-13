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
//±íÎ²²åÈë
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
		Node* p = A[y];
		while (p->next) p = p->next;
		Node* s = new Node(x);
		p->next=s;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		int y = x % 11;
		Node* p = A[y],*r=p;
		int count = 0;
		while (p)
		{

			if (p->val == x)
			{
				cout << y << " " << count << endl;
				break;
			}
			r = p;
			p = p->next;
			
			count++;
		}
		if (!p)
		{
			Node* s = new Node(x);
			r->next = s;
			cout << "error" << endl;
		}
	}


}