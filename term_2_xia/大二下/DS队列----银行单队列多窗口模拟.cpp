#include <iostream>
#include <queue>
using namespace std;

class QElem {
public:
	int arrivalt;
	int duration;
	int waittime;
	QElem(){}
	QElem(int a ,int d):arrivalt(a),duration(d),waittime(0){}
};
class Queue {
public:
	int head, rail;
	int service;
	QElem* Q;
	int size;
	Queue() { head = rail = 0; size = 0; service = 0; }
	~Queue() { delete[] Q; }
	void InitQ(int n)
	{
		Q = new QElem[n];
		size = n;
	}
	void push(QElem e)
	{
		Q[rail] = e;
		rail = (rail + 1) % size;
	}
	void pop()
	{
		head = (head + 1) % size;
	}
	bool empty()
	{
		return head==rail;
	}
	QElem front()
	{
		return Q[head];
	}
	void setWaittime(int t)
	{
		Q[head].waittime = t;
	}
	int Size() {
		return (head - rail + size) % size;
	}
};
int main()
{
	int k;
	int n; cin >> n; 
	int cnum = n;
	queue<QElem> q;
	int arrival, duration;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arrival >>duration;
		QElem elem(arrival, duration);
		q.push(elem);
	}
	cin >> k;
	Queue *Q = new Queue[k];
	for (int i = 0; i < k; i++)
		Q[i].InitQ(n);
	int count = 0;
	double average = 0;
	int interval = 0;
	int maxwait = 0;
	while(!q.empty()||cnum>0)
	{
		
		for (int i = 0; i < k; i++)
		{
			if (!Q[i].empty())
			{
				QElem qe1 = Q[i].front();
				if (qe1.waittime+qe1.duration + qe1.arrivalt == count) {
					Q[i].pop(); cnum--; Q[i].service++;
					if (!Q[i].empty())
					{
						QElem qe2 = Q[i].front();
						int x = count - qe2.arrivalt;
						Q[i].setWaittime(x);
						average += qe2.waittime;
						if (qe2.waittime > maxwait) maxwait = x;
					}
				}
			}
		}
		if (!q.empty())
		{
			QElem e = q.front();
			while ((e.arrivalt + e.waittime == count)&&!q.empty())
			{
				int min = 0;
				for (int i = 1; i < k; i++)
					if (Q[i].Size() < Q[min].Size()) min = i;
				Q[min].push(e); q.pop();
				if(!q.empty())e = q.front();
			}
		}
		count++;
	}
	average /= n;
	cout << average << " " << maxwait << " " << count << endl;
	for (int i = 0; i < k; i++)
		cout << Q[i].service << " ";
	cout << endl;
}

