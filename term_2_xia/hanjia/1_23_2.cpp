#include <iostream>
using namespace std;
struct Node
{
	int e;
	Node* prev;
	Node* next;
};
class ConnectedList
{
private:
	Node* motherNode;
public:
	ConnectedList()
	{
		motherNode = new Node();
		motherNode->data = -1;
		motherNode->prev = motherNode;
		motherNode->next = motherNode;
	}
};
