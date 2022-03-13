#include <iostream>
#include <stdio.h>
using namespace std;
class Node
{
public:
	int e;
	Node* next;
	Node() {
		next = NULL;
	}
};
Node* createL(int n)
{
	Node* L = new Node();
	Node* r = L;
	r->e = 1;
	for (int i = 2; i <= n; i++)
	{
		Node* s = new Node();
		s->e = i;
		r->next = s;
		r = s;
	}
	r->next = L;
	return L;
}
int main()
{

	
		int n, s, k;
		while ((scanf("%d%d%d", &n , &k ,&s))!=EOF)
		{
			Node* L = createL(n);
			for (int i = 1; i < s; i++)
				L = L->next;

			while (L != NULL)
			{

				for (int i = 1; i < k - 1; i++)
					L = L->next;
				if (L->next != L)
				{
					Node* s = L->next;
					cout << s->e << " ";
					L->next = s->next;
					delete s;
				}
				else {
					cout << L->e << " "<<endl;
					delete L;
					L = NULL;
				}
				if (L)L = L->next;
			}
		}
	
}

