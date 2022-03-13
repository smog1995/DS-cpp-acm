#include <iostream>
using namespace std;
class Node {
public:
	Node* next;
	int data;
	Node() {
		next = NULL;
	}
};
int main()
{
	int n;
	cin >> n;
	int len = n;
	Node* head = new Node();
	Node* p = head;
	for (int i = 0; i < n; i++)
	{
		Node* x = new Node();
		cin >> x->data;
		p->next = x;
		p = p->next;
	}
	p = head->next;
	while (p)
	{
		//cout << p->data << " ";
		Node* q = p;
		while (q)
		{
			if (q->next&&p->data == q->next->data)
			{
				//cout<<p->data<<endl;
				Node* x = q->next;
				q->next = x->next;
				delete x;
				len--;
			}
			else q = q->next;
		}
		p = p->next;
	}
	cout << len << ": ";
	p = head->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}
