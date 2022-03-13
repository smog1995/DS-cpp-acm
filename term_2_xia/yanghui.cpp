#include <iostream>

using namespace std;
int MaxSize = 1000;
class SqQueue {
public:
	int *Q;
	int front, rear;
	SqQueue() {
		front = rear = 0;
	}
	~SqQueue(){
		delete[] Q;
		
	}
	void InitQ(int n){
		Q=new int[n];
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
	void GetHead(int &e)
	{
		//if(rear==front) e=-1;
		//else
		 e=Q[front];
		
	}
	bool isEmpty()
	{
		return front==rear;
	}
};
void yanghui(int n)
{
	SqQueue *Q=new SqQueue();
	for(int i=1;i<=n;i++)
	{
		cout<<" ";
	}
	cout<<1<<endl;
	Q->InitQ(n+2);
	Q->Enqueue(0);
	Q->Enqueue(1);
	Q->Enqueue(1);
	int k=1;
	int s=0,e=0;
	while(k<n)
	{
		for(int i=1;i<=n-k;i++)
		cout<<" ";//输出n-k个空格保持三角形 
		Q->Enqueue(0);
		do{
			Q->Dequeue(s);
			Q->GetHead(e);
			if(e!=0) cout<<e<<" ";
			else cout<<endl;
			Q->Enqueue(s+e);
		}while(e!=0);
		k++;
	}
	Q->Dequeue(e);
	while(!Q->isEmpty())
	{
		Q->Dequeue(e);
		cout<<e<<" ";
	}
}
int main(){
	int n;
	cin>>n;
	yanghui(n);
} 
