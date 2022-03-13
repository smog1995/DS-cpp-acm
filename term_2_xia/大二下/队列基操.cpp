#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
	Node() {
		next = NULL;
	}
};
class Queue
{
public:
	Node *front, *rail;
		void InitQ()
		{
			front = rail = new Node();
		}

		void EnQueue(int x)
		{
			Node* s = new Node();
			s->data = x;
			rail->next = s;
			rail = s;
		}
		void DeQueue(int &x)
		{
			if (front == rail) return;
			Node* p = front->next;
			x = p->data;
			front->next = p->next;
			if (p == rail)
				rail = front;
			delete p;
		}
		bool isEmpty()
		{
			return rail == front;
		}
};
int MaxSize = 1000;
class SqQueue {
public:
	int Q[MaxSize];
	int front, rear;
	SqQueue() {
		front = rear = 0;
	}
	bool Enqueue(int x)
	{
		if ((rear + 1) % MaxSize == front) return false;
		Q[rear] = x;
		rear = (rear + 1) % MaxSize;
		return true;

	}
	bool Dequeue(int &x)
	{
		if (front == rear) return false;
		x = Q[front];
		front = (front + 1) % MaxSize;
		return true;
	}
};